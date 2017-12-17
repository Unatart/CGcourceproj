#include "model.h"
#include <ctime>

Model::Model(int L, int H, int W) {
    // W - x
    // H - y
    // L - z
    srand(time(0));
    model_size.H = H;
    model_size.L = L;
    model_size.W = W;

    Point form_point;
    Polygon polygon;

//    first polygon
    polygon.points.push_back(form_point);

    form_point.set_x(W);
    polygon.points.push_back(form_point);

    form_point.set_y(H);
    polygon.points.push_back(form_point);

    form_point.set_x(0);
    polygon.points.push_back(form_point);
    polygons.push_back(polygon);

//    second polygon
    for (Point& point : polygon.points) {
        point.set_z(L);
    }
	polygons.push_back(polygon);


//    side polygons
    Polygon first_pol(polygons[0]);
    Polygon second_pol(polygons[1]);

    for (unsigned i = 0; i < 4; ++i) {
        polygon.points.clear();
        unsigned first_index = (i != 0) ? (i - 1) : 3;

        polygon.points.push_back(first_pol.points[first_index]);
        polygon.points.push_back(first_pol.points[i]);
        polygon.points.push_back(second_pol.points[i]);
        polygon.points.push_back(second_pol.points[first_index]);

		polygons.push_back(polygon);
    }

    for (Polygon& polygon : polygons) {
        polygon.setup_flatness();
    }

    center.set(W/2, H/2, L/2);
}

Model& Model::operator =(const Model &other) {
    if (this == &other) {
        return *this;
    }

    this->model_size.H = other.model_size.H;
    this->model_size.L = other.model_size.L;
    this->model_size.W = other.model_size.W;

    this->center = other.center;
    this->polygons = other.polygons;

    return *this;
}

void Model::setColor(QColor color) {
    for (Polygon &p: polygons) {
		Point view(0, 0, -1);

		double angle = view.angle(p.flatness.normal());
		if (angle > M_PI_2) {
			angle = M_PI - angle;
		}

		double measure = cos(angle);
        if (color == Qt::red) {
			p.polygon_color =  QColor(155 + 100 * measure, 0, 0);
        }
        if (color == Qt::green) {
			p.polygon_color = QColor(0, 155 + 100 * measure, 0);\
        }
    }
}

void Model::printModel() {
    for(Polygon& pol : polygons) {
        for (Point& point : pol.points) {
            point.print_point();
        }
        pol.setup_flatness();
    }
}

bool Model::insideShip(const Ship& plane) const {
    for(const Polygon& plane_pol : plane.polygons) {
        for(const Polygon& pol : polygons) {
            for (const Point& point : pol.points) {
                if (plane_pol.infront(plane.get_center()) != plane_pol.infront(point)) {
                    return false;
                }
            }
        }
    }
    return true;
}
