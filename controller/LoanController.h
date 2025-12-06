#ifndef LOAN_CONTROLLER_H
#define LOAN_CONTROLLER_H
#include "../repository/LoanRepository.h"
#include "../repository/BookRepository.h"
#include "../repository/UserRepository.h"

typedef struct{
    LoanRepository* loanRepo;
    BookRepository* bookRepo;
    UserRepository* userRepo;
} LoanController;

void LoanController_init(LoanController* ctl, LoanRepository* loanRepo, BookRepository* bookRepo, UserRepository* userRepo);

RepoStatus ctl_borrowBook(LoanController* ctl, int userId, int bookId);

RepoStatus ctl_returnBook(LoanController* ctl, int loanId);

void ctl_showLoanList(LoanController* ctl);

void ctl_showLoansByUser(LoanController* ctl, int userId);

void ctl_showLoansByBook(LoanController* ctl, int bookId);

#endif

