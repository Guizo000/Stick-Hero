#include "character.h"
#include "game.h"
#include "utilities.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void drawMageVsThug(){
    printf("                          \n");
    printf("                          \n");
    printf("                 (  )     \n");
    printf("    ( )-O-     ---||---   \n");
    printf("   --|--|         ||      \n");
    printf("     |  |         /\\     \n");
    printf("    / \\ |        /  \\   \n");

}

void drawWarriorVsThug(){
    printf("       /|                 \n");
    printf("      | |                 \n");
    printf("      | |        (  )     \n");
    printf("   ( )|_|      ---||---   \n");
    printf("  --|--|          ||      \n");
    printf("    |  |          /\\     \n");
    printf("   / \\           /  \\   \n");

}

void game(Character character[], int actualCharacter){  
    char option[10];
    char weapon[50];
    int randNumber;
    bool triedDodge;
    if(character[actualCharacter].battle == 1){
        clearTerminal();
        printf("\n\n\n");
        printf("       ------------------  \n");
        printf("      | PRIMEIRA BATALHA | \n");
        printf("       ------------------  \n");
        sleep(2000);
        Thug thug = {
            .life = 15,
            .damage = 5,
            .dodge = 20
        };
        while(thug.life > 0 && character[actualCharacter].life > 0){
            clearTerminal();
            character[actualCharacter].dodgeMultiplier = 1;
            if(strcmp(character[actualCharacter].charClass, "mage") == 0){
                drawMageVsThug();
            }else{
                drawWarriorVsThug();
            }
            printf("LIFE: %d        LIFE: %d\n\n", character[actualCharacter].life, thug.life);
            printf("1.ATAQUE\n");
            printf("2.DEFESA\n\n");
            printf("Digite sua opcao: ");
            fgets(option, 10, stdin);
            option[strlen(option)-1] = '\0';

            if(checkForLetters(option) || checkForNonStdDigits(option) || strlen(option) > 1){
                printf("Digito Invalido \n");
                sleep(2000);
                continue;
            }

            switch(option[0]){
            case '1':
                
                strcpy(weapon, character[actualCharacter].weaponEquipped);
                if(strcmp(weapon, "sword") == 0){
                    clearTerminal();
                    drawWarriorVsThug();
                    randNumber = rand() % 100 + 1; 
                    if(randNumber > thug.dodge || character[actualCharacter].undodgeableAttack == true){
                        printf("\nO Ataque acertou em cheio\n");
                        thug.life -= 7;
                    }else{
                        printf("\nVoce errou o ataque\n");
                    }
                    sleep(2000);
                }else if(strcmp(weapon, "staff") == 0){
                    clearTerminal();
                    drawMageVsThug();
                    randNumber = (rand() % 100) + 1; 
                    if(randNumber > thug.dodge || character[actualCharacter].undodgeableAttack == true){
                        printf("\nA bola de fogo acerta em cheio\n");
                        thug.life -= 12;
                    }else{
                        printf("\nVoce errou o ataque\n");
                    }
                    sleep(2000);
                }
                character[actualCharacter].undodgeableAttack = false;
                break;
            case '2':
                character[actualCharacter].dodgeMultiplier = 2;
                triedDodge = true;
                break;
            default:
                printf("Digito Invalido \n");
                sleep(2000);
                break;
            }

            clearTerminal();
            if(strcmp(character[actualCharacter].charClass, "mage") == 0){
                drawMageVsThug();
            }else{
                drawWarriorVsThug();
            }
            printf("\nO Inimigo tenta te atacar\n");
            randNumber = (rand() % 100) + 1; 
            sleep(2000);
            if(randNumber > character[actualCharacter].dodge * character[actualCharacter].dodgeMultiplier){
                character[actualCharacter].life -= thug.damage;
                printf("Ele te acerta em cheio\n");
                sleep(2000);
            }else{
                printf("Voce consegue desviar\n");
                if(triedDodge){character[actualCharacter].undodgeableAttack = true;}
                sleep(2000);
            }
            
        }

        clearTerminal();
        if(character[actualCharacter].life <= 0){
            printf("\n\n\n");
            printf("       --------------  \n");
            printf("      | VOCE PERDDEU | \n");
            printf("       --------------  \n");
            sleep(2000);
            return;
        }else{
            printf("\n\n\n");
            printf("       -------------  \n");
            printf("      | VOCE GANHOU | \n");
            printf("       -------------  \n");
            sleep(2000);  
        }
        
    }
}
    