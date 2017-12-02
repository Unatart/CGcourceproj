#include "polygon.h"

void Polygon::setup_flatness()
{
    Flatness result;

    std::vector<Point> base;
    for (unsigned i = 0; i < PTNUM; ++i) {
        base.push_back(points[i]);
    }

    if (base.size() < PTNUM) {
        throw std::logic_error("Invalid edge!");
    }

    base[1] -= base[0];
    base[2] -= base[0];

    result.a = base[1].get_y() * base[2].get_z() - base[1].get_z() * base[2].get_y();
    result.b = base[1].get_z() * base[2].get_x() - base[1].get_x() * base[2].get_z();
    result.c = base[1].get_x() * base[2].get_y() - base[1].get_y() * base[2].get_x();

    result.d = - (base[0].get_x() * result.a + base[0].get_y() * result.b + \
            base[0].get_z() * result.c);

    flatness = result;
}

double Polygon::depth_of_pixel(int x, int y) const {
    double depth = 0;
    if (fabs(flatness.c) < ACC) {
        return 0;
    }
    depth = -(flatness.a*x + flatness.b*y + flatness.d)/ flatness.c;

    return depth;
}


