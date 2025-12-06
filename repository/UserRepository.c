#include "UserRepository.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void init_UserRepository(UserRepository* repo){
    repo->count = 0;
    repo->nextId=1;
}

int userExisted(UserRepository* repo, User* user) {
    for(int i=0;i<repo->count;i++){
        if(repo->user[i] == user) {
            return 1;
        }
    }
    return 0;
}
RepoStatus repo_addUser(UserRepository* repo, User* user){
    if(repo->count >= MAX_USER) {
        return REPO_FULL;
    }
    if(userExisted(repo, user)) {
        return REPO_DUPLICATE;
    }
    user->userId = repo->nextId++;
    repo->user[repo->count++] = user;
    return REPO_OK;
}

RepoStatus repo_deleteUser(UserRepository* repo, int userId){
    if(repo->count ==0){
        return REPO_EMPTY;
    }
    for(int i=0;i<repo->count;i++){
        if(repo->user[i]->userId == userId) {

            freeUser(repo->user[i]);

            for(int j=i;j<repo->count-1;j++){
                repo->user[j] = repo->user[j+1];
            }
            repo->count--;
            return REPO_OK;
        }
    }

    return REPO_NOTEXIST;
}

RepoStatus repo_updateUser(UserRepository* repo, User* oldUser, User* newUser){
    if(repo->count == 0) {
        return REPO_EMPTY;
    }
    if(!userExisted(repo,oldUser)) {
        return REPO_NOTEXIST;
    }
    for(int i=0;i<repo->count;i++) {
        if(repo->user[i] == oldUser) {
            repo->user[i] = newUser;
            return REPO_OK;
        }
    }
    return REPO_NOTEXIST;
}

User* findUserById(UserRepository* repo, int userId){
    for(int i=0;i<repo->count;i++){
        if(repo->user[i]->userId == userId) {
            return repo->user[i];
        }
    }
    return NULL;
}

