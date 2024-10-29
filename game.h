#ifndef GAME
#define GAME
#include "character.h"

struct{
    int life;
    int damage;
    int dodge;
}typedef Thug;

void drawMageVsThug();
void drawWarriorVsThug();
void game(Character character[], int actualCharacter);

#endif