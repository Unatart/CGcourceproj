#ifndef CAMERA_H
#define CAMERA_H

#include "invisible_object.h"
#include "point.h"
//#include "primitives/vector4d.hpp"
//#include "primitives/Point.hpp"
//#include "primitives/matrix4x4.hpp"

class camera : public invisible_object {
    public:
        camera();
        camera(const Point<double>&, const Point<double>&, double, double, double);
        ~camera() = default;

        void set_position(const Point<double>&);
        void set_target(const Point<double>&);

        matrix4x4<double> get_view_matrix();

        void rotate_up_down_sphere(double);
        void rotate_right_left_sphere(double);

        void yaw(double);
        void pitch(double);
        void roll(double);

    private:
        vector4d<double> look;
        vector4d<double> up;
        vector4d<double> right;

        vector4d<double> pos;
        vector4d<double> target;
};


#endif // CAMERA_H
