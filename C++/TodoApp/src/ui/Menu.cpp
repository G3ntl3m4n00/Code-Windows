// Menu.cpp
#include "Menu.h"
#include <iostream>
#include <cstdlib>

void Menu::run() {
    while (true) {
        system("cls");
        todoList.printAll();
        printMenu();
        switch (getInput()) {
            case 1: handleAdd(); break;
            case 2: handleRemove(); break;
            case 3: handleToggle(); break;
            case 0: return;
            default: std::cout << "Invalid option!\n";
        }
    }
}

int Menu::getInput() {
    int choice;
    std::cin >> choice;
    return choice;
}


void Menu::printMenu() {
    std::cout << "\n1. Add item\n";
    std::cout << "2. Remove item\n";
    std::cout << "3. Toggle item\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

void Menu::handleAdd() {
    std::cout << "Title: ";
    std::string title;
    std::cin.ignore();
    std::getline(std::cin, title);
    todoList.addItem(std::move(title));
}

void Menu::handleRemove() {
    std::cout << "Index: ";
    int index;
    std::cin >> index;
    todoList.removeItem(index);
}

void Menu::handleToggle() {
    std::cout << "Index: ";
    int index;
    std::cin >> index;
    todoList.toggleItem(index);
}