#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../prototypes/inventory.h"

void addItem(Player player, int itemCode) {
    switch (itemCode) {
        case -1:
            player.inventory.bombUp += 1;
            break;
        case -2:
            player.inventory.bombDown += 1;
            break;
        case -3:
            player.inventory.yellowFlame += 1;
            break;
        case -4:
            player.inventory.blueFlame += 1;
            break;
        case -5:
            player.inventory.redFlame += 1;
            break;
        case -6:
            if (player.inventory.bombKick == 1 && player.inventory.bombPass == 0) {
                player.inventory.bombKick = 0;
                player.inventory.bombPass = 1;
            } else if (player.inventory.bombPass == 0) {
                player.inventory.bombPass = 1;
            }
            break;
        case -7:
            if (player.inventory.bombPass == 1 && player.inventory.bombKick == 0) {
                player.inventory.bombPass = 0;
                player.inventory.bombKick = 1;
            } else if (player.inventory.bombKick == 0) {
                player.inventory.bombKick = 1;
            }
            break;
        case -8:
<<<<<<< Updated upstream
            player.inventory.invincibility = 1;
=======
            player->inventory.invincibility = 1;
            player->inventory.invincibleTimer = 3;
            printf("Vous devenez invincible pendant 2 tours\n");
>>>>>>> Stashed changes
            break;
        case -9:
            player.inventory.heart += 1;
            break;
        case -10:
            player.inventory.life += 1;
            break;
        default:
            printf("ItemCode inconnue");
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
    else if (cursor <= 43) {
        response = -4;
    }
    else if (cursor <= 50) {
        response = -5;
    }
    else if (cursor <= 60) {
        response = -6;
    }
    else if (cursor <= 70) {
        response = -7;
    }
    else if (cursor <= 80) {
        response = -8;
    }
    else if (cursor <= 90) {
        response = -9;
    }
    else if (cursor <= 100) {
        response = -10;
    }
    return response ;
}