#ifndef ERROR_CODE_H
#define ERROR_CODE_H

typedef enum {
    REPO_OK = 1,
    REPO_FULL = 0,
    REPO_DUPLICATE = -1,
    REPO_NOTEXIST = 2,
    REPO_EMPTY = 3,
} RepoStatus;




#endif