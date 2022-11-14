#include <stdio.h>
#include "../prototypes/player.h"

void movement(Game myGame, int direction) {
    int playerPosX,playerPosY;
    int playerPosCode = myGame.WhoPlay + 4;
    for (int i = 0; i < myGame.gameMap.row; i++) {
        for (int j = 0; j < myGame.gameMap.column; j++) {
            if(myGame.gameMap.map[i][j] == playerPosCode || myGame.gameMap.map[i][j]/10 == playerPosCode) {
                playerPosX = i;
                playerPosY = j;
            }
        }
    }
    switch (direction) {
        //Haut
        case 1:
            if (myGame.gameMap.map[playerPosX - 1][playerPosY] == 0
            || myGame.gameMap.map[playerPosX - 1][playerPosY] == 1
<<<<<<< Updated upstream
            || myGame.gameMap.map[playerPosX - 1][playerPosY] == 4
=======
            || (myGame.gameMap.map[playerPosX - 1][playerPosY] == 4 
            && myGame.players[myGame.WhoPlay-1].inventory.bombPass == 0
            && myGame.players[myGame.WhoPlay-1].inventory.bombKick == 0)
            || (myGame.gameMap.map[playerPosX - 1][playerPosY] == 4
            && myGame.gameMap.map[playerPosX - 2][playerPosY] != 2
            && myGame.players[myGame.WhoPlay-1].inventory.bombKick == 1)
>>>>>>> Stashed changes
            || myGame.gameMap.map[playerPosX - 1][playerPosY] > 4
            ) {
                printf("Deplacement impossible\nVeuillez selectionner une autre direction\n");
                printf("- 1: Haut\n- 2: Bas\n- 3: Gauche\n- 4: Droite\n");
                scanf("%d", &direction);
                movement(myGame, direction);
            } else {
                if(myGame.gameMap.map[playerPosX][playerPosY]/10 == playerPosCode){
                    myGame.gameMap.map[playerPosX][playerPosY] = 4;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY] = 2;
                }
<<<<<<< Updated upstream
                myGame.gameMap.map[playerPosX - 1][playerPosY] = playerPosCode;
=======
                if(myGame.gameMap.map[playerPosX - 1][playerPosY] < 0){
                    addItem(&myGame.players[myGame.WhoPlay-1], myGame.gameMap.map[playerPosX - 1][playerPosY]);
                }
                if(myGame.gameMap.map[playerPosX - 1][playerPosY] == 4){
                    if(myGame.players[myGame.WhoPlay-1].inventory.bombPass == 1){
                        myGame.gameMap.map[playerPosX - 1][playerPosY] = playerPosCode*10;
                    }
                    else if (myGame.players[myGame.WhoPlay-1].inventory.bombKick == 1){
                        int distance = 2;
                        while(myGame.gameMap.map[playerPosX - distance][playerPosY] == 2){
                            distance++;
                        }
                        myGame.gameMap.map[playerPosX - distance - 1][playerPosY] = 4;
                        myGame.gameMap.map[playerPosX - 1][playerPosY] = playerPosCode;
                    }
                }
                else{
                    myGame.gameMap.map[playerPosX - 1][playerPosY] = playerPosCode;
                }
>>>>>>> Stashed changes
            }
             break;
        //bas
        case 2:
            if (myGame.gameMap.map[playerPosX + 1][playerPosY] == 0
                || myGame.gameMap.map[playerPosX + 1][playerPosY] == 1
<<<<<<< Updated upstream
                || myGame.gameMap.map[playerPosX + 1][playerPosY] == 4
=======
                || (myGame.gameMap.map[playerPosX + 1][playerPosY] == 4
                && myGame.players[myGame.WhoPlay-1].inventory.bombPass == 0
                && myGame.players[myGame.WhoPlay-1].inventory.bombKick == 0)
                || (myGame.gameMap.map[playerPosX + 1][playerPosY] == 4
                && myGame.gameMap.map[playerPosX + 2][playerPosY] != 2
                && myGame.players[myGame.WhoPlay-1].inventory.bombKick == 1)
>>>>>>> Stashed changes
                || myGame.gameMap.map[playerPosX + 1][playerPosY] > 4
                    ) {
                printf("Deplacement impossible\nVeuillez selectionner une autre direction\n");
                printf("- 1: Haut\n- 2: Bas\n- 3: Gauche\n- 4: Droite\n");
                scanf("%d", &direction);
                movement(myGame, direction);
            } else {
                if(myGame.gameMap.map[playerPosX][playerPosY]/10 == playerPosCode){
                    myGame.gameMap.map[playerPosX][playerPosY] = 4;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY] = 2;
                }
<<<<<<< Updated upstream
                myGame.gameMap.map[playerPosX + 1][playerPosY] = playerPosCode;
=======

                if(myGame.gameMap.map[playerPosX + 1][playerPosY] < 0){
                    addItem(&myGame.players[myGame.WhoPlay-1], myGame.gameMap.map[playerPosX + 1][playerPosY]);
                }
                if(myGame.gameMap.map[playerPosX + 1][playerPosY] == 4){
                    if(myGame.players[myGame.WhoPlay-1].inventory.bombPass == 1){
                        myGame.gameMap.map[playerPosX + 1][playerPosY] = playerPosCode*10;
                    }
                    else if (myGame.players[myGame.WhoPlay-1].inventory.bombKick == 1){
                        int distance = 2;
                        while(myGame.gameMap.map[playerPosX + distance][playerPosY] == 2){
                            distance++;
                        }
                        myGame.gameMap.map[playerPosX + distance - 1][playerPosY] = 4;
                        myGame.gameMap.map[playerPosX + 1][playerPosY] = playerPosCode;
                    }
                }
                else{
                    myGame.gameMap.map[playerPosX + 1][playerPosY] = playerPosCode;
                }
>>>>>>> Stashed changes
            }
            break;
        //Gauche
        case 3:
            if (myGame.gameMap.map[playerPosX][playerPosY - 1] == 0
                || myGame.gameMap.map[playerPosX][playerPosY - 1] == 1
<<<<<<< Updated upstream
                || myGame.gameMap.map[playerPosX][playerPosY - 1] == 4
=======
                || (myGame.gameMap.map[playerPosX][playerPosY - 1] == 4
                && myGame.players[myGame.WhoPlay-1].inventory.bombPass == 0
                && myGame.players[myGame.WhoPlay-1].inventory.bombKick == 0)
                || (myGame.gameMap.map[playerPosX][playerPosY - 2] == 4
                && myGame.gameMap.map[playerPosX][playerPosY - 2] != 2
                && myGame.players[myGame.WhoPlay-1].inventory.bombKick == 1)
>>>>>>> Stashed changes
                || myGame.gameMap.map[playerPosX][playerPosY - 1] > 4
                    ) {
                printf("Deplacement impossible\nVeuillez selectionner une autre direction\n");
                printf("- 1: Haut\n- 2: Bas\n- 3: Gauche\n- 4: Droite\n");
                scanf("%d", &direction);
                movement(myGame, direction);
            } else {
                if(myGame.gameMap.map[playerPosX][playerPosY]/10 == playerPosCode){
                    myGame.gameMap.map[playerPosX][playerPosY] = 4;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY] = 2;
                }
