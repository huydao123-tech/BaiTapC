#include "inputter.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
int inputInt(const char* prompt, int min, int max) {
    char buffer[1000];
    int value;

    while(1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer),stdin);
        buffer[strcspn(buffer,"\n")] = 0;

        int ok = 1;
        for(int i=0;i<strlen(buffer);i++) {
            if(!isdigit(buffer[i])) {
                ok=0;
                break;
            }
        }
        if(ok==0) {
            printf("Vui long nhap so hop le");
            continue;
        }

        value = atoi(buffer);
        if(value > max || value < min) {
            printf("Gia tri phai tu %d den %d", min, max);
            continue;
        }

    }
    return value;
}



void inputString(const char* prompt, char* buffer) {
    printf("%s", prompt);
    fgets(buffer, INT_MAX, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}

