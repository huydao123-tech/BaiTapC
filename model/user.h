#ifndef USER_H
#define USER_H

typedef struct {
    char name[100];
    int userId;
    int numberOfBooksBorrowed;
} User;

User* createUser(const char* name, int id);
void freeUser(User* user);

// GETTER
const char* getUserName(const User* user);
int getUserId(const User* user);
int getBooksBorrowing(const User* user);
void setBookBorrowing(User* user, int );
#endif
