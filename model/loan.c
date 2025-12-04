#include "loan.h"
Loan* createLoan(int userId,int bookId){
    Loan* loan = (Loan*)malloc(sizeof(Loan));
    loan->userId = userId;
    loan->bookId = bookId;
    return  loan;
}
void freeLoan(Loan* loan){
    free(loan);
}

// GETTER
const int getLoanBookId(Loan loan){
    return loan.bookId;
}
const int getLoanUserId(Loan loan){
    return loan.userId;
}
void setBookLoanForUser(Loan* loan, int bookId) {
    loan->bookId = bookId;
}
