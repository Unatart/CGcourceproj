#include "manager.h"

Manager::Manager():
    active_object(nullptr),
    camera(p_c, p_d){}

bool Manager::check_visible_m() {
    for(ModelPolygon& pol : model.model) {
        for (Edge& edge : pol.mpolygon) {
            if (!camera.point_visible(edge.begin) || !camera.point_visible(edge.end)) {
                return false;
            }
        }
    }
    return true;
}

bool Manager::check_visible_s() {
    for(ShipPolygon& pol : ship.ship) {
        for (Edge& edge : pol.spolygon) {
            if (!camera.point_visible(edge.begin) || !camera.point_visible(edge.end)) {
                return false;
            }
        }
    }
    return true;
}
