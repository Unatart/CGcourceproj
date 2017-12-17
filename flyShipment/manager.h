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

    void add_model(const Model& model);
    void delete_model(int index);

    bool check_visible_m(const Model& model) const;
    bool check_visible_s() const;
    int num_of_models();

    Camera camera;

    std::vector<Model> model_list;
    Ship ship;

    SceneObject* active_object = nullptr;
};

#endif // MANAGER_H
