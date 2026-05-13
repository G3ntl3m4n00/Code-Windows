#include <iostream>
#include <vector>
#include "modules/Student.h"
#include <fstream>

std::vector<Student> students;
int numOfStudents {};

void readFromFile() {
    std::ifstream input_file("students.in");

    std::string name;
    int year, month, day;

    while (getline(input_file, name)) {
        input_file >> year >> month >> day;
        input_file.ignore();

        Student s(name, {year, month, day});
        students.push_back(s);
        numOfStudents++;
    }
}

void printAll() {
    for (int i = 0; i < numOfStudents; i++) {
        students[i].print();
    }
}


int main() {

    readFromFile();

    std::cout << "Students:\n";
    printAll();


}