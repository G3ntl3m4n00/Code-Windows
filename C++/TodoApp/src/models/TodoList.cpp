#include "TodoList.h"

#include <utility>
#include <iostream>

TodoList::TodoList() = default;

void TodoList::addItem(std::string new_title) {
    items.emplace_back(std::move(new_title));
}

void TodoList::removeItem(const int index) {
    items.erase(items.begin() + index);
}

void TodoList::toggleItem(int index) {
    items[index].toggleCompleted();
}

void TodoList::printAll() const {
    for (int i = 0; i < items.size(); i++) {
        std::cout << i << ". [" << (items[i].isCompleted() ? "X" : " ") << "] " << items[i].getTitle() << "\n";
    }
}
