#pragma once
#include "Date.h"
#include <string>

class Student {

    std::string name;
    Date born_date;

public:

    // Constructors
    Student();

    Student(std::string name, Date born_date);


    // Getter Methods
    [[nodiscard]] Date getBornDate() const;


    // Print
    void print() const;

};
