#include "Triangle.h"
#include <iostream>

Triangle::Triangle(Point a, Point b, Point c) {
    this->a = a;
    this->b = b;
    this->c = c;
}


[[nodiscard]] double Triangle::circumference() const {
    return a.distance(b) + b.distance(c) + c.distance(a);
}

[[nodiscard]] double Triangle::area() const {
    double s = circumference();
    double ab {a.distance(b)};
    double ac {a.distance(c)};
    double bc {b.distance(c)};

    return sqrt(s * (s - a) * (s-b) * (s-c));
}
