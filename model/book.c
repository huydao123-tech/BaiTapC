#include "book.h"
#include <string.h>
#include <stdlib.h>

Book* createBook(const char* title, const char* author, int id) {
    Book* book = (Book*)malloc(sizeof(Book));
    book->id = id;
    strcpy(book->title,title);
    strcpy(book->author,author);
    book->isAvailable = 1;
    return book;
}

void freeBook(Book* b){
    free(b);
}

const char* getBookTitle(const Book* book){
    return book->title;
}
const char* getBookAuthor(const Book* book){
    return book->author;
}
int getBookId(const Book* book) {
    return book->id;
}
char* isBookAvailable(const Book* book){
    if(book->isAvailable == 1) 
    {
        return "Book is exist";
    }
    else
    {
        return "Book is borrowed";
    }
}
void setBookAvailability(Book* book, int availability){
    book->isAvailable = availability;
}
