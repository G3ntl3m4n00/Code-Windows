#pragma once

#include "Date.h"
#include "Book.h"

class Member;

class Loan {
    Book* book {};
    Member* member {};
    Date borrow_date {};
    Date return_date {};
    bool is_returned {};

public:
    Loan(Book* book,
         Member* member,
         Date borrow_date
    );

    // Getter Methods
    [[nodiscard]] Book* getBook() const;
    [[nodiscard]] Member* getMember() const;
    [[nodiscard]] Date getBorrowDate() const;
    [[nodiscard]] Date getReturnDate() const;
    [[nodiscard]] bool getIsReturned() const;


    // Setter Methods
    void setBook(Book* new_book);
    void setMember(Member* new_member);
    void setBorrowDate(Date new_borrow_date);
    void setReturnDate(Date new_return_date);
    void setIsReturned(bool new_is_returned);


    // Operator
    void returnBook(Date new_return_date);

    // Print
    void printInfo() const;

};