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

//    if (color == Qt::red) {
//        auto rp = red_color_polygons.begin();
//        auto p = polygons.begin();

//            while (rp != red_color_polygons.end() && p != polygons.end()) {
    //        if (!red_color_polygons.empty()) {
//                p.polygon_color = rp.polygon_color;
//            }
//        }
//        else {
//            while (rp != red_color_polygons.end() && p != polygons.end()) {
//                rp.polygon_color = QColor(255, rand()%(200 - 100 + 1) + 100, rand()%(200 - 100 + 1) + 100);
//                p.polygon_color = rp.polygon_color;
//            } 
//        }
//    }

//    if (color == Qt::green) {
//        auto gp = green_color_polygons.begin();
//        auto p = polygons.begin();

//        if (!green_color_polygons.empty()) {
//            while (gp != green_color_polygons.end() && p != polygons.end()) {
//                p.polygon_color = gp.polygon_color;
//            }
//        }
//        else {
//            while (gp != green_color_polygons.end() && p != polygons.end()) {
//                gp.polygon_color = QColor(255, rand()%(200 - 100 + 1) + 100, rand()%(200 - 100 + 1) + 100);
//                p.polygon_color = gp.polygon_color;
//            }
//        }
//    }
}

void Model::move(double dx, double dy, double dz) {
    Point change(dx, dy, dz);

    for(Polygon& pol : polygons) {
        for (Point& point : pol.points) {
            point += change;
        }
        pol.setup_flatness();
    }

    center += change;
}

void Model::rotate(double dxy, double dyz, double dzx) {

    for(Polygon& pol : polygons) {
        for (Point& point : pol.points) {
            if (dxy != 0) {
                point.rotate_dxy(dxy, center);
            }
            if (dyz != 0) {
                point.rotate_dyz(dyz, center);
            }
            if (dzx != 0) {
                point.rotate_dzx(dzx, center);
            }
        }
        pol.setup_flatness();
    }
}

void Model::resize(double k) {
    for(Polygon& pol : polygons) {
        for (Point& point : pol.points) {
            point = center + (point - center) * k;
        }
        pol.setup_flatness();
    }
}

void Model::rotate(double dxy, double dyz, double dzx, const Point& center) {
    for(Polygon& pol : polygons) {
        for (Point& point : pol.points) {
            if (dxy != 0) {
                point.rotate_dxy(dxy, center);
            }
            if (dyz != 0) {
                point.rotate_dyz(dyz, center);
            }
            if (dzx != 0) {
                point.rotate_dzx(dzx, center);
            }
        }
        pol.setup_flatness();
    }

    if (dxy != 0) {
        this->center.rotate_dxy(dxy, center);
    }
    if (dyz != 0) {
        this->center.rotate_dyz(dyz, center);
    }
    if (dzx != 0) {
        this->center.rotate_dzx(dzx, center);
    }
}

void Model::resize(double k, const Point& center) {
    for(Polygon& pol : polygons) {
        for (Point& point : pol.points) {
            point = center + (point - center) * k;
        }
        pol.setup_flatness();
    }

    this->center = center + (this->center - center) * k;
}

void Model::printModel() {
    for(Polygon& pol : polygons) {
        for (Point& point : pol.points) {
            point.print_point();
        }
        pol.setup_flatness();
    }
}

bool Model::insideShip(Ship& plane) {
    bool inside = true;

    for(Polygon& plane_pol : plane.polygons) {
        for(Polygon& pol : polygons) {
            for (Point& point : pol.points) {
                if ((plane_pol.infront(plane.get_center()) != plane_pol.infront(point)) ||
                            (plane_pol.behind(plane.get_center()) != plane_pol.behind(point))) {
                    inside = false;
                    break;
                }
            }
        }
    }

    return inside;
}