<<<<<<< Updated upstream
                myGame.gameMap.map[playerPosX][playerPosY - 1] = playerPosCode;
=======

                if(myGame.gameMap.map[playerPosX][playerPosY - 1] < 0){
                    addItem(&myGame.players[myGame.WhoPlay-1], myGame.gameMap.map[playerPosX][playerPosY - 1]);
                }
                if(myGame.gameMap.map[playerPosX][playerPosY - 1] == 4){
                    if(myGame.players[myGame.WhoPlay-1].inventory.bombPass == 1){
                        myGame.gameMap.map[playerPosX][playerPosY - 1] = playerPosCode*10;
                    }
                    else if (myGame.players[myGame.WhoPlay-1].inventory.bombKick == 1){
                        int distance = 2;
                        while(myGame.gameMap.map[playerPosX][playerPosY - distance] == 2){
                            distance++;
                        }
                        myGame.gameMap.map[playerPosX][playerPosY - distance - 1] = 4;
                        myGame.gameMap.map[playerPosX][playerPosY - 1] = playerPosCode;
                    }
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY - 1] = playerPosCode;
                }
>>>>>>> Stashed changes
            }
            break;
        //Droite
        case 4:
            if (myGame.gameMap.map[playerPosX][playerPosY + 1] == 0
                || myGame.gameMap.map[playerPosX][playerPosY + 1] == 1
<<<<<<< Updated upstream
                || myGame.gameMap.map[playerPosX][playerPosY + 1] == 4
                || myGame.gameMap.map[playerPosX][playerPosY + 1] > 4
=======
                || (myGame.gameMap.map[playerPosX][playerPosY + 1] == 4
                && myGame.players[myGame.WhoPlay-1].inventory.bombPass == 0
                && myGame.players[myGame.WhoPlay-1].inventory.bombKick == 0)
                || (myGame.gameMap.map[playerPosX][playerPosY + 1] == 4
                && myGame.gameMap.map[playerPosX][playerPosY + 2] != 2
                && myGame.players[myGame.WhoPlay-1].inventory.bombKick == 1)
                || myGame.gameMap.map[playerPosX ][playerPosY + 1] > 4
>>>>>>> Stashed changes
                    ) {
                printf("Deplacement impossible\nVeuillez selectionner une autre direction\n");
                printf("- 1: Haut\n- 2: Bas\n- 3: Gauche\n- 4: Droite\n");
                scanf("%d", &direction);
                movement(myGame, direction);
            } else {
                if(myGame.gameMap.map[playerPosX][playerPosY]/10 == playerPosCode){
                    myGame.gameMap.map[playerPosX][playerPosY] = 4;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY] = 2;
                }
