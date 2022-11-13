#include <stdio.h>
#include "../prototypes/player.h"
#include "../prototypes/inventory.h"

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
            //déplacement à travers trou dans le bord de la map
            if(playerPosX == 0){
                if(myGame.gameMap.map[playerPosX][playerPosY]/10 == playerPosCode){
                    myGame.gameMap.map[playerPosX][playerPosY] = 4;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY] = 2;
                }
                myGame.gameMap.map[myGame.gameMap.row-1][playerPosY] = playerPosCode;
            }
            //déplacemetn impossible
            else if (myGame.gameMap.map[playerPosX - 1][playerPosY] == 0
            || myGame.gameMap.map[playerPosX - 1][playerPosY] == 1
            || (myGame.gameMap.map[playerPosX - 1][playerPosY] == 4 
            && myGame.players[myGame.WhoPlay-1].inventory.bombPass == 0)
            || myGame.gameMap.map[playerPosX - 1][playerPosY] > 4
            ) {
                printf("Deplacement impossible\nVeuillez selectionner une autre direction\n");
                printf("- 1: Haut\n- 2: Bas\n- 3: Gauche\n- 4: Droite\n");
                scanf("%d", &direction);
                movement(myGame, direction);
            } 
            //déplacement OK
            else {
                if(myGame.gameMap.map[playerPosX][playerPosY]/10 == playerPosCode){
                    myGame.gameMap.map[playerPosX][playerPosY] = 4;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY] = 2;
                }
                if(myGame.gameMap.map[playerPosX - 1][playerPosY] < 0){
                    addItem(&myGame.players[myGame.WhoPlay-1], myGame.gameMap.map[playerPosX - 1][playerPosY]);
                }
                if(myGame.gameMap.map[playerPosX - 1][playerPosY] == 4){
                    myGame.gameMap.map[playerPosX - 1][playerPosY] = playerPosCode*10;
                }
                else{
                    myGame.gameMap.map[playerPosX - 1][playerPosY] = playerPosCode;
                }
            }
             break;
        //bas
        case 2:
        if(playerPosX == myGame.gameMap.row-1){
                if(myGame.gameMap.map[playerPosX][playerPosY]/10 == playerPosCode){
                    myGame.gameMap.map[playerPosX][playerPosY] = 4;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY] = 2;
                }
                myGame.gameMap.map[0][playerPosY] = playerPosCode;
            }
            else if (myGame.gameMap.map[playerPosX + 1][playerPosY] == 0
                || myGame.gameMap.map[playerPosX + 1][playerPosY] == 1
                || (myGame.gameMap.map[playerPosX + 1][playerPosY] == 4
                && myGame.players[myGame.WhoPlay-1].inventory.bombPass == 0)
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

                if(myGame.gameMap.map[playerPosX + 1][playerPosY] < 0){
                    addItem(&myGame.players[myGame.WhoPlay-1], myGame.gameMap.map[playerPosX + 1][playerPosY]);
                }
                if(myGame.gameMap.map[playerPosX + 1][playerPosY] == 4){
                    myGame.gameMap.map[playerPosX + 1][playerPosY] = playerPosCode*10;
                }
                else{
                    myGame.gameMap.map[playerPosX + 1][playerPosY] = playerPosCode;
                }
            }
            break;
        //Gauche
        case 3:
            if(playerPosY == 0){
                if(myGame.gameMap.map[playerPosX][playerPosY]/10 == playerPosCode){
                    myGame.gameMap.map[playerPosX][playerPosY] = 4;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY] = 2;
                }
                myGame.gameMap.map[playerPosX][myGame.gameMap.column-1] = playerPosCode;
            }
            else if (myGame.gameMap.map[playerPosX][playerPosY - 1] == 0
                || myGame.gameMap.map[playerPosX][playerPosY - 1] == 1
                || (myGame.gameMap.map[playerPosX][playerPosY - 1] == 4
                && myGame.players[myGame.WhoPlay-1].inventory.bombPass == 0)
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

                if(myGame.gameMap.map[playerPosX][playerPosY - 1] < 0){
                    addItem(&myGame.players[myGame.WhoPlay-1], myGame.gameMap.map[playerPosX][playerPosY - 1]);
                }
                if(myGame.gameMap.map[playerPosX][playerPosY - 1] == 4){
                    myGame.gameMap.map[playerPosX][playerPosY - 1] = playerPosCode*10;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY - 1] = playerPosCode;
                }
            }
            break;
        //Droite
        case 4:
            if(playerPosY == myGame.gameMap.column-1){
                if(myGame.gameMap.map[playerPosX][playerPosY]/10 == playerPosCode){
                    myGame.gameMap.map[playerPosX][playerPosY] = 4;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY] = 2;
                }
                myGame.gameMap.map[playerPosX][0] = playerPosCode;
            }
            else if (myGame.gameMap.map[playerPosX][playerPosY + 1] == 0
                || myGame.gameMap.map[playerPosX][playerPosY + 1] == 1
                || (myGame.gameMap.map[playerPosX][playerPosY + 1] == 4
                && myGame.players[myGame.WhoPlay-1].inventory.bombPass == 0)
                || myGame.gameMap.map[playerPosX ][playerPosY + 1] > 4
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

                if(myGame.gameMap.map[playerPosX][playerPosY + 1] < 0){
                    addItem(&myGame.players[myGame.WhoPlay-1], myGame.gameMap.map[playerPosX][playerPosY + 1]);
                }
                if(myGame.gameMap.map[playerPosX][playerPosY + 1] == 4){
                    myGame.gameMap.map[playerPosX][playerPosY + 1] = playerPosCode*10;
                }
                else{
                    myGame.gameMap.map[playerPosX][playerPosY + 1] = playerPosCode;
                }
            }
            break;
    }
}

void dropBomb(Game *myGame, Player *player) {
    //set keyVariables
    int playerPosX,playerPosY;
    int playerPosCode = myGame->WhoPlay + 4;
    int playerBombRange;
    if (player->inventory.redFlame == 1) {
        playerBombRange = 7;
    } else {
        playerBombRange = (2 + player->inventory.yellowFlame) - player->inventory.blueFlame;
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
    if( player->bombCount == 0) {
        printf("Il ne vous reste plus de bombe :/\n");
        return;
    }

    //creation of the bomb
    Bomb newBomb;
    newBomb.timer = 3;
    newBomb.blastRange = playerBombRange;
    newBomb.owner = myGame->WhoPlay;
    newBomb.posX = playerPosX;
    newBomb.posY = playerPosY;
    newBomb.isExplode = 0;

    //finalise
    myGame->posedBomb[myGame->posedBombCount] = newBomb;
    myGame->posedBombCount++;
    myGame->gameMap.map[playerPosX][playerPosY] = playerPosCode*10;
    player->bombCount--;

}

void isDead(Game *myGame){
    for(int i = 0; i < myGame->playerCount; i++){
        if(myGame->players[i].life <= 0){
            for(int k = 0; k < myGame->gameMap.row; k++){
                for(int l = 0; l < myGame->gameMap.column; l++){
                    if(myGame->gameMap.map[k][l] - 5 == i || (myGame->gameMap.map[k][l]/10) - 5 == i){
                        myGame->gameMap.map[k][l] = 2;
                    }
                }
            }
        }
    }
}