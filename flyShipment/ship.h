#ifndef SHIP_H
#define SHIP_H

#include "point.h"
#include "polygon.h"
#include "sceneobj.h"

struct ship_sizes {
    int L;
    int H;
    int Wb;
    int Wt;
};

class Ship : public SceneObject{
public:

    Ship() = default;
    Ship(const Ship& other) = default;

    void createShip(int L, int H, int Wt, int Wb);
    void setColor();

    Point front_vector;

private:
    ship_sizes ship_size;
    Point front;

};



#endif // SHIP_H
