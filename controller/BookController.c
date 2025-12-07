#include "BookController.h"
#include "../inputter/inputter.h"
void BookController_init(BookController* ctl, BookRepository* repo){
    init_BookRepository(repo);
    ctl->repo = repo;
}

void ctl_addBook(BookRepository* ctl, Book* book){
    char* title = NULL;
    char* author = NULL;
    inputString("Nhap tieu de sach: ", &title);
    inputString("Nhap ten tac gia: ", &author);
    strcpy(book->title,title);
    strcpy(book->author, author);

    RepoStatus st = repo_addBook(ctl,book);
    
    if(st == REPO_FULL) {
        printf("Khong the them sach duoc nua vi het slot");
    }
    if(st == REPO_DUPLICATE) {
        printf("Cuon sach da ton tai");
    }
      
    if(st == REPO_OK) {
        printf("Da them sach thanh cong");
    }
    
}

void ctl_deleteBook(BookRepository* ctl, int bookId) {

    RepoStatus st = repo_deleteBook(ctl,bookId);
    if(st==REPO_EMPTY) {
        printf("Khong the xoa vi khong co cuon sach nao");
    }
    printf("Da xoa thanh cong");
}

Book* ctl_findBook(BookRepository* ctl, int bookId) {

}

void ctl_showBookList(BookRepository* ctl);