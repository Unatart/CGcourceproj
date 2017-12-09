#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"
#include <vector>
#include <QColor>
#include "flatness.h"
#include <cmath>

const int PTNUM = 3;
const double ACC = 1e-4;

class Polygon {
public:
    std::vector<Point> points;
    QColor polygon_color;

    void setup_flatness();
    double depth_of_pixel(int x, int y) const;
    bool in_polygon(const Point& p) const;

    bool in_polygon(int x, int y) const;

    double min_x() const;
    double max_x() const;

    double min_y() const;
    double max_y() const;


    Flatness flatness;
};


#endif // POLYGON_H
