#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../prototypes/bomb.h"
#include "../prototypes/inventory.h"

void boomDestructibleWall(int *map) {
    srand(time(NULL));
    int lowerLimit = 1, upperLimit = 100;
    int cursor =  lowerLimit + rand() % (upperLimit - lowerLimit);
    if(cursor >= 50) {
        *map = generateRandomItem();
    }
}

void boomPlayer(Game myGame , int *map) {
    switch (*map) {
        case 5 :
            if(myGame.players[0].inventory.invincibility == 0){
                if(myGame.players[0].inventory.heart == 0){
                    myGame.players[0].life -= 1;
                }
                else{
                    myGame.players[0].inventory.heart = 0;
                }
            }
            break;
        case 50:
            if(myGame.players[0].inventory.invincibility == 0){
                if(myGame.players[0].inventory.heart == 0){
                    myGame.players[0].life -= 1;
                }
                else{
                    myGame.players[0].inventory.heart = 0;
                }
            }
            break;
        case 6:
            if(myGame.players[1].inventory.invincibility == 0){
                if(myGame.players[1].inventory.heart == 0){
                    myGame.players[1].life -= 1;
                }
                else{
                    myGame.players[1].inventory.heart = 0;
                }
            }
            break;
        case 60:
<<<<<<< Updated upstream
            myGame.players[0].life -= 1;
=======
            if(myGame.players[1].inventory.invincibility == 0){
                if(myGame.players[1].inventory.heart == 0){
                    myGame.players[1].life -= 1;
                }
                else{
                    myGame.players[1].inventory.heart = 0;
                }
            }
>>>>>>> Stashed changes
            break;
        case 7:
            if(myGame.players[2].inventory.invincibility == 0){
                if(myGame.players[2].inventory.heart == 0){
                    myGame.players[2].life -= 1;
                }
                else{
                    myGame.players[2].inventory.heart = 0;
                }
            }
            break;
        case 70:
<<<<<<< Updated upstream
            myGame.players[0].life -= 1;
=======
            if(myGame.players[2].inventory.invincibility == 0){
                if(myGame.players[2].inventory.heart == 0){
                    myGame.players[2].life -= 1;
                }
                else{
                    myGame.players[2].inventory.heart = 0;
                }
            }
>>>>>>> Stashed changes
            break;
        case 8:
            if(myGame.players[3].inventory.invincibility == 0){
                if(myGame.players[3].inventory.heart == 0){
                    myGame.players[3].life -= 1;
                }
                else{
                    myGame.players[3].inventory.heart = 0;
                }
            }
            break;
        case 80:
<<<<<<< Updated upstream
            myGame.players[0].life -= 1;
=======
            if(myGame.players[3].inventory.invincibility == 0){
                if(myGame.players[3].inventory.heart == 0){
                    myGame.players[3].life -= 1;
                }
                else{
                    myGame.players[3].inventory.heart = 0;
                }
            }
>>>>>>> Stashed changes
            break;
    }
}

void verticalBoom(Game myGame, Bomb myBomb) {
    for (int i = -myBomb.blastRange; i < myBomb.blastRange ; i++) {
        if(myGame.gameMap.map[myBomb.posX+i][myBomb.posY] == 0) {
            break;
        }
        if(myGame.gameMap.map[myBomb.posX+i][myBomb.posY] == 1) {
            boomDestructibleWall(&myGame.gameMap.map[myBomb.posX+i][myBomb.posY]);
        }
        if(myGame.gameMap.map[myBomb.posX+i][myBomb.posY] == 4) {
            for (int j = 0; j < myGame.posedBombCount ; j++) {
                if(myGame.posedBomb[j].posY == myBomb.posY && myGame.posedBomb[j].posX == myBomb.posX+i) {
                    Boom(myGame,myGame.posedBomb[j]);
                }
            }
        }
        if( myGame.gameMap.map[myBomb.posX+i][myBomb.posY] >= 50) {
            boomPlayer(myGame ,&myGame.gameMap.map[myBomb.posX+i][myBomb.posY]);
            for (int j = 0; j < myGame.posedBombCount ; j++) {
                if(myGame.posedBomb[j].posY == myBomb.posY && myGame.posedBomb[j].posX == myBomb.posX+i) {
                    Boom(myGame,myGame.posedBomb[j]);
                }
            }
        }

    }
}

void horizontalBoom(Game myGame, Bomb myBomb) {
    for (int i = -myBomb.blastRange; i < myBomb.blastRange ; i++) {
        if(myGame.gameMap.map[myBomb.posX][myBomb.posY+i] == 0) {
            break;
        }
        if(myGame.gameMap.map[myBomb.posX][myBomb.posY+i] == 1) {
            boomDestructibleWall(&myGame.gameMap.map[myBomb.posX][myBomb.posY+i]);
        }
        if(myGame.gameMap.map[myBomb.posX][myBomb.posY+i] == 4) {
            for (int j = 0; j < myGame.posedBombCount ; j++) {
                if(myGame.posedBomb[j].posY == myBomb.posY+i && myGame.posedBomb[j].posX == myBomb.posX) {
                    Boom(myGame,myGame.posedBomb[j]);
                }
            }
        }
        if( myGame.gameMap.map[myBomb.posX][myBomb.posY+i] >= 50) {
            boomPlayer(myGame ,&myGame.gameMap.map[myBomb.posX][myBomb.posY+i]);
            for (int j = 0; j < myGame.posedBombCount ; j++) {
                if(myGame.posedBomb[j].posY == myBomb.posY+i && myGame.posedBomb[j].posX == myBomb.posX) {
                    Boom(myGame,myGame.posedBomb[j]);
                }
            }
        }

    }
}

void Boom(Game myGame, Bomb myBomb) {
    verticalBoom(myGame, myBomb);
    horizontalBoom(myGame, myBomb);
    //diagonal
}

void makeThemBoom(Game myGame) {
    for (int i = 0; i < myGame.posedBombCount ; i++) {
        if(myGame.posedBomb[i].timer == 0 && myGame.posedBomb[i].isExplode != 1) {
            Boom(myGame,myGame.posedBomb[i]);
            myGame.gameMap.map[myGame.posedBomb[i].posX][myGame.posedBomb[i].posY] = 2;
        }
    }
}