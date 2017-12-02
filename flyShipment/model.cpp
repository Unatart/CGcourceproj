#include "model.h"

Model::Model(int L, int H, int W) {
    // W - x
    // H - y
    // L - z
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
    polygon.setup_flatness();

    polygons.push_back(polygon);

//    second polygon
    for (Point& point : polygon.points) {
        point.set_z(L);
    }
    polygon.setup_flatness();
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

        polygon.setup_flatness();
        polygons.push_back(polygon);
    }

    center.set(W/2, H/2, L/2);
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
