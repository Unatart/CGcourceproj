#include "ship.h"

void Ship::createShip(int L, int H, int Wt, int Wb) {
    // W - x
    // H - y
    // L - z
    ship_size.H = H;
    ship_size.L = L;
    ship_size.Wt = Wt;
    ship_size.Wb = Wb;

    Point form_point(0, 0, 0);

    Polygon polygon;
    polygon.points.push_back(form_point);

    form_point.set_x(Wb);
    polygon.points.push_back(form_point);

    form_point.set_x(Wb - (Wb - Wt)/2);
    form_point.set_y(H);
    polygon.points.push_back(form_point);

    form_point.set_x((Wb - Wt)/2);
    polygon.points.push_back(form_point);

    polygon.polygon_color = Qt::gray;
    polygons.push_back(polygon);

//    second polygon
    for (Point& point : polygon.points) {
        point.set_z(L);
    }
    polygon.polygon_color = Qt::black;
    polygons.push_back(polygon);


//    side polygons
    Polygon first_poly = polygons[0];
    Polygon second_poly = polygons[1];

    for (unsigned i = 0; i < 4; ++i) {
        polygon.points.clear();
        unsigned first_index = (i != 0) ? (i - 1) : 3;

        polygon.points.push_back(first_poly.points[first_index]);
        polygon.points.push_back(first_poly.points[i]);
        polygon.points.push_back(second_poly.points[i]);
        polygon.points.push_back(second_poly.points[first_index]);

        polygon.polygon_color = Qt::gray;
        polygons.push_back(polygon);
    }

    for (Polygon& polygon : polygons) {
        polygon.setup_flatness();
    }

    center.set(Wb/2, H/2, L/2);
    front.set(Wb/2, H/2, L);

    front_vector.set(center.get_x() - front.get_x(), center.get_y() - front.get_y(), center.get_z() - front.get_z());
}

Point Ship::get_center() {
    return center;
}

void Ship::move(double dx, double dy, double dz) {
    Point change(dx, dy, dz);

    for(Polygon& pol : polygons) {
        for (Point& point : pol.points) {
            point += change;
        }
        pol.setup_flatness();
    }

    center += change;
    front += change;
    front_vector.set(center.get_x() - front.get_x(), center.get_y() - front.get_y(), center.get_z() - front.get_z());
}

void Ship::rotate(double dxy, double dyz, double dzx) {
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

void Ship::resize(double k) {
    for(Polygon& pol : polygons) {
        for (Point& point : pol.points) {
            point = center + (point - center) * k;
        }
        pol.setup_flatness();
    }
}

void Ship::rotate(double dxy, double dyz, double dzx, const Point& center) {
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

    if (dxy != 0) {
        this->front.rotate_dxy(dxy, center);
    }
    if (dyz != 0) {
        this->front.rotate_dyz(dyz, center);
    }
    if (dzx != 0) {
        this->front.rotate_dzx(dzx, center);
    }

    front_vector.set(this->center.get_x() - front.get_x(), this->center.get_y() - front.get_y(), this->center.get_z() - front.get_z());
}

void Ship::resize(double k, const Point& center) {
    for(Polygon& pol : polygons) {
        for (Point& point : pol.points) {
            point = center + (point - center) * k;
        }
        pol.setup_flatness();
    }

    this->center = center + (this->center - center) * k;
    this->front = center + (this->front - center) * k;

    front_vector.set(this->center.get_x() - front.get_x(), this->center.get_y() - front.get_y(), this->center.get_z() - front.get_z());
}
