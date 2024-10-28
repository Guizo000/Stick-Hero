#include "menu.h"
#include "character.h"
#include "utilities.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

//Função para iniciar o jogo
void play(Character characters[], int *pQtdCharacters, int *pActualCharacter){
    clearTerminal();
    //Pegando infos
    printf("Digite o nome do seu personagem: ");
    char characterName[50];
    fgets(characterName, 50, stdin);
    characterName[strlen(characterName)-1] = '\0';

    if(strlen(characterName) == 0){ 
        printf("Digito Invalido");
        sleep(2000);
        return;
    }

    //Seleção de personagem
    printf("Muito bem %s!!! Agora selecione a sua classe (Digite o numero correspondente): \n\n", characterName);
    printf("       /|               \n");
    printf("      | |               \n");
    printf("      | |               \n");
    printf("   ( )|_|       ( )-O-  \n");
    printf("  --|--|       --|--|   \n");
    printf("    |  |         |  |   \n");
    printf("   / \\          / \\ | \n");
    printf("1.GUERREIRO    2.MAGO   \n\n");

    printf("Selecione uma opcao: ");
    char characterClass[10];
    fgets(characterClass, 10, stdin);
    characterClass[strlen(characterClass)-1] = '\0';
    
    //Checando opção para dígitos inválidos
    if(checkForLetters(characterClass) || checkForNonStdDigits(characterClass) || strlen(characterClass) > 1){
        printf("Digito Invalido \n");
        sleep(2000);
        return;
    }

    //Checando opção escolhida
    switch(characterClass[0])
    {
    case '1':
        printf("Voce escolheu Guerreiro, seus status e itens sao: \n\n");
        printf("Vida: 30   Esquiva: 25    \n");
        printf("Itens: 4x Pocao de Vida;  \n");
        printf("Armas: Espada             \n");

        //Inicializando player novo
        if(*pQtdCharacters >= 10){
            printf("Quantidade maxima de saves atingida");
            sleep(2000);
            return;
        }

        characters[*pQtdCharacters] = criarCharacter("warrior", characterName);
        *pQtdCharacters += 1;
        *pActualCharacter = *pQtdCharacters;
        characterArrayToTxt(characters, pQtdCharacters);
        sleep(2000);

        break;
    case '2':
        printf("Voce escolheu Mago, seus status e itens sao: \n\n");
        printf("Vida: 15   Esquiva: 50   Mana: 10\n");
        printf("Itens:  4x Pocao de Vida; \n");
        printf("        4x Pocao de Mana; \n");
        printf("Armas:  Cajado;           \n");
        printf("Magias: Bola de Fogo      \n");

        //Inicializando player novo
        characters[*pQtdCharacters] = criarCharacter("mage", characterName);
        *pQtdCharacters += 1;
        *pActualCharacter = *pQtdCharacters;
        characterArrayToTxt(characters, pQtdCharacters);
        sleep(2000);

        break;
    default:
        printf("Digito Invalido \n");
        sleep(2000);
        break;
    }  
}

//Função para o menu inicial
void menu(bool *pGoToPlay){
    //Título
    clearTerminal();
    printf("\n");
    printf("  ___  _____      _____  |  /     |    |   ____   ____     _____      \n");
    printf(" |       |    |  |       | /      |    |  |      |    \\   /     \\   \n");
    printf(" |___    |    |  |       |/       |____|  |____  |____/  |       |    \n"); 
    printf("     |   |    |  |       | \\      |    |  |      |    \\  |       |  \n");   
    printf("  ___|   |    |  |_____  |  \\     |    |  |____  |     \\  \\_____/  \n\n");

    //Opções
    printf(" ------------  \n");
    printf("|  1.JOGAR   | \n");
    printf(" ------------  \n\n");

    //Selecionar opção
    printf("Selecione uma opcao: ");
    char option[10];
    fgets(option, 10, stdin);
    option[strlen(option)-1] = '\0';

    //Checando opção para dígitos inválidos
    if(checkForLetters(option) || checkForNonStdDigits(option) || strlen(option) > 1){
        printf("Digito Invalido \n");
        sleep(2000);
        return;
    }

    //Checando opção escolhida
    switch(option[0])
    {
    case '1':
        *pGoToPlay = true;
        return;
        break;
    default:
        printf("Digito Invalido \n");
        sleep(2000);
        return;
        break;
    }  
}