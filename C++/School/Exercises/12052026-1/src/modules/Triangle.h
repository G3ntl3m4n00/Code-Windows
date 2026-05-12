#pragma once

#include "Point.h"

class Triangle {

    Point a, b, c;

public:

    // Constructor
    Triangle(Point a, Point b, Point c);

    // Operators
    [[nodiscard]] double area() const;
    [[nodiscard]] double circumference() const;


    // Print
    void print() const;

};
