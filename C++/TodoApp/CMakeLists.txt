cmake_minimum_required(VERSION 4.2)
project(TodoApp)

set(CMAKE_CXX_STANDARD 20)

add_executable(TodoApp src/main.cpp
        src/models/TodoItem.cpp
        src/models/TodoItem.h
        src/models/TodoList.cpp
        src/models/TodoList.h
        src/ui/Menu.cpp
        src/ui/Menu.h)

target_include_directories(TodoApp PRIVATE src)