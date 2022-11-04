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
            || myGame.gameMap.map[playerPosX - 1][playerPosY] == 4
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
                myGame.gameMap.map[playerPosX - 1][playerPosY] = playerPosCode;
            }
             break;
        //bas
        case 2:
            if (myGame.gameMap.map[playerPosX + 1][playerPosY] == 0
                || myGame.gameMap.map[playerPosX + 1][playerPosY] == 1
                || myGame.gameMap.map[playerPosX + 1][playerPosY] == 4
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
                myGame.gameMap.map[playerPosX + 1][playerPosY] = playerPosCode;
            }
            break;
        //Gauche
        case 3:
            if (myGame.gameMap.map[playerPosX][playerPosY - 1] == 0
                || myGame.gameMap.map[playerPosX][playerPosY - 1] == 1
                || myGame.gameMap.map[playerPosX][playerPosY - 1] == 4
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
                myGame.gameMap.map[playerPosX][playerPosY - 1] = playerPosCode;
            }
            break;
        //Droite
        case 4:
            if (myGame.gameMap.map[playerPosX][playerPosY + 1] == 0
                || myGame.gameMap.map[playerPosX][playerPosY + 1] == 1
                || myGame.gameMap.map[playerPosX][playerPosY + 1] == 4
                || myGame.gameMap.map[playerPosX][playerPosY + 1] > 4
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
                myGame.gameMap.map[playerPosX][playerPosY + 1] = playerPosCode;
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

    //finalise
    myGame->posedBomb[myGame->posedBombCount] = newBomb;
    myGame->posedBombCount++;
    myGame->gameMap.map[playerPosX][playerPosY] = playerPosCode*10;

}