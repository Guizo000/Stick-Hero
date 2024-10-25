#include <stdio.h>
#include "utilities.h"

void play(){
    clearTerminal();
    //Pegando infos
    printf("Digite seu nome: ");
    char name[50];
    fgets(name, 50, stdin);
    name[strlen(name)-1] = '\0';

    //Seleção de personagem
    printf("Muito bem %s!!! Agora selecione o seu personagem (Digite o numero correspondente): \n\n", name);

    printf("       /|               \n");
    printf("      | |               \n");
    printf("      | |               \n");
    printf("   ( )|_|       ( )-O-  \n");
    printf("  --|--|       --|--|   \n");
    printf("    |  |         |  |   \n");
    printf("   / \\          / \\ | \n");
    printf("1.GUERREIRO    2.MAGO   \n\n");

    printf("Selecione uma opcao: ");
    char character[10];
    fgets(character, 10, stdin);
    character[strlen(character)-1] = '\0';

    //Checando opção para dígitos inválidos
    if(checkForLetters(character) || checkForNonStdDigits(character) || strlen(character) > 1){
        printf("Digito Invalido \n");
        return;
    }

    //Checando opção escolhida
    switch(character[0])
    {
    case '1':
        printf("Voce escolheu Guerreiro, seus status e itens sao: \n\n");
        printf("Vida: 30   Esquiva: 25    \n");
        printf("Itens: 2x Pocao de Vida;  \n");
        printf("       2x Pocao de Forca; \n");
        printf("       1x Espada          \n");
        break;
    case '2':
        printf("Voce escolheu Mago, seus status e itens sao: \n\n");
        printf("Vida: 15   Esquiva: 50    \n");
        printf("Itens: 4x Pocao de Vida;  \n");
        printf("       4x Pocao de Mana;  \n");
        printf("       Magia de  Fogo     \n");
        break;
    default:
        printf("Digito Invalido \n");
        break;
    }  
}

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
 
int main(){
    while(1){
        menu();
    } 
    return 0;
}