#include "manager.h"

Manager::Manager():
    camera(p_c, p_d),
    active_object(nullptr){}

bool Manager::check_visible_m() {
    for(Polygon& pol : model.polygons) {
        for (Point& point : pol.points) {
            if (!camera.point_visible(point)) {
                return false;
            }
        }
    }
    return true;
}

bool Manager::check_visible_s() {
    for(Polygon& pol : ship.polygons) {
        for (Point& point : pol.points) {
            if (!camera.point_visible(point)) {
                return false;
            }
        }
    }
    return true;
}
