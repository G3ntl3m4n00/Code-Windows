// Menu.h
#pragma once

#include "../models/TodoList.h"

class Menu {
    TodoList todoList;

public:
    void run();

private:
    static void printMenu();
    static int getInput();
    void handleAdd();
    void handleRemove();
    void handleToggle();
};