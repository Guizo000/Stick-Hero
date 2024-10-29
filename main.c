#include "menu.h"
#include "game.h"
#include "character.h"
#include "utilities.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0)); 
    //Inicializando os valores da listaPlayers
    ListaCharacters listaCharacters;
    listaCharacters.qtdCharacters = 0;
    int *pQtdCharacters = &listaCharacters.qtdCharacters;
    listaCharacters.actualCharacter = 0;
    int *pActualCharacter = &listaCharacters.actualCharacter;
    
    //Váriaveis para controle de fluxo no menu
    bool goToPlay = false;
    bool *pGoToPlay = &goToPlay;

    bool goToGame = false;
    bool *pGoToGame = &goToGame;

    //Atualizando a lita de players para ser usada durante o prrograma
    listaCharacters = txtToCharacterArray(listaCharacters, sizeof(listaCharacters.characters)/sizeof(listaCharacters.characters[0])); 

    while(true){
        menu(pGoToPlay);
        if(goToPlay){ play(listaCharacters.characters, pQtdCharacters, pActualCharacter, pGoToGame); }
        listaCharacters = txtToCharacterArray(listaCharacters, sizeof(listaCharacters.characters)/sizeof(listaCharacters.characters[0]));
        if(goToGame){ game(listaCharacters.characters, listaCharacters.actualCharacter); }
        listaCharacters = txtToCharacterArray(listaCharacters, sizeof(listaCharacters.characters)/sizeof(listaCharacters.characters[0]));
    } 
    return 0;
}