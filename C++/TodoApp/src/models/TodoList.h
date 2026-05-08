#pragma once

#include <vector>

#include "TodoItem.h"

class TodoList {
    std::vector<TodoItem> items;
    int nextId {};

public:
    TodoList();

    void addItem(std::string new_title);
    void removeItem(int index);
    void toggleItem(int index);
    void printAll() const;

};