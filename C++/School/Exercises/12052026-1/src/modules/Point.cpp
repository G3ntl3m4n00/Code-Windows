#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(const int x, const int y) {
    this->x = x;
    this->y = y;
}


// Operator
[[nodiscard]] double Point::distance(Point P) const {
    return sqrt(pow(x - P.x, 2) + pow(y - P.y, 2));
}

// Print
void Point::print() const {
    std::cout << "(" << x << ", " << y << ")";
}
