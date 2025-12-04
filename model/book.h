#ifndef BOOK_H
#define BOOK_H

typedef struct {
    char title[100];
    char author[100];
    int id;
    int isAvailable; // 1 if available, 0 if borrowed
} Book;

Book* createBook(const char* title, const char* author, int id);
void freeBook(Book* book);

// GETTER
const char getBookTitle(const Book* book);
const char getBookAuthor(const Book* book);
int getBookId(const Book* book);
char* isBookAvailable(const Book* book);
void setBookAvailability(Book* book, int availability);
#endif