#include "modules/Point.h"
#include <iostream>

int main() {

    const Point A(1, 2);
    const Point B(4, 5);

    std::cout << "A pontok:\n";
    A.print(); std::cout << "\n";
    B.print(); std::cout << std::endl;

    std::cout << "The distance from point A to point B: " << A.distance(B) << std::endl;
}