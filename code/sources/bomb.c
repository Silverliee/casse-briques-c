#include <stdio.h>
<<<<<<< HEAD
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
            myGame.players[0].life -= 1;
            break;
        case 50:
            myGame.players[0].life -= 1;
            break;
        case 6:
            myGame.players[1].life -= 1;
            break;
        case 60:
            myGame.players[0].life -= 1;
            break;
        case 7:
            myGame.players[2].life -= 1;
            break;
        case 70:
            myGame.players[0].life -= 1;
            break;
        case 8:
            myGame.players[3].life -= 1;
            break;
        case 80:
            myGame.players[0].life -= 1;
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
=======
#include "../prototypes/bomb.h"

void verifBoom(Game mygGame){
    //for(in)
>>>>>>> 81d18fd (encore)
}