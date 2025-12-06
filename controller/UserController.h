#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H
#include "../repository/UserRepository.h"

typedef struct{
    UserRepository* repo;
} UserController;

void UserController_init(UserController* ctl, UserRepository* repo);

void ctl_addUser(UserController* ctl, User* user);

User* ctl_createAndAddUser(UserController* ctl);

void ctl_deleteUser(UserController* ctl, int userId);

User* ctl_findUser(UserController* ctl, int userId);

void ctl_showUserList(UserController* ctl);

void ctl_updateUser(UserController* ctl, User* oldUser, User* newUser);

#endif

