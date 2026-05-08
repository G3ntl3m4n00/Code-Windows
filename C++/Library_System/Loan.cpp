#include "Header Files/Loan.h"
#include <iostream>

Loan::Loan(Book *book, Member *member, Date borrow_date) {
    this->book = book;
    this->member = member;
    this->borrow_date = borrow_date;
    this->is_returned = false;
}

// Getter Methods
Book* Loan::getBook() const {
    return book;
}

Member *Loan::getMember() const {
    return member;
}

Date Loan::getBorrowDate() const {
    return borrow_date;
}

Date Loan::getReturnDate() const {
    return return_date;
}

bool Loan::getIsReturned() const {
    return is_returned;
}


// Setter Methods
void Loan::setBook(Book *new_book) {
    this->book = new_book;
}

void Loan::setMember(Member *new_member) {
    this->member = new_member;
}

void Loan::setBorrowDate(const Date new_borrow_date) {
    this->borrow_date = new_borrow_date;
}

void Loan::setReturnDate(const Date new_return_date) {
    this->return_date = new_return_date;
}

void Loan::setIsReturned(bool new_is_returned) {
    this->is_returned = new_is_returned;
}

void Loan::returnBook(Date new_return_date) {
    this->return_date = new_return_date;
    this->is_returned = true;
    book->setAvailable(true);
}

// Print Info
void Loan::printInfo() const {
    std::cout << "Loan: " << book->getTitle()
              << " | Borrow date: " << borrow_date.toString();

    if (is_returned) {
        std::cout << " | Returned: " << return_date.toString();
    } else {
        std::cout << " | Not yet returned";
    }
    std::cout << std::endl;
}
