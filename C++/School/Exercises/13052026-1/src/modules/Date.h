#pragma once

class Date {
    int year{};
    int month{};
    int day{};

public:

    // Constructors
    Date();

    explicit Date(int year);
    Date(int year, int month);
    Date(int year, int month, int day);


    // Operators
    [[nodiscard]] int compare(const Date& d) const;

    // Print
    void print() const;
};