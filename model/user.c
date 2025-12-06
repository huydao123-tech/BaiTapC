#include "user.h"
#include <string.h>
#include <stdlib.h>

User* createUser(const char* name, int id) {
    User* user = (User*) malloc(sizeof(User));
    strcpy(user->name, name);
    user->userId = id;
    return user;

}
void freeUser(User* user) {
    free(user);
}
const char* getUserName(const User* user){
    return user->name;
}
int getUserId(const User* user){
    return user->userId;
}
int getBooksBorrowing(const User* user){
    return user->numberOfBooksBorrowed;
}
void setBookBorrowing(User* user, int numOfBooks){
    user->numberOfBooksBorrowed = numOfBooks;
}