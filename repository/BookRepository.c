#include "BookRepository.h"
#include <string.h>

void init_BookRepository(BookRepository* repo)
{
    repo->count = 0;
    repo->nextId = 1;
}

int bookExisted(BookRepository* repo, Book* book)
{
    for(int i=0;i<repo->count;i++){
        if(strcmp(repo->book[i]->author, book->author) == 0 && strcmp(repo->book[i]->title, book->title) == 0){
            return 1;
        }
    }
    return 0;
}
RepoStatus repo_addBook(BookRepository* repo, Book* book)
{
    if(repo->count >= MAX_BOOK){
        return REPO_FULL;
    }
    if(bookExisted(repo, book)) {
        return REPO_DUPLICATE;
    }
    book->id = repo->nextId++;
    repo->book[repo->count++] = book;

    return REPO_OK;
}

RepoStatus repo_deleteBook(BookRepository* repo, int bookId)
{
    if(repo->count == 0) {
        return REPO_EMPTY;
    }
    for(int i=0;i<repo->count;i++) {
        if(repo->book[i]->id == bookId){
            
            freeBook(repo->book[i]);

            for(int j=i;j<repo->count-1;j++) {
                repo->book[j] = repo->book[j+1];
            }

            repo->count--;
            return REPO_OK;
        }
    }
    return REPO_NOTEXIST;
}

RepoStatus repo_updateBook(BookRepository* repo, Book* oldBook, Book* newBook) {
    if(repo->count == 0) {
        return REPO_EMPTY;
    }
    if(!bookExisted(repo,oldBook)) {
        return REPO_NOTEXIST;
    }
    for(int i=0;i<repo->count;i++) {
        if(repo->book[i] == oldBook) {
            repo->book[i] = newBook;
            return REPO_OK;
        }
    }
    return REPO_NOTEXIST;
}

Book* findBookById(BookRepository* repo, int bookId){
    for(int i=0;i<repo->count;i++){
        if(repo->book[i]->id == bookId) {
            return repo->book[i];
        }
    }
    return NULL;
}

