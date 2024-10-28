#include "menu.h"
#include "player.h"
#include "utilities.h"
#include <string.h>
#include <stdio.h>

//Criando o array pra armazenar todos os players
Player players[10];

//Função para iniciar o jogo
void play(){
    clearTerminal();
    //Pegando infos
    printf("Digite seu nome: ");
    char name[50];
    fgets(name, 50, stdin);
    name[strlen(name)-1] = '\0';

    //Seleção de personagem
    printf("Muito bem %s!!! Agora selecione a sua classe (Digite o numero correspondente): \n\n", name);

    printf("       /|               \n");
    printf("      | |               \n");
    printf("      | |               \n");
    printf("   ( )|_|       ( )-O-  \n");
    printf("  --|--|       --|--|   \n");
    printf("    |  |         |  |   \n");
    printf("   / \\          / \\ | \n");
    printf("1.GUERREIRO    2.MAGO   \n\n");

    printf("Selecione uma opcao: ");
    char class[10];
    fgets(class, 10, stdin);
    class[strlen(class)-1] = '\0';

    //Checando opção para dígitos inválidos
    if(checkForLetters(class) || checkForNonStdDigits(class) || strlen(class) > 1){
        printf("Digito Invalido \n");
        sleep(2000);
        return;
    }

    //Checando opção escolhida
    switch(class[0])
    {
    case '1':
        printf("Voce escolheu Guerreiro, seus status e itens sao: \n\n");
        printf("Vida: 30   Esquiva: 25    \n");
        printf("Itens: 4x Pocao de Vida;  \n");
        printf("Armas: Espada             \n");

        //Inicializando player novo
        players[0] = criarPlayer("warrior", name);
        sleep(10000);
        break;
    case '2':
        printf("Voce escolheu Mago, seus status e itens sao: \n\n");
        printf("Vida: 15   Esquiva: 50   Mana: 10\n");
        printf("Itens:  4x Pocao de Vida; \n");
        printf("        4x Pocao de Mana; \n");
        printf("Armas:  Cajado;           \n");
        printf("Magias: Bola de Fogo      \n");

        //Inicializando player novo
        players[0] = criarPlayer("mage", name);
        sleep(10000);
        break;
    default:
        printf("Digito Invalido \n");
        break;
    }  
}

//Função para o menu inicial
void menu(){
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
        play();
        break;
    default:
        printf("Digito Invalido \n");
        sleep(2000);
        return;
        break;
    }  
}