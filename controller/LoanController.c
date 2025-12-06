#include "LoanController.h"
#include "../inputter/inputter.h"
#include "../model/loan.h"
#include "../model/book.h"
#include "../model/user.h"
#include <stdio.h>
#include <string.h>

void LoanController_init(LoanController* ctl, LoanRepository* loanRepo, BookRepository* bookRepo, UserRepository* userRepo){
    ctl->loanRepo = loanRepo;
    ctl->bookRepo = bookRepo;
    ctl->userRepo = userRepo;
}

RepoStatus ctl_borrowBook(LoanController* ctl, int userId, int bookId){
    // Kiểm tra user có tồn tại không
    User* user = findUserById(ctl->userRepo, userId);
    if(user == NULL){
        printf("Khong tim thay nguoi dung voi ID: %d\n", userId);
        return REPO_NOTEXIST;
    }
    
    // Kiểm tra book có tồn tại không
    Book* book = findBookById(ctl->bookRepo, bookId);
    if(book == NULL){
        printf("Khong tim thay sach voi ID: %d\n", bookId);
        return REPO_NOTEXIST;
    }
    
    // Kiểm tra sách có sẵn không
    if(book->isAvailable == 0){
        printf("Sach da duoc muon!\n");
        return REPO_DUPLICATE;
    }
    
    // Kiểm tra user đã mượn quá nhiều sách chưa (giả sử tối đa 5 cuốn)
    if(user->numberOfBooksBorrowed >= 5){
        printf("Nguoi dung da muon toi da so sach!\n");
        return REPO_FULL;
    }
    
    // Thêm loan
    RepoStatus status = repo_addLoan(ctl->loanRepo, userId, bookId);
    if(status == REPO_OK){
        // Cập nhật trạng thái sách
        book->isAvailable = 0;
        // Cập nhật số sách đang mượn của user
        user->numberOfBooksBorrowed++;
        printf("Muon sach thanh cong!\n");
    }
    
    return status;
}

RepoStatus ctl_returnBook(LoanController* ctl, int loanId){
    // Tìm loan
    int index = repo_FindLoanIndexById(ctl->loanRepo, loanId);
    if(index == -1){
        printf("Khong tim thay phieu muon voi ID: %d\n", loanId);
        return REPO_NOTEXIST;
    }
    
    Loan* loan = ctl->loanRepo->loanList[index];
    int userId = loan->userId;
    int bookId = loan->bookId;
    
    // Xóa loan
    RepoStatus status = repo_deleteLoan(ctl->loanRepo, loanId);
    if(status == REPO_OK){
        // Cập nhật trạng thái sách
        Book* book = findBookById(ctl->bookRepo, bookId);
        if(book != NULL){
            book->isAvailable = 1;
        }
        
        // Cập nhật số sách đang mượn của user
        User* user = findUserById(ctl->userRepo, userId);
        if(user != NULL && user->numberOfBooksBorrowed > 0){
            user->numberOfBooksBorrowed--;
        }
        
        printf("Tra sach thanh cong!\n");
    }
    
    return status;
}

void ctl_showLoanList(LoanController* ctl){
    if(ctl->loanRepo->count == 0){
        printf("Danh sach phieu muon trong!\n");
        return;
    }
    printf("\n=== DANH SACH PHIEU MUON ===\n");
    for(int i = 0; i < ctl->loanRepo->count; i++){
        Loan* loan = ctl->loanRepo->loanList[i];
        User* user = findUserById(ctl->userRepo, loan->userId);
        Book* book = findBookById(ctl->bookRepo, loan->bookId);
        
        printf("Loan ID: %d, User: %s (ID: %d), Book: %s (ID: %d)\n",
               loan->loanId,
               user ? user->name : "Unknown",
               loan->userId,
               book ? book->title : "Unknown",
               loan->bookId);
    }
    printf("============================\n\n");
}

void ctl_showLoansByUser(LoanController* ctl, int userId){
    User* user = findUserById(ctl->userRepo, userId);
    if(user == NULL){
        printf("Khong tim thay nguoi dung voi ID: %d\n", userId);
        return;
    }
    
    printf("\n=== SACH DANG MUON CUA %s (ID: %d) ===\n", user->name, userId);
    int found = 0;
    for(int i = 0; i < ctl->loanRepo->count; i++){
        Loan* loan = ctl->loanRepo->loanList[i];
        if(loan->userId == userId){
            Book* book = findBookById(ctl->bookRepo, loan->bookId);
            printf("Loan ID: %d, Book: %s (ID: %d)\n",
                   loan->loanId,
                   book ? book->title : "Unknown",
                   loan->bookId);
            found = 1;
        }
    }
    if(!found){
        printf("Nguoi dung nay chua muon sach nao.\n");
    }
    printf("========================================\n\n");
}

void ctl_showLoansByBook(LoanController* ctl, int bookId){
    Book* book = findBookById(ctl->bookRepo, bookId);
    if(book == NULL){
        printf("Khong tim thay sach voi ID: %d\n", bookId);
        return;
    }
    
    printf("\n=== LICH SU MUON SACH: %s (ID: %d) ===\n", book->title, bookId);
    int found = 0;
    for(int i = 0; i < ctl->loanRepo->count; i++){
        Loan* loan = ctl->loanRepo->loanList[i];
        if(loan->bookId == bookId){
            User* user = findUserById(ctl->userRepo, loan->userId);
            printf("Loan ID: %d, User: %s (ID: %d)\n",
                   loan->loanId,
                   user ? user->name : "Unknown",
                   loan->userId);
            found = 1;
        }
    }
    if(!found){
        printf("Sach nay chua duoc muon.\n");
    }
    printf("========================================\n\n");
}

