#pragma once

#include <string>

class Book {
    std::string title;
    std::string author;
    std::string book_id;
    std::string isbn;
    int publication_year {};
    bool is_available {true};

public:
    Book(const std::string &title,
         const std::string &author,
         const std::string &book_id,
         const std::string &isbn,
         int publication_year
    );

    // Getter Methods
    std::string getTitle();
    std::string getAuthor();
    std::string getBookId();
    std::string getISBN();
    [[nodiscard]] int getPublicationYear() const;
    [[nodiscard]] bool isBookAvailable() const;


    // Setter Methods
    void setAvailable(bool available);


    // Print
    void printInfo() const;

};