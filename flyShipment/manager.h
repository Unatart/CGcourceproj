#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include "model.h"
#include "ship.h"
#include "camera.h"
#include "sceneobj.h"

const Point p_c(0, 0, 400);
const Point p_d(0, 0, -1);
const double distance = 300;

class Manager {
public:
    Manager();

    bool check_visible_m();
    bool check_visible_s();

    Camera camera;

    Model model;
    Ship ship;

    SceneObject* active_object = nullptr;
};

#endif // MANAGER_H
