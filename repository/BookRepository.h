#ifndef BOOK_REPOSITORY_H

#define BOOK_REPOSITORY_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOK 1000
#include "error_code.h"
#include "../model/book.h"
typedef struct {
    Book* book[MAX_BOOK];
    int count;
    int nextId;
} BookRepository;


void init_BookRepository(BookRepository* repo);
RepoStatus repo_addBook(BookRepository* repo, Book* book);

RepoStatus repo_deleteBook(BookRepository* repo, int bookId);

RepoStatus repo_updateBook(BookRepository* repo, Book* oldBook, Book* newBook);

RepoStatus bookExisted(BookRepository* repo, Book* book);

Book* findBookById(BookRepository* repo, int bookId);

#endif
