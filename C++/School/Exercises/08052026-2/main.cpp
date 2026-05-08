#include <iostream>
#include <cmath>

class Triangle {
    double a, b, c;

public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    [[nodiscard]] bool isTriangle() const {
        return a + b > c && a + c > b && b + c > a;
    }

    [[nodiscard]] double perimeter() const {
        return a + b + c;
    }

    [[nodiscard]] double area() const {
        const double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    [[nodiscard]] bool isEquilateral() const {
        return a == b && a == c;
    }

    [[nodiscard]] bool isIsosceles() const {
        return a == b || a == c || b == c;
    }

    [[nodiscard]] bool isRightAngled() const {
        double x = a, y = b, z = c;
        if (x < y) std::swap(x, y);
        if (x < z) std::swap(x, z);
        return std::abs(y*y + z*z - x*x) < 1e-9;
    }

    void printSorted() const {
        double x = a, y = b, z = c;
        if (x > y) std::swap(x, y);
        if (x > z) std::swap(x, z);
        if (y > z) std::swap(y, z);
        std::cout << x << ", " << y << ", " << z << std::endl;
    }

};

int main() {
    Triangle A = Triangle(3, 4, 5);

    if (A.isTriangle()) {
        std::cout << "The triangle sides: "; A.printSorted();

        std::cout << "Perimeter: " << A.perimeter() << std::endl;
        std::cout << "Area: " << A.area() << std::endl;

        std::cout << "Is the triangle equilateral: "; A.isEquilateral() ? std::cout <<  "Yes" : std::cout << "No"; std::cout << std::endl;
        std::cout << "Is the triangle isosceles: "; A.isIsosceles() ? std::cout <<  "Yes" : std::cout << "No"; std::cout << std::endl;
        std::cout << "Is the triangle right-angled: "; A.isRightAngled() ? std::cout <<  "Yes" : std::cout << "No"; std::cout << std::endl;

    }
}