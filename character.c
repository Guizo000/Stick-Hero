#include "character.h"
#include <string.h>
#include <stdio.h>

//Função para criar um personagem
Character criarCharacter(char characterClass[], char name[]){
    Character character;
    if(strcmp(characterClass, "mage")){
        character = (Character) {
            .weaponEquipped = "sword",
            .weapons[0] = "sword",
            .itens = {{"healingPotion"}, {"healingPotion"}, {"healingPotion"}, {"healingPotion"},},
            .dodge = 25,
            .life = 30,
            .mana = 0
        };
    }else if(strcmp(characterClass, "warrior")){
        character = (Character) {
            .weaponEquipped = "staff",
            .spellEquipped = "fireBall",
            .weapons[0] = "staff",
            .spells[0] = "fireBall",
            .itens = {{"healingPotion"}, {"healingPotion"}, {"healingPotion"}, {"healingPotion"}, {"manaPotion"}, {"manaPotion"}, {"manaPotion"}, {"manaPotion"}},
            .dodge = 50,
            .life = 15,
            .mana = 10
        };
    }

    strcpy(character.name, name);
    
    return character;
}

ListaCharacters txtToCharacterArray(ListaCharacters listaCharacters, int charactersLen){
    FILE *file;
    file = fopen("character.txt", "rb");
    if (file != NULL){
        fread(listaCharacters.characters, sizeof(listaCharacters.characters[0]) *  charactersLen, 1, file);
        for(int i = 0; i < charactersLen; i++){
            if(strlen(listaCharacters.characters[i].name) == 0){
                break;
            }else{
                listaCharacters.qtdCharacters += 1;
            }
        }
    }
    return listaCharacters;
}

void characterArrayToTxt(Character characters[], int *pQtdCharacters){
    FILE* file;
    file = fopen("character.txt", "wb");
    fwrite(characters, sizeof(characters[0]) * *pQtdCharacters, 1, file);
    fclose(file);
}


