#include "menu.h"
#include "character.h"
#include "utilities.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void drawTitle(){
    printf("  ___  _____      _____  |  /     |    |   ____   ____     _____      \n");
    printf(" |       |    |  |       | /      |    |  |      |    \\   /     \\   \n");
    printf(" |___    |    |  |       |/       |____|  |____  |____/  |       |    \n"); 
    printf("     |   |    |  |       | \\      |    |  |      |    \\  |       |  \n");   
    printf("  ___|   |    |  |_____  |  \\     |    |  |____  |     \\  \\_____/  \n\n");
}
//Função para iniciar o jogo
void play(Character characters[], int *pQtdCharacters, int *pActualCharacter, bool *pGoToGame){
    clearTerminal();
    printf("\n");
    drawTitle();
    
    //Opções
    printf("       ---------------                     ---------------           \n");
    printf("      |  1.NOVO JOGO  |                   |  2.CONTINUAR  |          \n");
    printf("       ---------------                     ---------------           \n\n");

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

    if(option[0] == '1'){
        //Pegando infos
        clearTerminal();
        printf("Digite o nome do seu personagem: ");
        char characterName[50];
        fgets(characterName, 50, stdin);
        characterName[strlen(characterName)-1] = '\0';

        //Checando se o nome é valido ou se ja existe
        if(strlen(characterName) == 0){ 
            printf("Nome Invalido \n");
            *pGoToGame = false;
            sleep(2000);
            return;
        }

        for(int i = 0; i < *pQtdCharacters; i++){
            if(strcmp(characters[i].name, characterName) == 0){
                printf("Personagem com esse nome ja existente \n");
                sleep(2000);
                return;
            }
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
            *pGoToGame = false;
            sleep(2000);
            return;
        }

        //Checando opção escolhida
        switch(characterClass[0])
        {
        case '1':
            printf("Voce escolheu Guerreiro, seus status e itens sao: \n\n");
            printf("Vida: 30   Esquiva: 25    \n");
            printf("Armas: Espada - Dano: 7   \n");
            printf("Pecas de Ouro: 0         \n");

            //Inicializando player novo
            if(*pQtdCharacters >= 10){
                printf("Quantidade maxima de saves atingida \n");
                *pGoToGame = false;
                sleep(2000);
                return;
            }

            characters[*pQtdCharacters] = criarCharacter("warrior", characterName);
            *pActualCharacter = *pQtdCharacters;
            *pQtdCharacters += 1;
            characterArrayToTxt(characters, pQtdCharacters);
            *pGoToGame = true;
            sleep(2000);

            break;
        case '2':
            printf("Voce escolheu Mago, seus status e itens sao: \n\n");
            printf("Vida: 15   Esquiva: 20       \n");
            printf("Armas: Cajado;               \n");
            printf("Magia: Bola de Fogo - Dano: 12\n");
            printf("Pecas de Ouro: 30            \n");

            //Inicializando player novo
            characters[*pQtdCharacters] = criarCharacter("mage", characterName);
            *pActualCharacter = *pQtdCharacters;
            *pQtdCharacters += 1;
            characterArrayToTxt(characters, pQtdCharacters);
            *pGoToGame = true;
            sleep(2000);

            break;
        default:
            printf("Digito Invalido \n");
            *pGoToGame = false;
            sleep(2000);
            break;
        }  
    }else if(option[0] == '2'){
        //Obtendo nome do personagem salvo
        printf("Digite o nome do seu personagem salvo: ");
        char name[50];
        fgets(name, 50, stdin);
        name[strlen(name)-1] = '\0';

        //Checando se o nome a ser procurado é válido
        if(strlen(name) == 0){ 
            printf("Nome Invalido \n");
            *pGoToGame = false;
            sleep(2000);
            return;
        }

        //Procurando pelo personagem
        for(int i = 0; i < *pQtdCharacters; i++){
            if(strcmp(characters[i].name, name) == 0){
                *pActualCharacter = i;
                *pGoToGame = true;
                printf("Personagem Encontrado\n");
                sleep(2000);
                return;
            }
        }

        //Caso não seja encontrado
        printf("Personagem nao foi encontrado\n");
        sleep(2000);
        return;
    }else{
        printf("Digito Invalido \n");
        *pGoToGame = false;
        sleep(2000);
        return;
    }
    
}

//Função para o menu inicial
void menu(bool *pGoToPlay){
    //Título
    clearTerminal();
    printf("\n");
    drawTitle();
    
    //Opções
    printf("       ------------                     -------------------            \n");
    printf("      |  1.JOGAR   |                   |  2.SOBRE O JOGO   |           \n");
    printf("       ------------                     -------------------            \n\n");

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
    case '2':
        clearTerminal();
        printf("\n");
        drawTitle();
        //Sobre o jogo
        printf("Stick Hero é um jogo de batalha em turnos baseado em texto e ASCII\n");
        printf("Para finalizar, voce deve derrotar 3 inimigos em seguida\n");
        printf("Durante a batalha, voce tera duas opcoes, atacar ou defender\n");
        printf("Ao atacar voce tentara desferir um golpe, porem o inimigo pode desviar\n");
        printf("Ao defender voce dobrara as suas chances de desviar,\n");
        printf("e caso voce consiga desviar, seu proximo golpe sera indisviavel\n");
        printf("Alem disso entre as batalhas, voce podera escolher um upgrade pro seu personagem\n");
        printf("O Jogo salva seu progresso entre batalhas\n");
        sleep(10000);
        break;
    default:
        printf("Digito Invalido \n");
        sleep(2000);
        return;
        break;
    }  
}