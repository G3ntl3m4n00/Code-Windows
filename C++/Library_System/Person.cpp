#include "Header Files/Person.h"
#include <iostream>

Person::Person(const std::string &first_name, const std::string &last_name, const std::string &email, const std::string &phone_number, const int id) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->email = email;
    this->phone_number = phone_number;
    this->id = id;
}


// Getter Methods
std::string Person::getFirstName() {
    return first_name;
}

std::string Person::getLastName() {
    return last_name;
}

std::string Person::getEmail() {
    return email;
}

std::string Person::getPhoneNumber() {
    return phone_number;
}

int Person::getId() const {
    return id;
}


// Setter Methods
void Person::setFirstName(const std::string& new_first_name) {
    first_name = new_first_name;
}

void Person::setLastName(const std::string& new_last_name) {
    last_name = new_last_name;
}

void Person::setEmail(const std::string& new_email) {
   email = new_email;
}

void Person::setPhoneNumber(const std::string& new_phone_number) {
    phone_number = new_phone_number;
}

void Person::setId(const int new_id) {
    id = new_id;
}


// Print
void Person::printInfo() const {
    std::cout << "["
              << id << "] "
              << first_name << " "
              << last_name << " : "
              << email << " - "
              << phone_number << std::endl;
}
