#pragma once

class Point {

    int x{};
    int y{};

public:
    Point();
    Point(int x, int y);


    // Setter Methods


    // Operators
    [[nodiscard]] double distance(Point P) const;

    // Print
    void print() const;
};
