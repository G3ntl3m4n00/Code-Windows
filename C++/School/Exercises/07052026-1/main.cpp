#include <iostream>
#include <cmath>

class Pont {
private:
    float x;
    float y;

public:
    Pont() {
        x = 0;
        y = 0;
    }

    Pont(const float a, const float b) {
        x = a;
        y = b;
    }

    void writeToConsole() const {
        std::cout << "(" << x << ", " << y << ")" << "\n";
    }

    [[nodiscard]] float distanceFromO() const {
        return std::sqrt(x*x + y*y);
    }

    float distanceFromNode(Pont P) {
        return std::sqrt(std::pow((x - P.x), 2) + std::pow((y - P.y), 2));
    }

    Pont halfPoint(Pont P) {
       return Pont((x + P.x)/2, (y + P.y)/2);
    }
};

int main() {
    auto A = Pont(3, 4);
    auto B = Pont(7,5);

    A.writeToConsole();
    std::cout << A.distanceFromO() << "\n";
    std::cout << "A ket pont tavolsaga: " << A.distanceFromNode(B) << "\n";

    A.halfPoint(B).writeToConsole();
}