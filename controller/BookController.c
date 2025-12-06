#include "BookController.h"
#include "../inputter/inputter.h"
#include "../model/book.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BookController_init(BookController* ctl, BookRepository* repo){
    ctl->repo = repo;
}

void ctl_addBook(BookController* ctl, Book* book){
    char title[100];
    char author[100];
    inputString("Nhap ten tieu de sach: ", title);
    inputString("Nhap ten tac gia: ", author);
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->isAvailable = 1;
    repo_addBook(ctl->repo, book);
}

Book* ctl_createAndAddBook(BookController* ctl){
    char title[100];
    char author[100];
    inputString("Nhap ten tieu de sach: ", title);
    inputString("Nhap ten tac gia: ", author);
    Book* book = createBook(title, author, 0); // ID sẽ được set bởi repository
    RepoStatus status = repo_addBook(ctl->repo, book);
    if(status != REPO_OK){
        freeBook(book);
        return NULL;
    }
    return book;
}

void ctl_deleteBook(BookController* ctl, int bookId){
    repo_deleteBook(ctl->repo, bookId);
}

Book* ctl_findBook(BookController* ctl, int bookId){
    return findBookById(ctl->repo, bookId);
}

void ctl_showBookList(BookController* ctl){
    if(ctl->repo->count == 0){
        printf("Danh sach sach trong!\n");
        return;
    }
    printf("\n=== DANH SACH SACH ===\n");
    for(int i = 0; i < ctl->repo->count; i++){
        printf("ID: %d, Tieu de: %s, Tac gia: %s, Trang thai: %s\n", 
               ctl->repo->book[i]->id,
               ctl->repo->book[i]->title,
               ctl->repo->book[i]->author,
               ctl->repo->book[i]->isAvailable ? "Co san" : "Da muon");
    }
    printf("======================\n\n");
}