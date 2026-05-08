#pragma once

#include <string>

class Person {
    std::string first_name;
    std::string last_name;
    std::string email;
    std::string phone_number;
    int id {};

public:
    Person(const std::string &first_name,
           const std::string &last_name,
           const std::string &email,
           const std::string &phone_number,
           int id
    );

    // Getter Methods
    std::string getFirstName();
    std::string getLastName();
    std::string getEmail();
    std::string getPhoneNumber();
    [[nodiscard]] int getId() const;

    // Set Methods
    void setFirstName(const std::string& new_first_name);
    void setLastName(const std::string& new_last_name);
    void setEmail(const std::string& new_email);
    void setPhoneNumber(const std::string& new_phone_number);
    void setId(int new_id);

    // Print
    void printInfo() const;

};