#include "model.h"

Model::createModel(int L, int H, int W) {
    // W - x
    // H - y
    // L - z
    model_size.H = H;
    model_size.L = L;
    model_size.W = W;

    Point init_point;
    init_point.set(0,0,0);

    Point form_point;
    form_point.set(0,0,0);

    // for x/y axe
    Point xy_points_array[4];
    ModelPolygon polygon;

    xy_points_array[0] = init_point;
    form_point.set_x(W);
    xy_points_array[1] = form_point;
    form_point.set_x(0);
    form_point.set_y(H);
    xy_points_array[2] = form_point;
    form_point.set_x(W);
    xy_points_array[3] = form_point;
    //polygon.mpolygon.createpolygon.mpolygon(xy_points_array);
    Edge edge;

    edge.begin = xy_points_array[0];
    edge.end = xy_points_array[2];
    polygon.mpolygon.push_back(edge);

    edge.begin = xy_points_array[2];
    edge.end = xy_points_array[3];
    polygon.mpolygon.push_back(edge);

    edge.begin = xy_points_array[3];
    edge.end = xy_points_array[1];
    polygon.mpolygon.push_back(edge);

    edge.begin = xy_points_array[1];
    edge.end = xy_points_array[0];
    polygon.mpolygon.push_back(edge);

    model.push_back(polygon);
    for (int i = 0; i < 4; i++) {
        xy_points_array[i].set_z(L);
    }

    polygon.mpolygon.clear();

    edge.begin = xy_points_array[0];
    edge.end = xy_points_array[2];
    polygon.mpolygon.push_back(edge);

    edge.begin = xy_points_array[2];
    edge.end = xy_points_array[3];
    polygon.mpolygon.push_back(edge);

    edge.begin = xy_points_array[3];
    edge.end = xy_points_array[1];
    polygon.mpolygon.push_back(edge);

    edge.begin = xy_points_array[1];
    edge.end = xy_points_array[0];
    polygon.mpolygon.push_back(edge);
    model.push_back(polygon);

    polygon.mpolygon.clear();

    //for x/z axe
    Point xz_points_array[4];
    form_point.set(0,0,0);

    xz_points_array[0] = init_point;
    form_point.set_x(W);
    xz_points_array[1] = form_point;
    form_point.set_x(0);
    form_point.set_z(L);
    xz_points_array[2] = form_point;
    form_point.set_x(W);
    xz_points_array[3] = form_point;
    edge.begin = xz_points_array[0];
    edge.end = xz_points_array[2];
    polygon.mpolygon.push_back(edge);

    edge.begin = xz_points_array[2];
    edge.end = xz_points_array[3];
    polygon.mpolygon.push_back(edge);

    edge.begin = xz_points_array[3];
    edge.end = xz_points_array[1];
    polygon.mpolygon.push_back(edge);

    edge.begin = xz_points_array[1];
    edge.end = xz_points_array[0];
    polygon.mpolygon.push_back(edge);
    model.push_back(polygon);

    polygon.mpolygon.clear();

    for (int i = 0; i < 4; i++) {
        xz_points_array[i].set_y(H);
    }

    edge.begin = xz_points_array[0];
    edge.end = xz_points_array[2];
    polygon.mpolygon.push_back(edge);

    edge.begin = xz_points_array[2];
    edge.end = xz_points_array[3];
    polygon.mpolygon.push_back(edge);

    edge.begin = xz_points_array[3];
    edge.end = xz_points_array[1];
    polygon.mpolygon.push_back(edge);

    edge.begin = xz_points_array[1];
    edge.end = xz_points_array[0];
    polygon.mpolygon.push_back(edge);
    model.push_back(polygon);

    polygon.mpolygon.clear();

    //yz axe

    Point yz_points_array[4];
    form_point.set(0,0,0);

    yz_points_array[0] = init_point;
    form_point.set_y(H);
    yz_points_array[1] = form_point;
    form_point.set_y(0);
    form_point.set_z(L);
    yz_points_array[2] = form_point;
    form_point.set_y(H);
    yz_points_array[3] = form_point;
    edge.begin = yz_points_array[0];
    edge.end = yz_points_array[2];
    polygon.mpolygon.push_back(edge);

    edge.begin = yz_points_array[2];
    edge.end = yz_points_array[3];
    polygon.mpolygon.push_back(edge);

    edge.begin = yz_points_array[3];
    edge.end = yz_points_array[1];
    polygon.mpolygon.push_back(edge);

    edge.begin = yz_points_array[1];
    edge.end = yz_points_array[0];
    polygon.mpolygon.push_back(edge);
    model.push_back(polygon);

    polygon.mpolygon.clear();
    for (int i = 0; i < 4; i++) {
        yz_points_array[i].set_x(W);
    }

    edge.begin = yz_points_array[0];
    edge.end = yz_points_array[2];
    polygon.mpolygon.push_back(edge);

    edge.begin = yz_points_array[2];
    edge.end = yz_points_array[3];
    polygon.mpolygon.push_back(edge);

    edge.begin = yz_points_array[3];
    edge.end = yz_points_array[1];
    polygon.mpolygon.push_back(edge);

    edge.begin = yz_points_array[1];
    edge.end = yz_points_array[0];
    polygon.mpolygon.push_back(edge);
    model.push_back(polygon);

    polygon.mpolygon.clear();

    Point somepoint;
    somepoint.set(W/2, H/2, L/2);
    center = somepoint;

}

void Model::move(double dx, double dy, double dz) {
    Point change(dx, dy, dz);

    for(ModelPolygon& pol : model) {
        for (Edge& edge : pol.mpolygon) {
            edge.begin += change;
            //edge.end += change;
        }
    }

    center += change;
}

void Model::rotate(double dxy, double dyz, double dzx) {

    for(ModelPolygon& pol : model) {
        for (Edge& edge : pol.mpolygon) {
            if (dxy != 0) {
                edge.begin.rotate_dxy(dxy, center);
                //edge.end.rotate_dxy(dxy, center);
            }
            if (dyz != 0) {
                edge.begin.rotate_dyz(dyz, center);
                //edge.end.rotate_dyz(dyz, center);
            }
            if (dzx != 0) {
                edge.begin.rotate_dzx(dzx, center);
               // edge.end.rotate_dzx(dzx, center);
            }
        }
    }

}

void Model::resize(double k) {
    for(ModelPolygon& pol : model) {
        for (Edge& edge : pol.mpolygon) {
            edge.begin += center + (edge.begin - center) * k;
           // edge.end += center + (edge.end - center) * k;
        }
    }
}

void Model::rotate(double dxy, double dyz, double dzx, const Point& center) {
    for(ModelPolygon& pol : model) {
        for (Edge& edge : pol.mpolygon) {
            if (dxy != 0) {
                edge.begin.rotate_dxy(dxy, center);
               //edge.end.rotate_dxy(dxy, center);
            }
            if (dyz != 0) {
                edge.begin.rotate_dyz(dyz, center);
               // edge.end.rotate_dyz(dyz, center);
            }
            if (dzx != 0) {
                edge.begin.rotate_dzx(dzx, center);
                //edge.end.rotate_dzx(dzx, center);
            }
        }
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
    for(ModelPolygon& pol : model) {
        for (Edge& edge : pol.mpolygon) {
            edge.begin = center + (edge.begin - center) * k;
           // edge.end = center + (edge.end - center) * k;
        }
    }

    this->center = center + (this->center - center) * k;

}

void Model::printModel() {
    for(ModelPolygon& pol : model) {
        for (Edge& edge : pol.mpolygon) {
            edge.begin.print_point();
          //  edge.end.print_point();
        }
    }
}
