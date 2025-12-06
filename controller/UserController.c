#include "UserController.h"
#include "../inputter/inputter.h"
#include "../model/user.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void UserController_init(UserController* ctl, UserRepository* repo){
    ctl->repo = repo;
}

void ctl_addUser(UserController* ctl, User* user){
    char name[100];
    inputString("Nhap ten nguoi dung: ", name);
    strcpy(user->name, name);
    user->numberOfBooksBorrowed = 0;
    repo_addUser(ctl->repo, user);
}

User* ctl_createAndAddUser(UserController* ctl){
    char name[100];
    inputString("Nhap ten nguoi dung: ", name);
    User* user = createUser(name, 0); // ID sẽ được set bởi repository
    user->numberOfBooksBorrowed = 0;
    RepoStatus status = repo_addUser(ctl->repo, user);
    if(status != REPO_OK){
        freeUser(user);
        return NULL;
    }
    return user;
}

void ctl_deleteUser(UserController* ctl, int userId){
    repo_deleteUser(ctl->repo, userId);
}

User* ctl_findUser(UserController* ctl, int userId){
    return findUserById(ctl->repo, userId);
}

void ctl_showUserList(UserController* ctl){
    if(ctl->repo->count == 0){
        printf("Danh sach nguoi dung trong!\n");
        return;
    }
    printf("\n=== DANH SACH NGUOI DUNG ===\n");
    for(int i = 0; i < ctl->repo->count; i++){
        printf("ID: %d, Ten: %s, So sach dang muon: %d\n", 
               ctl->repo->user[i]->userId,
               ctl->repo->user[i]->name,
               ctl->repo->user[i]->numberOfBooksBorrowed);
    }
    printf("============================\n\n");
}

void ctl_updateUser(UserController* ctl, User* oldUser, User* newUser){
    repo_updateUser(ctl->repo, oldUser, newUser);
}
