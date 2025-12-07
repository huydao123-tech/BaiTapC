#include "view.h"
#include "../inputter/inputter.h"
#include <stdio.h>
#include <stdlib.h>

void showMainMenu() {
    printf("\n========== HE THONG QUAN LY THU VIEN ==========\n");
    printf("1. Quan ly sach\n");
    printf("2. Quan ly nguoi dung\n");
    printf("3. Quan ly muon tra sach\n");
    printf("0. Thoat chuong trinh\n");
    printf("===============================================\n");
    printf("Lua chon cua ban: ");
}

void showBookMenu() {
    printf("\n========== QUAN LY SACH ==========\n");
    printf("1. Them sach moi\n");
    printf("2. Xoa sach\n");
    printf("3. Tim kiem sach theo ID\n");
    printf("4. Hien thi danh sach sach\n");
    printf("0. Quay lai menu chinh\n");
    printf("==================================\n");
    printf("Lua chon cua ban: ");
}

void showUserMenu() {
    printf("\n========== QUAN LY NGUOI DUNG ==========\n");
    printf("1. Them nguoi dung moi\n");
    printf("2. Xoa nguoi dung\n");
    printf("3. Tim kiem nguoi dung theo ID\n");
    printf("4. Hien thi danh sach nguoi dung\n");
    printf("0. Quay lai menu chinh\n");
    printf("========================================\n");
    printf("Lua chon cua ban: ");
}

void showLoanMenu() {
    printf("\n========== QUAN LY MUON TRA SACH ==========\n");
    printf("1. Muon sach\n");
    printf("2. Tra sach\n");
    printf("3. Hien thi danh sach phieu muon\n");
    printf("4. Hien thi sach dang muon cua nguoi dung\n");
    printf("5. Hien thi lich su muon cua sach\n");
    printf("0. Quay lai menu chinh\n");
    printf("==========================================\n");
    printf("Lua chon cua ban: ");
}

void handleBookMenu(BookController* bookCtl) {
    int choice;
    do {
        showBookMenu();
        choice = inputInt("", 0, 4);
        
        switch(choice) {
            case 1: {
                Book* book = ctl_createAndAddBook(bookCtl);
                if(book != NULL) {
                    printf("Them sach thanh cong! ID sach: %d\n", book->id);
                } else {
                    printf("Them sach that bai!\n");
                }
                break;
            }
            case 2: {
                int bookId = inputInt("Nhap ID sach can xoa: ", 1, 9999);
                Book* book = ctl_findBook(bookCtl, bookId);
                if(book != NULL) {
                    ctl_deleteBook(bookCtl, bookId);
                    printf("Xoa sach thanh cong!\n");
                } else {
                    printf("Khong tim thay sach voi ID: %d\n", bookId);
                }
                break;
            }
            case 3: {
                int bookId = inputInt("Nhap ID sach can tim: ", 1, 9999);
                Book* book = ctl_findBook(bookCtl, bookId);
                if(book != NULL) {
                    printf("\n=== THONG TIN SACH ===\n");
                    printf("ID: %d\n", book->id);
                    printf("Tieu de: %s\n", book->title);
                    printf("Tac gia: %s\n", book->author);
                    printf("Trang thai: %s\n", book->isAvailable ? "Co san" : "Da muon");
                    printf("=====================\n");
                } else {
                    printf("Khong tim thay sach voi ID: %d\n", bookId);
                }
                break;
            }
            case 4: {
                ctl_showBookList(bookCtl);
                break;
            }
            case 0:
                printf("Quay lai menu chinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while(choice != 0);
}

void handleUserMenu(UserController* userCtl) {
    int choice;
    do {
        showUserMenu();
        choice = inputInt("", 0, 4);
        
        switch(choice) {
            case 1: {
                User* user = ctl_createAndAddUser(userCtl);
                if(user != NULL) {
                    printf("Them nguoi dung thanh cong! ID nguoi dung: %d\n", user->userId);
                } else {
                    printf("Them nguoi dung that bai!\n");
                }
                break;
            }
            case 2: {
                int userId = inputInt("Nhap ID nguoi dung can xoa: ", 1, 9999);
                User* user = ctl_findUser(userCtl, userId);
                if(user != NULL) {
                    if(user->numberOfBooksBorrowed > 0) {
                        printf("Khong the xoa nguoi dung! Nguoi dung dang muon %d cuon sach.\n", user->numberOfBooksBorrowed);
                    } else {
                        ctl_deleteUser(userCtl, userId);
                        printf("Xoa nguoi dung thanh cong!\n");
                    }
                } else {
                    printf("Khong tim thay nguoi dung voi ID: %d\n", userId);
                }
                break;
            }
            case 3: {
                int userId = inputInt("Nhap ID nguoi dung can tim: ", 1, 9999);
                User* user = ctl_findUser(userCtl, userId);
                if(user != NULL) {
                    printf("\n=== THONG TIN NGUOI DUNG ===\n");
                    printf("ID: %d\n", user->userId);
                    printf("Ten: %s\n", user->name);
                    printf("So sach dang muon: %d\n", user->numberOfBooksBorrowed);
                    printf("============================\n");
                } else {
                    printf("Khong tim thay nguoi dung voi ID: %d\n", userId);
                }
                break;
            }
            case 4: {
                ctl_showUserList(userCtl);
                break;
            }
            case 0:
                printf("Quay lai menu chinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while(choice != 0);
}

void handleLoanMenu(LoanController* loanCtl) {
    int choice;
    do {
        showLoanMenu();
        choice = inputInt("", 0, 5);
        
        switch(choice) {
            case 1: {
                int userId = inputInt("Nhap ID nguoi dung: ", 1, 9999);
                int bookId = inputInt("Nhap ID sach: ", 1, 9999);
                RepoStatus status = ctl_borrowBook(loanCtl, userId, bookId);
                if(status == REPO_OK) {
                    printf("Muon sach thanh cong!\n");
                }
                break;
            }
            case 2: {
                int loanId = inputInt("Nhap ID phieu muon can tra: ", 1, 9999);
                RepoStatus status = ctl_returnBook(loanCtl, loanId);
                if(status == REPO_OK) {
                    printf("Tra sach thanh cong!\n");
                }
                break;
            }
            case 3: {
                ctl_showLoanList(loanCtl);
                break;
            }
            case 4: {
                int userId = inputInt("Nhap ID nguoi dung: ", 1, 9999);
                ctl_showLoansByUser(loanCtl, userId);
                break;
            }
            case 5: {
                int bookId = inputInt("Nhap ID sach: ", 1, 9999);
                ctl_showLoansByBook(loanCtl, bookId);
                break;
            }
            case 0:
                printf("Quay lai menu chinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while(choice != 0);
}

void handleMainMenu(BookController* bookCtl, UserController* userCtl, LoanController* loanCtl) {
    int choice;
    do {
        showMainMenu();
        choice = inputInt("", 0, 3);
        
        switch(choice) {
            case 1:
                handleBookMenu(bookCtl);
                break;
            case 2:
                handleUserMenu(userCtl);
                break;
            case 3:
                handleLoanMenu(loanCtl);
                break;
            case 0:
                printf("Cam on ban da su dung he thong! Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while(choice != 0);
}


