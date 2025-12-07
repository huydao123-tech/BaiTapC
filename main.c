#include <stdio.h>
#include <stdlib.h>
#include "repository/BookRepository.h"
#include "repository/UserRepository.h"
#include "repository/LoanRepository.h"
#include "controller/BookController.h"
#include "controller/UserController.h"
#include "controller/LoanController.h"
#include "view/view.h"

int main() {
    BookRepository bookRepo;
    UserRepository userRepo;
    LoanRepository loanRepo;
    
    init_BookRepository(&bookRepo);
    init_UserRepository(&userRepo);
    init_LoanRepository(&loanRepo);
    
    BookController bookCtl;
    UserController userCtl;
    LoanController loanCtl;
    
    BookController_init(&bookCtl, &bookRepo);
    UserController_init(&userCtl, &userRepo);
    LoanController_init(&loanCtl, &loanRepo, &bookRepo, &userRepo);
    
    handleMainMenu(&bookCtl, &userCtl, &loanCtl);
    
    return 0;
}

