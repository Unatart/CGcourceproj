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

    Model(const Model& other);
    Model& operator =(const Model& other);
    Point get_center();

    void setColor(QColor color);

    bool insideShip(Ship &plane);

    void move(double dx, double dy, double dz);

    void rotate(double dxy, double dyz, double dzx);
    void resize(double k);

    void rotate(double dxy, double dyz, double dzx, const Point& center);
    void resize(double k, const Point& center) ;

    void printModel();

    std::vector<Polygon> polygons;

private:
    sizes model_size;
    Point center;
};


#endif // MODEL_H
