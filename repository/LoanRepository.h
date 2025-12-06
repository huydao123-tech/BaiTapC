#ifndef LOAN_REPOSITORY_H
#define LOAN_REPOSITORY_H

#include "error_code.h"
#include "../model/loan.h"
#define MAX_LOAN 1000
typedef struct {
    Loan* loanList[1000];
    int count;
    int nextId;
} LoanRepository;

void init_LoanRepository(LoanRepository* repo);
RepoStatus repo_addLoan(LoanRepository* repo, int userId, int bookId);
int repo_FindLoanIndexById(LoanRepository* repo, int loanId);
RepoStatus repo_deleteLoan(LoanRepository* repo, int loanId);

#endif