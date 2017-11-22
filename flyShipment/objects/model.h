#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>

#include "point.h"
#include "visible_object.h"

class model : public visible_object {
public:
    explicit model() = default;
    explicit model(const std::vector<std::pair<Point<double>, Point<double>>>&);
    model(const model&);
    ~model() = default;

    model& operator=(const model&);
    model& operator=(model&&);

    //friend class model_transformations;
    //friend class draw_manager;

protected:
    void set_up_center();

private:
    std::vector<std::pair<Point<float>, Point<float>>> edges;

};

#endif // MODEL_H
