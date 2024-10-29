#include "character.h"
#include "game.h"
#include "utilities.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Primeira Batalha
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


//Segunda Batalha
void drawMageVsDemon(){
    printf("                  / /     \n");
    printf("                 (  )/  / \n");
    printf("                  ||/ /   \n");
    printf("    ( )-O-     ---||/---  \n");
    printf("   --|--|         ||      \n");
    printf("     |  |         /\\     \n");
    printf("    / \\ |        /  \\   \n");

}

void drawWarriorVsDemon(){
    printf("       /|         / /     \n");
    printf("      | |        (  )/  / \n");
    printf("      | |         ||/ /   \n");
    printf("   ( )|_|      ---||/---  \n");
    printf("  --|--|          ||      \n");
    printf("    |  |          /\\     \n");
    printf("   / \\           /  \\   \n");

}

//Terceira Batalha
void drawMageVsKingDemon(){
    printf("                  / /     \n");
    printf("                 (  )/  / \n");
    printf("                  ||/ /   \n");
    printf("    ( )-O-     ---||/---  \n");
    printf("   --|--|         ||      \n");
    printf("     |  |         /\\     \n");
    printf("    / \\ |        /  \\   \n");

}

void drawWarriorVsKingDemon(){
    printf("                 |\\/|    \n");
    printf("       /|   ()() (-- )    \n");
    printf("      | |   ()()  ||  /  /\n");
    printf("      | |     |   ||/ /   \n");
    printf("   ( )|_|     |---||/---  \n");
    printf("  --|--|      |   ||      \n");
    printf("    |  |    ()()  /\\     \n");
    printf("   / \\      ()() /  \\   \n");
}

