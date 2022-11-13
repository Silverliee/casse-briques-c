#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../prototypes/inventory.h"

void addItem(Player *player, int itemCode) {
    switch (itemCode) {
        case -1:
            player->bombCount += 1;
            printf("Votre nombre de bombes maximum augemente de 1\n");
            break;
        case -2:
            player->bombCount -= 1;
            printf("Votre nombre de bombes maximum diminue de 1\n");
            break;
        case -3:
            player->inventory.yellowFlame += 1;
            printf("la portee de vos bombes augmente de 1\n");
            break;
        case -4:
            player->inventory.blueFlame += 1;
            printf("La portee de vos bombes diminue de 1\n");
            break;
        case -5:
            player->inventory.redFlame += 1;
            printf("La portee de vos bombes est augmentee au maximum\n");
            break;
        case -6:
            if (player->inventory.bombKick == 1 && player->inventory.bombPass == 0) {
                player->inventory.bombKick = 0;
                player->inventory.bombPass = 1;
            } else if (player->inventory.bombPass == 0) {
                player->inventory.bombPass = 1;
            }
            printf("Vous pouvez maintenant passer au travers des bombes\n");
            break;
        case -7:
            if (player->inventory.bombPass == 1 && player->inventory.bombKick == 0) {
                player->inventory.bombPass = 0;
                player->inventory.bombKick = 1;
            } else if (player->inventory.bombKick == 0) {
                player->inventory.bombKick = 1;
            }
            printf("Vous pouvez deplacer les bombes en vous deplacant\n");
            break;
        case -8:
            player->inventory.invincibility = 1;
            printf("Vous devenez invincible pendant 2 tours\n");
            break;
        case -9:
            if(player->inventory.pickHeart == 0){
                player->inventory.heart += 1;
                player->inventory.pickHeart = 1;
            }
            printf("Vous pouvez survivre 1 fois\n");
            break;
        case -10:
            player->inventory.life += 1;
            printf("Vos PV augmente de 1\n");
            break;
        default:
            printf("ItemCode inconnue\n");
            break;
    }
}

int generateRandomItem() {
    int response;
    srand(time(NULL));
    int lowerLimit = 1, upperLimit = 100;
    int cursor =  lowerLimit + rand() % (upperLimit - lowerLimit);
    if (cursor <= 15) {
        response = -1;
    }
    else if (cursor <= 30) {
        response = -2;
    }
    else if (cursor <= 40) {
        response = -3;
    }
    else if (cursor <= 50) {
        response = -4;
    }
    else if (cursor <= 55) {
        response = -5;
    }
    else if (cursor <= 65) {
        response = -6;
    }
    else if (cursor <= 75) {
        response = -7;
    }
    else if (cursor <= 85) {
        response = -8;
    }
    else if (cursor <= 95) {
        response = -9;
    }
    else if (cursor <= 100) {
        response = -10;
    }
    return response ;
}