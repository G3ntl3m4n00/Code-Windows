#include "Student.h"
#include <utility>
#include <iostream>



// Constructors

Student::Student() = default;

Student::Student(std::string name, const Date born_date) {
    this->name = std::move(name);
    this->born_date = born_date;
}

// Getter Methods
Date Student::getBornDate() const {
    return born_date;
}


// Print

void Student::print() const {
    std::cout << name << " - "; born_date.print(); std::cout << std::endl;
}
