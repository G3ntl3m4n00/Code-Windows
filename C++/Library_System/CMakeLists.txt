cmake_minimum_required(VERSION 4.2)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/G3ntl3m4n/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(Library_System)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(unofficial-pdcurses CONFIG REQUIRED)


add_executable(library
        main.cpp
        Book.cpp
        Person.cpp
        Loan.cpp
        Member.cpp
        Librarian.cpp
        Library.cpp
        UI.cpp
        "Header Files/Book.h"
        "Header Files/Person.h"
        "Header Files/Loan.h"
        "Header Files/Member.h"
        "Header Files/Librarian.h"
        "Header Files/Library.h"
        "Header Files/UI.h"
        "Book.cpp"
        Person.cpp
        Loan.cpp
        Member.cpp
        Librarian.cpp
        Library.cpp
        UI.cpp
        "Header Files/Date.h"
)

target_link_libraries(library PRIVATE unofficial::pdcurses::pdcurses)
