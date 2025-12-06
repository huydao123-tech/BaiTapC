#include "LoanRepository.h"
#include <stdlib.h>
#include "../model/loan.h"

void init_LoanRepository(LoanRepository* repo){
    repo->count = 0;
    repo->nextId = 1;
}

RepoStatus repo_addLoan(LoanRepository* repo, int userId, int bookId) {

    if(repo->count >= MAX_LOAN) {
        return REPO_FULL;
    }

    Loan* loan = createLoan(userId, bookId);
    loan->loanId = repo->nextId++;

    repo->loanList[repo->count++] = loan;
    return REPO_OK;
}

int repo_FindLoanIndexById(LoanRepository* repo, int loanId){
    for(int i=0;i<repo->count;i++) {
        if(repo->loanList[i]->loanId == loanId) {
            return i;
        }
    }

    return -1;
}

RepoStatus repo_deleteLoan(LoanRepository* repo, int loanId) {
    int index = repo_FindLoanIndexById(repo,loanId);
    if(index==-1) {
        return REPO_NOTEXIST;
    }
    freeLoan(repo->loanList[index]);

    for(int i=index;i<repo->count-1;i++){
        repo->loanList[i] = repo->loanList[i+1];
    }
    repo->count--;
    return REPO_OK;
}