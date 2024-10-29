#ifndef GAME
#define GAME
#include "character.h"

struct{
    int life;
    int damage;
    int dodge;
}typedef Thug;

struct{
    int life;
    int damage;
    int dodge;
}typedef Demon;

struct{
    int life;
    int damage;
    int dodge;
}typedef KingDemon;


void drawMageVsThug();
void drawWarriorVsThug();
void game(Character character[], int actualCharacter, int *pQtdCharacters);

#endif