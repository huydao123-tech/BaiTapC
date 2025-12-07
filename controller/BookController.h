#ifndef BOOK_CONTROLLER_H
#define BOOK_CONTROLLER_H
#include "../repository/BookRepository.h"

typedef struct{
    BookRepository* repo;
} BookController;

void BookController_init(BookController* ctl, BookRepository* repo);

void ctl_addBook(BookController* ctl, Book* book);

Book* ctl_createAndAddBook(BookController* ctl);

void ctl_deleteBook(BookController* ctl, int bookId);

Book* ctl_findBook(BookController* ctl, int bookId);

void ctl_showBookList(BookController* ctl);

#endif