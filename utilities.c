#include "utilities.h"
#include <string.h>
#include <stdlib.h>
#include <errno.h> 
#include <time.h>

int checkForNonStdDigits(char string[]){
    for(int i = 0; i < strlen(string); i++){
        if((string[i] >= 32 && string[i] <= 47) || (string[i] >= 58 && string[i] <= 64) || (string[i] >= 91 && string[i] <= 96) || (string[i] >= 123 && string[i] <= 127)){
            return 1;
        }
    }
    return 0;
}

int checkForLetters(char string[]){
    for(int i = 0; i < strlen(string); i++){
        if((string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122)){
            return 1;
        }
    }
    return 0;
}

int checkForNumbers(char string[]){
    for(int i = 0; i < strlen(string); i++){
        if((string[i] >= 48 && string[i] <= 57)){
            return 1;
        }
    }
    return 0;
}

void clearTerminal(){
    system("cls");
}

int sleep(long msec){
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}