#ifndef PLAYER
#define PLAYER

//Structs
struct{
    char weaponEquipped[50];
    char spellEquipped[50];
    char weapons[50][50];
    char spells[50][50];
    char itens[50][50];
    char name[50];
    int dodge;
    int life;
    int mana;
}typedef Player;

//Funções
Player criarPlayer(char class[], char name[]);

#endif 