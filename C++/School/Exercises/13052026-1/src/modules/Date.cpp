#include "Date.h"
#include <iostream>

// Constructors

Date::Date() {
    year = 2000;
    month = 1;
    day = 1;
}

Date::Date(const int year) {
    this->year = year;
    month = 1;
    day = 1;
}

Date::Date(const int year, const int month) {
    this->year = year;
    this->month = month;
}

Date::Date(const int year, const int month, const int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

// Operators
[[nodiscard]] int Date::compare(const Date &d) const {
   if (const auto c = year <=> d.year; c!= 0 )
       return c < 0 ? -1 : 1;
   if (const auto c = month <=> d.month; c!=0)
       return c < 0 ? -1:1;
   if (const auto c = day <=> d.day; c!=0)
       return c < 0 ? -1 : 1;
   return 0;
}


// Print
void Date::print() const {
   std::cout << year << "." << month << "." << day;
}
