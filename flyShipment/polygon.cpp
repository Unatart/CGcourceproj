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
	double depth = std::numeric_limits<double>::lowest();

	if (fabs(flatness.c) < ACC) {
		for (const Point& p : points) {
			depth = std::max(p.get_z(), depth);
		}
		return depth;
    }

    depth = -(flatness.a*x + flatness.b*y + flatness.d)/ flatness.c;

    return depth;
}

bool Polygon::in_polygon(const Point& p) const {

    auto it = points.cbegin();

    Point vec1(*it - *points.crbegin());
    Point vec2(p - *points.crbegin());

    Point first = vec1 * vec2;

    for (auto it2 = it + 1; it2 != points.cend(); ++it, ++it2) {
        vec1 = *it2 - *it;
        vec2 = p - *it;

		Point second = vec1 * vec2;

		double mult_z = first.get_z() * second.get_z();
		if (mult_z <= 0) {
			return false;
		}
        first = second;

    }

    return true;
}

bool Polygon::infront(const Point& p) const {
    if ((flatness.a * p.get_x() + flatness.b * p.get_y() + flatness.c * p.get_z() + flatness.d) > 0)
        return true;
    return false;
}

bool Polygon::behind(const Point& p) const {
    if ((flatness.a * p.get_x() + flatness.b * p.get_y() + flatness.c * p.get_z() + flatness.d) < 0)
        return true;
    return false;
}

bool Polygon::in_polygon(int x, int y) const {

    auto it = points.crbegin();
    auto it2 = points.cbegin();
    Point vec1((*it2).get_x() - (*it).get_x(), (*it2).get_y() - (*it).get_y(), 0);
    Point vec2(x - (*it).get_x(), y - (*it).get_y(), 0);

    Point first(vec1 * vec2);

    auto it1 = it2;
    it2 = it1 + 1;
    while (it2 != points.cend()) {
        vec1.set_x((*it2).get_x() - (*it1).get_x());
        vec1.set_y((*it2).get_y() - (*it1).get_y());
        vec2.set_x(x - (*it1).get_x());
        vec2.set_y(y - (*it1).get_y());

        Point second(vec1 * vec2);
		if (second.get_z() * first.get_z() <= 0) {
            return false;
        }
        first = second;

        ++it1;
        ++it2;
    }
    return true;
}

double Polygon::min_x() const {
    auto it = points.cbegin();
    double min_x((*it).get_x());
    while (it != points.cend()) {
        if ((*it).get_x() < min_x) {
            min_x = (*it).get_x();
        }
        ++it;
    }
    return min_x;
}

double Polygon::max_x() const {
    auto it = points.cbegin();
    double max_x((*it).get_x());
    while (it != points.cend()) {
        if ((*it).get_x() > max_x) {
            max_x = (*it).get_x();
        }
        ++it;
    }
    return max_x;
}

double Polygon::min_y() const {
    auto it = points.cbegin();
    double min_y((*it).get_y());
    while (it != points.cend()) {
        if ((*it).get_y() < min_y) {
            min_y = (*it).get_y();
        }
        ++it;
    }
    return min_y;
}

double Polygon::max_y() const {
    auto it = points.cbegin();
    double max_y((*it).get_y());
    while (it != points.cend()) {
        if ((*it).get_y() > max_y) {
            max_y = (*it).get_y();
        }
        ++it;
    }
    return max_y;
}
