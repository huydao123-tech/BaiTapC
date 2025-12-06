#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include "../model/user.h"
#include "error_code.h"
#define MAX_USER 1000
typedef struct {
    User* user[MAX_USER];
    int count;
    int nextId;
} UserRepository;


void init_UserRepository(UserRepository* repo);

int userExisted(UserRepository* repo, User* user);
RepoStatus repo_addUser(UserRepository* repo, User* user);

RepoStatus repo_deleteUser(UserRepository* repo, int userId);

RepoStatus repo_updateUser(UserRepository* repo, User* oldUser, User* newUser);

User* findUserById(UserRepository* repo, int userId);

#endif