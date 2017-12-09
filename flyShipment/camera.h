#ifndef CAMERA_H
#define CAMERA_H

#include "point.h"
#include <QPoint>
#include <QColor>

const double screen_distance = 700;
const int screen_size_x = 800;
const int screen_size_y = 600;
const int screen_size_x_half = screen_size_x / 2;
const int screen_size_y_half = screen_size_y / 2;


class Camera {
public:

    Camera(const Point& coordinates, const Point& direction);
    QPoint to_screen(const Point& p);
    Point to_screen_3d(const Point& point);
    bool point_visible(const Point& p) const;

    Point coordinates;
    Point direction;
};

#endif // CAMERA_H
