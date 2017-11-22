#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include "model.h"
#include "ship.h"
#include "camera.h"

const Point p_c(0, 0, 400);
const Point p_d(0, 0, -1);
const double distance = 300;

class Manager {
public:
    Manager();

    bool check_visible(Model& init_model);
    bool check_visible(Ship& init_ship);

    Model model;
    Ship plane;
    Camera camera;

    SceneObj* active_object = nullptr;
};

#endif // MANAGER_H
