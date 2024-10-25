#ifndef UTILITIES
#define UTILITIES
#include <string.h>
#include <stdlib.h>
#include <errno.h> 
#include <time.h>

int checkForNonStdDigits(char string[]);
int checkForLetters(char string[]);
int checkForNumbers(char string[]);
void clearTerminal();
int sleep(long msec);

#endif 