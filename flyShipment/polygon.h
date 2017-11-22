#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"
#include <vector>
#include <QColor>

struct Edge {
    Point begin;
    Point end;
    QColor EdgeColor;
};

class ModelPolygon {
public:
    createPolygon(Point* points_array);
    addEdge(Edge edge);

private:
    std::vector<Edge> mpolygon;
    QColor polygon_color;
};

class ShipPolygon {
public:
    createPolygon(Point* points_array);
    addEdge(Edge edge);

private:
    std::vector<Edge> spolygon;
    QColor polygon_color;
};



#endif // POLYGON_H
