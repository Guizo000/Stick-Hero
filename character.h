#ifndef CHARACTER
#define CHARACTER

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