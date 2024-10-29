#include "character.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

//Função para criar um personagem
Character criarCharacter(char characterClass[], char name[]){
    Character character;
    if(strcmp(characterClass, "warrior") == 0){
        character = (Character) {
            .weaponEquipped = "sword",
            .charClass = "warrior",
            .bonusDamage = 0,
            .dodgeMultiplier = 1,
            .undodgeableAttack = false,
            .battle = 1,
            .money = 0,
            .dodge = 20,
            .life = 30,
            .maxLife = 30
        };
    }else if(strcmp(characterClass, "mage") == 0){
        character = (Character) {
            .weaponEquipped = "staff",
            .charClass = "mage",
            .bonusDamage = 0,
            .dodgeMultiplier = 1,
            .undodgeableAttack = false,
            .battle = 1,
            .money = 0,
            .dodge = 15,
            .life = 15,
            .maxLife = 15
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


