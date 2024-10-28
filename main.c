#include "menu.h"
#include "character.h"
#include "utilities.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    //Inicializando os valores da listaPlayers
    ListaCharacters listaCharacters;
    listaCharacters.qtdCharacters = 0;
    int *pQtdCharacters = &listaCharacters.qtdCharacters;
    listaCharacters.actualCharacter = 0;
    int *pActualCharacter = &listaCharacters.actualCharacter;
    
    //Váriaveis para controle de fluxo no menu
    bool goToPlay = false;
    bool *pGoToPlay = &goToPlay;

    //Atualizando a lita de players para ser usada durante o prrograma
    listaCharacters = txtToCharacterArray(listaCharacters, sizeof(listaCharacters.characters)/sizeof(listaCharacters.characters[0])); 

    for(int i = 0; i < listaCharacters.qtdCharacters; i++){
        printf("%s  %s  %s  %d  %d  %d \n", listaCharacters.characters[i].weaponEquipped, listaCharacters.characters[i].spellEquipped, listaCharacters.characters[i].name, listaCharacters.characters[i].life, listaCharacters.characters[i].mana, listaCharacters.characters[i].dodge);
    }
    sleep(2000); 

    while(true){
        menu(pGoToPlay);
        if(goToPlay){ play(listaCharacters.characters, pQtdCharacters, pActualCharacter); }
    } 
    return 0;
}