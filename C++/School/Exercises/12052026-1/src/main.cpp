#include "modules/Point.h"
#include "modules/Triangle.h"
#include <iostream>

int main() {

    const Point A(1, 2);
    const Point B;

    std::cout << "A pontok:\n";
    A.print(); std::cout << "\n";
    B.print(); std::cout << std::endl;

    std::cout << "The distance from point A to point B: " << A.distance(B) << std::endl;


    Triangle t(A, B, {2, 3});

    std::cout << "The triangle's area: " << t.area();
    std::cout << "The triangle's circumference: " << t.circumference();

}