#ifndef VIEW_H
#define VIEW_H

#include "../controller/BookController.h"
#include "../controller/UserController.h"
#include "../controller/LoanController.h"

void showMainMenu();
void showBookMenu();
void showUserMenu();
void showLoanMenu();

void handleBookMenu(BookController* bookCtl);
void handleUserMenu(UserController* userCtl);
void handleLoanMenu(LoanController* loanCtl);
void handleMainMenu(BookController* bookCtl, UserController* userCtl, LoanController* loanCtl);

#endif


