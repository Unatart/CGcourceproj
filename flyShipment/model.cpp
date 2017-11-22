#include "model.h"

void Model::createModel(int L, int H, int W) {
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
    polygon.createPolygon(xy_points_array);
    model.push_back(polygon);
    for (int i = 0; i < 4; i++) {
        xy_points_array[i].print_point();
        xy_points_array[i].set_z(L);
        std::cout << std::endl;
    }
    for (int i = 0; i < 4; i++) {
        xy_points_array[i].print_point();
        std::cout << std::endl;
    }
    polygon.createPolygon(xy_points_array);
    model.push_back(polygon);


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
    polygon.createPolygon(xz_points_array);
    model.push_back(polygon);
    for (int i = 0; i < 4; i++) {
        xz_points_array[i].print_point();
        xz_points_array[i].set_y(H);
        std::cout << std::endl;
    }
    for (int i = 0; i < 4; i++) {
        xz_points_array[i].print_point();
        std::cout << std::endl;
    }
    polygon.createPolygon(xz_points_array);
    model.push_back(polygon);

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
    polygon.createPolygon(yz_points_array);
    model.push_back(polygon);
    for (int i = 0; i < 4; i++) {
        yz_points_array[i].print_point();
        yz_points_array[i].set_x(W);
        std::cout << std::endl;
    }
    for (int i = 0; i < 4; i++) {
        yz_points_array[i].print_point();
        std::cout << std::endl;
    }
    polygon.createPolygon(yz_points_array);
    model.push_back(polygon);

    Point somepoint;
    somepoint.set(W/2, H/2, L/2);
    center = somepoint;

}
