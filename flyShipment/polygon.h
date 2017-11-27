#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"
#include <vector>
#include <QColor>

class Polygon {
public:
    std::vector<Point> points;
    QColor polygon_color;
};


#endif // POLYGON_H
