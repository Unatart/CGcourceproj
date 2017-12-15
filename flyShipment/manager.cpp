#include "manager.h"

Manager::Manager():
    camera(p_c, p_d),
    active_object(nullptr){}

void Manager::add_model(const Model &model) {
    this->model_list.push_back(model);
}

bool Manager::check_visible_m(const Model &model) const {
    for(const Polygon& pol : model.polygons) {
        for (const Point& point : pol.points) {
            if (!camera.point_visible(point)) {
                return false;
            }
        }
    }
    return true;
}

bool Manager::check_visible_s() const {
    for(const Polygon& pol : ship.polygons) {
        for (const Point& point : pol.points) {
            if (!camera.point_visible(point)) {
                return false;
            }
        }
    }
    return true;
}

int Manager::num_of_models() {
    return this->model_list.size();
}
