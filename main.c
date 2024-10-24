#include <stdio.h>
#include "utilities.h"

void play(){
    clearScreen();
}

void menu(){
    //Título
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
    scanf("%s", option);
    getchar();

    //Checando opção para dígitos inválidos
    if(checkForLetters(option) || checkForNonStdDigits(option) || strlen(option) > 1){
        printf("Digito Invalido \n");
    }

    //Checando opção escolhida
    switch(option[0])
    {
    case '1':
        printf("Jogar \n");
        break;
    default:
        printf("Digito Invalido \n");
        break;
    }  
}
 
int main(){
    menu();
    play();
    return 0;
}