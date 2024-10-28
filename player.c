#include "player.h"
#include <string.h>

//Função para criar um player
Player criarPlayer(char class[], char name[]){
    Player player;
    if(strcmp(class, "mage")){
        player = (Player) {
            .weaponEquipped = "sword",
            .weapons[0] = "sword",
            .itens = {{"healingPotion"}, {"healingPotion"}, {"healingPotion"}, {"healingPotion"},},
            .dodge = 25,
            .life = 30,
            .mana = 0
        };
    }else if(strcmp(class, "warrior")){
        player = (Player) {
            .weaponEquipped = "staff",
            .spellEquipped = "fireBall",
            .weapons[0] = "staff",
            .spells[0] = "fireBall",
            .itens = {{"healingPotion"}, {"healingPotion"}, {"healingPotion"}, {"healingPotion"}, {"manaPotion"}, {"manaPotion"}, {"manaPotion"}, {"manaPotion"}},
            .dodge = 50,
            .life = 15,
            .mana = 10
        };
    }

    strcpy(player.name, name);
    
    return player;
}