//Game
void game(Character character[], int actualCharacter, int *pQtdCharacters){  
    char option[10];
    char weapon[50];
    int randNumber;
    bool triedDodge;

    //BATALHA 1
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
            .dodge = 10
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
                        thug.life -= 7 + character[actualCharacter].bonusDamage;
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
                        thug.life -= 12 + character[actualCharacter].bonusDamage;
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
                continue;
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


        //POS BATALHA
        clearTerminal();
        if(character[actualCharacter].life <= 0){
            printf("\n\n\n");
            printf("       ---------------  \n");
            printf("      |  VOCE PERDEU  | \n");
            printf("       ---------------  \n");
            sleep(2000);
            return;
        }else{
            while(true){
                printf("\n\n\n");
                printf("       -------------  \n");
                printf("      | VOCE GANHOU | \n");
                printf("       -------------  \n");
                printf("     +30 Pecas de ouro\n");
                printf("      Vida Restaurada \n");
                sleep(2000);  
                clearTerminal();
                printf("Escolha uma melhoria por 30 de ouro:\n");
                printf("Ouro Atual: %d\n", character[actualCharacter].money);
                printf("1. +5 Dano Bonus\n");
                printf("2. +5 Esquiva\n");
                printf("3. +20 Vida Maxima\n");
                printf("Selecione uma opcao: ");
                char upgrade[10];
                fgets(upgrade, 10, stdin);
                upgrade[strlen(upgrade)-1] = '\0';

                //Checando opção para dígitos inválidos
                if(checkForLetters(upgrade) || checkForNonStdDigits(upgrade) || strlen(upgrade) > 1){
                    printf("Digito Invalido \n");
                    sleep(2000);
                    continue;
                }

                if(upgrade[0] == '1'){ character[actualCharacter].bonusDamage += 5; }
                else if(upgrade[0] == '2'){ character[actualCharacter].dodge += 5; }
                else if(upgrade[0] == '3'){ character[actualCharacter].maxLife += 20; }
                character[actualCharacter].life = character[actualCharacter].maxLife;
                character[actualCharacter].battle = 2;
                characterArrayToTxt(character, pQtdCharacters);
                break;
            }
            
        }
        
    }





    //BATALHA 2
    if(character[actualCharacter].battle == 2){
        clearTerminal();
        printf("\n\n\n");
        printf("       ------------------  \n");
        printf("      | SEGUNDA BATALHA | \n");
        printf("       ------------------  \n");
        sleep(2000);
        Demon demon = {
            .life = 30,
            .damage = 8,
            .dodge = 20
        };
        while(demon.life > 0 && character[actualCharacter].life > 0){
            clearTerminal();
            character[actualCharacter].dodgeMultiplier = 1;
            if(strcmp(character[actualCharacter].charClass, "mage") == 0){
                drawMageVsDemon();
            }else{
                drawWarriorVsDemon();
            }
            printf("LIFE: %d        LIFE: %d\n\n", character[actualCharacter].life, demon.life);
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
                    drawWarriorVsDemon();
                    randNumber = rand() % 100 + 1; 
                    if(randNumber > demon.dodge || character[actualCharacter].undodgeableAttack == true){
                        printf("\nO Ataque acertou em cheio\n");
                        demon.life -= 7 + character[actualCharacter].bonusDamage;
                    }else{
                        printf("\nVoce errou o ataque\n");
                    }
                    sleep(2000);
                }else if(strcmp(weapon, "staff") == 0){
                    clearTerminal();
                    drawMageVsDemon();
                    randNumber = (rand() % 100) + 1; 
                    if(randNumber > demon.dodge || character[actualCharacter].undodgeableAttack == true){
                        printf("\nA bola de fogo acerta em cheio\n");
                        demon.life -= 12 + character[actualCharacter].bonusDamage;
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
                continue;
                break;
            }

            clearTerminal();
            if(strcmp(character[actualCharacter].charClass, "mage") == 0){
                drawMageVsDemon();
            }else{
                drawWarriorVsDemon();
            }
            printf("\nO Inimigo tenta te atacar\n");
            randNumber = (rand() % 100) + 1; 
            sleep(2000);
            if(randNumber > character[actualCharacter].dodge * character[actualCharacter].dodgeMultiplier){
                character[actualCharacter].life -= demon.damage;
                printf("Ele te acerta em cheio\n");
                sleep(2000);
            }else{
                printf("Voce consegue desviar\n");
                if(triedDodge){character[actualCharacter].undodgeableAttack = true;}
                sleep(2000);
            }
            
        }


        //POS BATALHA
        clearTerminal();
        if(character[actualCharacter].life <= 0){
            printf("\n\n\n");
            printf("       ---------------  \n");
            printf("      |  VOCE PERDEU  | \n");
            printf("       ---------------  \n");
            sleep(2000);
            return;
        }else{
            while(true){
                printf("\n\n\n");
                printf("       -------------  \n");
                printf("      | VOCE GANHOU | \n");
                printf("       -------------  \n");
                printf("     +30 Pecas de ouro\n");
                printf("      Vida Restaurada \n");
                sleep(2000);  
                clearTerminal();
                printf("Escolha uma melhoria por 30 de ouro:\n");
                printf("Ouro Atual: %d\n", character[actualCharacter].money);
                printf("1. +10 Dano Bonus\n");
                printf("2. +10 Esquiva\n");
                printf("3. +30 Vida Maxima\n");
                printf("Selecione uma opcao: ");
                char upgrade[10];
                fgets(upgrade, 10, stdin);
                upgrade[strlen(upgrade)-1] = '\0';

                //Checando opção para dígitos inválidos
                if(checkForLetters(upgrade) || checkForNonStdDigits(upgrade) || strlen(upgrade) > 1){
                    printf("Digito Invalido \n");
                    sleep(2000);
                    continue;
                }

                if(upgrade[0] == '1'){ character[actualCharacter].bonusDamage += 10; }
                else if(upgrade[0] == '2'){ character[actualCharacter].dodgeMultiplier += 10; }
                else if(upgrade[0] == '3'){ character[actualCharacter].maxLife += 30; }
                character[actualCharacter].life = character[actualCharacter].maxLife;
                character[actualCharacter].battle = 3;
                characterArrayToTxt(character, pQtdCharacters);
                break;
            }
            
        }
        
    }



    //BATALHA 3
    if(character[actualCharacter].battle == 2){
        clearTerminal();
        printf("\n\n\n");
        printf("       ------------------  \n");
        printf("      |  ULTIMA BATALHA  | \n");
        printf("       ------------------  \n");
        sleep(2000);
        KingDemon kingDemon = {
            .life = 50,
            .damage = 12,
            .dodge = 30
        };
        while(kingDemon.life > 0 && character[actualCharacter].life > 0){
            clearTerminal();
            character[actualCharacter].dodgeMultiplier = 1;
            if(strcmp(character[actualCharacter].charClass, "mage") == 0){
                drawMageVsKingDemon();
            }else{
                drawWarriorVsKingDemon();
            }
            printf("LIFE: %d        LIFE: %d\n\n", character[actualCharacter].life, kingDemon.life);
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
                    drawWarriorVsKingDemon();
                    randNumber = rand() % 100 + 1; 
                    if(randNumber > kingDemon.dodge || character[actualCharacter].undodgeableAttack == true){
                        printf("\nO Ataque acertou em cheio\n");
                        kingDemon.life -= 7 + character[actualCharacter].bonusDamage;
                    }else{
                        printf("\nVoce errou o ataque\n");
                    }
                    sleep(2000);
                }else if(strcmp(weapon, "staff") == 0){
                    clearTerminal();
                    drawMageVsKingDemon();
                    randNumber = (rand() % 100) + 1; 
                    if(randNumber > kingDemon.dodge || character[actualCharacter].undodgeableAttack == true){
                        printf("\nA bola de fogo acerta em cheio\n");
                        kingDemon.life -= 12 + character[actualCharacter].bonusDamage;
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
                continue;
                break;
            }

            clearTerminal();
            if(strcmp(character[actualCharacter].charClass, "mage") == 0){
                drawMageVsKingDemon();
            }else{
                drawWarriorVsKingDemon();
            }
            printf("\nO Inimigo tenta te atacar\n");
            randNumber = (rand() % 100) + 1; 
            sleep(2000);
            if(randNumber > character[actualCharacter].dodge * character[actualCharacter].dodgeMultiplier){
                character[actualCharacter].life -= kingDemon.damage;
                printf("Ele te acerta em cheio\n");
                sleep(2000);
            }else{
                printf("Voce consegue desviar\n");
                if(triedDodge){character[actualCharacter].undodgeableAttack = true;}
                sleep(2000);
            }
            
        }


        //POS BATALHA
        clearTerminal();
        if(character[actualCharacter].life <= 0){
            printf("\n\n\n");
            printf("       ---------------  \n");
            printf("      |  VOCE PERDEU  | \n");
            printf("       ---------------  \n");
            sleep(2000);
            return;
        }else{
            while(true){
                printf("\n\n\n");
                printf("       -------------  \n");
                printf("      | VOCE GANHOU | \n");
                printf("       -------------  \n");
                printf("      Parabens!!!!!!! \n");
                printf("     Voce zerou o jogo\n");
                sleep(2000);  
                clearTerminal();
                character[actualCharacter].life = character[actualCharacter].maxLife;
                character[actualCharacter].battle = 3;
                characterArrayToTxt(character, pQtdCharacters);
                break;
            }
            
        }
        
    }

}
    