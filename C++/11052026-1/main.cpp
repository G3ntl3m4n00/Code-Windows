#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

class Date {

    int year{};
    int month{};
    int day{};

public:

    // Constructors
    Date() : year(200), month(1), day(1) {}
    Date(const int year, const int month, const int day) : year(year), month(month), day(day) {}


    // Getter Methods
    [[nodiscard]] int getYear() const {
        return year;
    }

    [[nodiscard]] int getMonth() const {
        return month;
    }


    // Operations
    [[nodiscard]] bool leapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    [[nodiscard]] bool isValid() const {
        if (year < 1)
            return false;

        if (month < 1 || month > 12)
            return false;

        int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (leapYear())
            daysInMonths[2] = 29;

        if (day < 1 || day > daysInMonths[month])
            return false;

        return true;
    }

    [[nodiscard]] int compare(const Date& d) const {
        if (const auto c = year <=> d.year; c != 0) return c < 0 ? -1 : 1;
        if (const auto c = month <=> d.month; c != 0) return c < 0 ? -1 : 1;
        if (const auto c = day <=> d.day; c != 0) return c < 0 ? -1 : 1;
        return 0;
    }

    // Print
    void print() const {
        std::cout << year << "/" << month << "/" << day;
    }
};


std::vector<Date> dates;
int num_of_elements;

void readFromFile() {
    std::ifstream inputFile("date.in");

    inputFile >> num_of_elements;

    for (int i = 0; i < num_of_elements; i++) {
        int year, month, day;

        inputFile >> year >> month >> day;

        dates.emplace_back(year, month, day);
    }
}

void writeOutToConsole() {
    for (int i = 0; i < num_of_elements; i++) {
        dates[i].print();
        std::cout << "\n";
    }
    std::cout << std::endl;
}


bool search(const Date d) {
    for (int i = 0; i < num_of_elements; i++) {
       if (dates[i].compare(d) == 0)
           return true;

    }
    return false;
}

bool compare(const Date d1, const Date d2) {
    return d1.getYear() < d2.getYear();
}


int main() {
    readFromFile();
    writeOutToConsole();


    int year, month, day;
    std::cout << "Give a date: \n";
    std::cout << "Year: "; std::cin >> year;
    std::cout << "Month: "; std::cin >> month;
    std::cout << "Day: "; std::cin >> day;
    const Date d(year, month, day);


    if (search(d))
        std::cout << "The date is in the array.\n";
    else
        std::cout << "The date is not in the array.\n";


    for (auto i = 0; i < num_of_elements; i++) {
        if (d.getMonth() == dates[i].getMonth()) {
            dates[i].print();
            std::cout << "\n";
        }
    }
    std::cout << std::endl;



   std::ranges::sort(dates, compare);
   writeOutToConsole();


    for (int i = 0 ;i < num_of_elements; i++) {
        if (dates[i].getMonth() >= 3 and dates[i].getMonth() <= 5)
            dates[i].print(); std::cout << std::endl;
    }

    int leap_year_num = 0;

    for (int i = 0; i < num_of_elements; i++) {
        if (dates[i].leapYear())
            leap_year_num++;
    }
    std::cout << "Leap years: " << leap_year_num << "\n";



    std::ranges::sort(dates, [] (const Date d1, const Date d2){
        return d1.compare(d2);
    });

    writeOutToConsole();
}