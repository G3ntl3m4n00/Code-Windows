#include "Header Files/Book.h"
#include <iostream>

Book::Book(const std::string &title, const std::string &author, const std::string &book_id, const std::string &isbn, const int publication_year) {
    this->title = title;
    this->author = author;
    this->book_id = book_id;
    this->isbn = isbn;
    this->publication_year = publication_year;
    this->is_available = true;
}

std::string Book::getTitle() {
    return title;
}

std::string Book::getAuthor() {
    return author;
}

std::string Book::getBookId() {
    return book_id;
}

std::string Book::getISBN() {
    return isbn;
}

int Book::getPublicationYear() const {
    return publication_year;
}

bool Book::isBookAvailable() const {
    return is_available;
}

void Book::setAvailable(const bool available) {
    is_available = available;
}

void Book::printInfo() const {
    std::cout << "["
              << book_id << "] "
              << title << " - "
              << author << "("
              << isbn << ") ["
              << publication_year << "] : ";

    if (is_available)
        std::cout << " (AVAILABLE)" << std::endl;
    else
        std::cout << " (NOT AVAILABLE)" << std::endl;
}
