#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "polygon.h"
#include "sceneobj.h"
#include "ship.h"

struct sizes {
    int L;
    int H;
    int W;
};

class Model : public SceneObject {
public:

    Model() = default;
    Model(int L, int H, int W);

    Model(const Model& other) = default;
    Model& operator =(const Model& other);

    void setColor(QColor color);

    bool insideShip(const Ship &plane) const;

    void printModel();


private:
    sizes model_size;
};


#endif // MODEL_H
