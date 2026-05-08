// Member.cpp
#include "Header Files/Member.h"
#include <iostream>

Member::Member(const std::string& first_name,
               const std::string& last_name,
               const std::string& email,
               const std::string& phone_number,
               int id,
               int max_loans)
    : Person(first_name, last_name, email, phone_number, id) {
    this->max_loans = max_loans;
}

// Getter Methods
std::vector<Loan*> Member::getActiveLoans() const {
    return active_loans;
}

std::vector<Loan*> Member::getLoanHistory() const {
    return loan_history;
}

int Member::getMaxLoans() const {
    return max_loans;
}

// Setter Methods
void Member::setMaxLoans(int newMaxLoans) {
    this->max_loans = newMaxLoans;
}

// Operations
bool Member::borrowBook(Book* book, Date borrow_date) {
    if (!book->isBookAvailable()) {
        std::cout << "Error: Book is not available." << std::endl;
        return false;
    }
    if (active_loans.size() >= max_loans) {
        std::cout << "Error: Loan limit reached." << std::endl;
        return false;
    }

    Loan* loan = new Loan(book, this, borrow_date);
    active_loans.push_back(loan);
    book->setAvailable(false);
    return true;
}

void Member::returnBook(Book* book, Date return_date) {
    for (int i = 0; i < active_loans.size(); i++) {
        if (active_loans[i]->getBook() == book) {
            active_loans[i]->returnBook(return_date);
            loan_history.push_back(active_loans[i]);
            active_loans.erase(active_loans.begin() + i);
            return;
        }
    }
    std::cout << "Error: Book not found in active loans." << std::endl;
}

// Print
void Member::printInfo() const {
    std::cout << "[" << getId() << "] "
              << getFirstName() << " " << getLastName()
              << " | Email: " << getEmail()
              << " | Phone: " << getPhoneNumber()
              << " | Active loans: " << active_loans.size()
              << "/" << max_loans << std::endl;
}

void Member::printActiveLoans() const {
    if (active_loans.empty()) {
        std::cout << "No active loans." << std::endl;
        return;
    }
    std::cout << "Active loans:" << std::endl;
    for (const auto& loan : active_loans) {
        loan->printInfo();
    }
}

void Member::printLoanHistory() const {
    if (loan_history.empty()) {
        std::cout << "No loan history." << std::endl;
        return;
    }
    std::cout << "Loan history:" << std::endl;
    for (const auto& loan : loan_history) {
        loan->printInfo();
    }
}