<<<<<<< Updated upstream
                myGame.gameMap.map[playerPosX][playerPosY + 1] = playerPosCode;
=======

                if(myGame.gameMap.map[playerPosX][playerPosY + 1] < 0){
                    addItem(&myGame.players[myGame.WhoPlay-1], myGame.gameMap.map[playerPosX][playerPosY + 1]);
                }
                if(myGame.gameMap.map[playerPosX][playerPosY + 1] == 4){
                    if(myGame.players[myGame.WhoPlay-1].inventory.bombPass == 1){
                        myGame.gameMap.map[playerPosX][playerPosY + 1] = playerPosCode*10;
                    }
                    else if (myGame.players[myGame.WhoPlay-1].inventory.bombKick == 1){
                        int distance = 2;
                        while(myGame.gameMap.map[playerPosX][playerPosY + distance] == 2){
                            distance++;
                        }
                        myGame.gameMap.map[playerPosX][playerPosY + distance - 1] = 4;
                        myGame.gameMap.map[playerPosX][playerPosY + 1] = playerPosCode;
                    }
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY + 1] = playerPosCode;
                }
>>>>>>> Stashed changes
            }
            break;
    }
}

void dropBomb(Game *myGame, Player player) {
    //set keyVariables
    int playerPosX,playerPosY;
    int playerPosCode = myGame->WhoPlay + 4;
    int playerRemainingBomb = (player.bombCount + player.inventory.bombUp) - player.inventory.bombDown;
    int playerBombRange;
    if (player.inventory.redFlame == 1) {
        playerBombRange = 7;
    } else {
        playerBombRange = (2 + player.inventory.yellowFlame) - player.inventory.blueFlame;
    }
    for (int i = 0; i < myGame->gameMap.row; i++) {
        for (int j = 0; j < myGame->gameMap.column; j++) {
            if(myGame->gameMap.map[i][j] == playerPosCode) {
                playerPosX = i;
                playerPosY = j;
            }
        }
    }

    // invalide situation management condition
    if( playerRemainingBomb <= 0) {
        printf("Il ne vous reste plus de bombe :/\n");
        return;
    }

    //creation of the bomb
    Bomb newBomb;
    newBomb.timer = 2;
    newBomb.blastRange = playerBombRange;
    newBomb.owner = player;
    newBomb.posX = playerPosX;
    newBomb.posY = playerPosY;
    newBomb.isExplode = 0;

    //finalise
    myGame->posedBomb[myGame->posedBombCount] = newBomb;
    myGame->posedBombCount++;
    myGame->gameMap.map[playerPosX][playerPosY] = playerPosCode*10;

}