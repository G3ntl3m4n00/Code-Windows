#pragma once

#include <string>

struct Date {
    int day;
    int month;
    int year;

    [[nodiscard]] std::string toString() const {
        return std::to_string(year) + "." +
               std::to_string(month) + "." +
               std::to_string(day);
    }
};