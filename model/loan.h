#ifndef LOAN_H
#define LOAN_H

typedef struct {
    int userId;
    int bookId;
    int loanId;
} Loan;


Loan* createLoan(int userId,int bookId);
void freeLoan(Loan* loan);

// GETTER
const int getLoanBookId(Loan loan);
const int getLoanUserId(Loan loan);
void setBookLoanForUser(Loan* loan, int bookId);
#endif
