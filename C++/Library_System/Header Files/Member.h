#pragma once

#include "Person.h"
#include "Loan.h"
#include <vector>

class Member : public Person {
private:
    std::vector<Loan*> active_loans;
    std::vector<Loan*> loan_history;
    int max_loans;

public:
    Member(const std::string& first_name,
           const std::string& last_name,
           const std::string& email,
           const std::string& phone_number,
           int id,
           int max_loans = 3
    );

    // Getter Methods
    [[nodiscard]] std::vector<Loan*> getActiveLoans() const;
    [[nodiscard]] std::vector<Loan*> getLoanHistory() const;
    [[nodiscard]] int getMaxLoans() const;

    void setMaxLoans(int newMaxLoans);

    // Operators
    bool borrowBook(Book* book, Date borrow_date);
    void returnBook(Book* book, Date return_date);

    // Print
    void printInfo() const;
    void printActiveLoans() const;
    void printLoanHistory() const;

};