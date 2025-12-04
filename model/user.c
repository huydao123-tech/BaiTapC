#include "user.h"

User* createUser(const char* name, int id) {
    User* user = (User*) malloc(sizeof(User));
    strcpy(user->name, name);
    user->userId = id;
    return user;

}

const char getUserName(const User* user){
    return user->name;
}
const char getUserId(const User* user){
    return user->userId;
}
int getBooksBorrowing(const User* user){
    return user->numberOfBooksBorrowed;
}
void setBookBorrowing(User* user, int numOfBooks){
    user->numberOfBooksBorrowed = numOfBooks;
}