#ifndef CHARACTER
#define CHARACTER
#include <stdbool.h>
//Structs
struct{
    char weaponEquipped[50];
    char name[50];
    char charClass[50];
    int bonusDamage;
    int dodgeMultiplier;
    bool undodgeableAttack;
    int battle;
    int money;
    int dodge;
    int life;
    int maxLife;
}typedef Character;

//Lista de characters
struct{
    Character characters[10];
    int qtdCharacters;
    int actualCharacter;
}typedef ListaCharacters;

//Funções
Character criarCharacter(char characterClass[], char name[]);
ListaCharacters txtToCharacterArray(ListaCharacters listaCharacters, int charactersLen);
void characterArrayToTxt(Character characters[], int *pQtdCharacters);

#endif 