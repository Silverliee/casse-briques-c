#include <time.h>
#include <stdlib.h>
#include "../prototypes/bot.h"
#include "../prototypes/inventory.h"

void botMovement(Game myGame) {
    //var initialisation
    int moveDirection;
    int botPosX, botPosY;
    int botPosCode = myGame.WhoPlay + 4;
    //find bot actual coord
    for (int i = 0; i < myGame.gameMap.row; i++) {
        for (int j = 0; j < myGame.gameMap.column; j++) {
            if (myGame.gameMap.map[i][j] == botPosCode || myGame.gameMap.map[i][j] / 10 == botPosCode) {
                botPosX = i;
                botPosY = j;
            }
        }
    }
    //define randomly direction
    srand(time(NULL));
    moveDirection = 1 + rand() % (1 - 4);
    //handle movement
    switch (moveDirection) {
        //Up
        case 1:
            if (myGame.gameMap.map[botPosX - 1][botPosY] == 0
                || myGame.gameMap.map[botPosX - 1][botPosY] == 1
                || (myGame.gameMap.map[botPosX - 1][botPosY] == 4
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombPass == 0
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 0)
                || (myGame.gameMap.map[botPosX - 1][botPosY] == 4
                    && myGame.gameMap.map[botPosX - 2][botPosY] != 2
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 1)
                || myGame.gameMap.map[botPosX - 1][botPosY] > 4
                    ) {
                botMovement(myGame);
            } else {
                if (myGame.gameMap.map[botPosX][botPosY] / 10 == botPosCode) {
                    myGame.gameMap.map[botPosX][botPosY] = 4;
                } else {
                    myGame.gameMap.map[botPosX][botPosY] = 2;
                }
                if (myGame.gameMap.map[botPosX - 1][botPosY] < 0) {
                    addItem(&myGame.players[myGame.WhoPlay - 1], myGame.gameMap.map[botPosX - 1][botPosY]);
                }
                if (myGame.gameMap.map[botPosX - 1][botPosY] == 4) {
                    if (myGame.players[myGame.WhoPlay - 1].inventory.bombPass == 1) {
                        myGame.gameMap.map[botPosX - 1][botPosY] = botPosCode * 10;
                    } else if (myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 1) {
                        int distance = 2;
                        while (myGame.gameMap.map[botPosX - distance][botPosY] == 2) {
                            distance++;
                        }
                        for (int i = 0; i < myGame.posedBombCount; i++) {
                            if (myGame.posedBomb[i].posX == botPosX - 1 && myGame.posedBomb[i].posY == botPosY) {
                                myGame.posedBomb[i].posX = botPosX - distance - 1;
                            }
                        }
                        myGame.gameMap.map[botPosX - distance - 1][botPosY] = 4;
                        myGame.gameMap.map[botPosX - 1][botPosY] = botPosCode;
                    }
                } else {
                    myGame.gameMap.map[botPosX - 1][botPosY] = botPosCode;
                }
            }
            break;
            //Down
        case 2:
            if (myGame.gameMap.map[botPosX + 1][botPosY] == 0
                || myGame.gameMap.map[botPosX + 1][botPosY] == 1
                || (myGame.gameMap.map[botPosX + 1][botPosY] == 4
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombPass == 0
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 0)
                || (myGame.gameMap.map[botPosX + 1][botPosY] == 4
                    && myGame.gameMap.map[botPosX + 2][botPosY] != 2
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 1)
                || myGame.gameMap.map[botPosX + 1][botPosY] > 4
                    ) {
                botMovement(myGame);
            } else {
                if (myGame.gameMap.map[botPosX][botPosY] / 10 == botPosCode) {
                    myGame.gameMap.map[botPosX][botPosY] = 4;
                } else {
                    myGame.gameMap.map[botPosX][botPosY] = 2;
                }
                if (myGame.gameMap.map[botPosX + 1][botPosY] < 0) {
                    addItem(&myGame.players[myGame.WhoPlay - 1], myGame.gameMap.map[botPosX + 1][botPosY]);
                }
                if (myGame.gameMap.map[botPosX + 1][botPosY] == 4) {
                    if (myGame.players[myGame.WhoPlay - 1].inventory.bombPass == 1) {
                        myGame.gameMap.map[botPosX + 1][botPosY] = botPosCode * 10;
                    } else if (myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 1) {
                        int distance = 2;
                        while (myGame.gameMap.map[botPosX + distance][botPosY] == 2) {
                            distance++;
                        }
                        for (int i = 0; i < myGame.posedBombCount; i++) {
                            if (myGame.posedBomb[i].posX == botPosX + 1 && myGame.posedBomb[i].posY == botPosY) {
                                myGame.posedBomb[i].posX = botPosX + distance - 1;
                            }
                        }
                        myGame.gameMap.map[botPosX + distance - 1][botPosY] = 4;
                        myGame.gameMap.map[botPosX + 1][botPosY] = botPosCode;
                    }
                } else {
                    myGame.gameMap.map[botPosX + 1][botPosY] = botPosCode;
                }
            }
            break;
            //Left
        case 3:
            if (myGame.gameMap.map[botPosX][botPosY - 1] == 0
                || myGame.gameMap.map[botPosX][botPosY - 1] == 1
                || (myGame.gameMap.map[botPosX][botPosY - 1] == 4
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombPass == 0
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 0)
                || (myGame.gameMap.map[botPosX][botPosY - 2] == 4
                    && myGame.gameMap.map[botPosX][botPosY - 2] != 2
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 1)
                || myGame.gameMap.map[botPosX][botPosY - 1] > 4
                    ) {
                botMovement(myGame);
            } else {
                if (myGame.gameMap.map[botPosX][botPosY] / 10 == botPosCode) {
                    myGame.gameMap.map[botPosX][botPosY] = 4;
                } else {
                    myGame.gameMap.map[botPosX][botPosY] = 2;
                }
                if (myGame.gameMap.map[botPosX][botPosY - 1] < 0) {
                    addItem(&myGame.players[myGame.WhoPlay - 1], myGame.gameMap.map[botPosX][botPosY - 1]);
                }
                if (myGame.gameMap.map[botPosX][botPosY - 1] == 4) {
                    if (myGame.players[myGame.WhoPlay - 1].inventory.bombPass == 1) {
                        myGame.gameMap.map[botPosX][botPosY - 1] = botPosCode * 10;
                    } else if (myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 1) {
                        int distance = 2;
                        while (myGame.gameMap.map[botPosX][botPosY - distance] == 2) {
                            distance++;
                        }
                        for (int i = 0; i < myGame.posedBombCount; i++) {
                            if (myGame.posedBomb[i].posX == botPosX && myGame.posedBomb[i].posY == botPosY - 1) {
                                myGame.posedBomb[i].posY = botPosY - distance - 1;
                            }
                        }
                        myGame.gameMap.map[botPosX][botPosY - distance - 1] = 4;
                        myGame.gameMap.map[botPosX][botPosY - 1] = botPosCode;
                    }
                } else {
                    myGame.gameMap.map[botPosX][botPosY - 1] = botPosCode;
                }
            }
            break;
            //Right
        case 4:
            if (myGame.gameMap.map[botPosX][botPosY + 1] == 0
                || myGame.gameMap.map[botPosX][botPosY + 1] == 1
                || (myGame.gameMap.map[botPosX][botPosY + 1] == 4
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombPass == 0
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 0)
                || (myGame.gameMap.map[botPosX][botPosY + 1] == 4
                    && myGame.gameMap.map[botPosX][botPosY + 2] != 2
                    && myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 1)
                || myGame.gameMap.map[botPosX][botPosY + 1] > 4
                    ) {
                botMovement(myGame);
            } else {
                if (myGame.gameMap.map[botPosX][botPosY] / 10 == botPosCode) {
                    myGame.gameMap.map[botPosX][botPosY] = 4;
                } else {
                    myGame.gameMap.map[botPosX][botPosY] = 2;
                }
                if (myGame.gameMap.map[botPosX][botPosY + 1] < 0) {
                    addItem(&myGame.players[myGame.WhoPlay - 1], myGame.gameMap.map[botPosX][botPosY + 1]);
                }
                if (myGame.gameMap.map[botPosX][botPosY + 1] == 4) {
                    if (myGame.players[myGame.WhoPlay - 1].inventory.bombPass == 1) {
                        myGame.gameMap.map[botPosX][botPosY + 1] = botPosCode * 10;
                    } else if (myGame.players[myGame.WhoPlay - 1].inventory.bombKick == 1) {
                        int distance = 2;
                        while (myGame.gameMap.map[botPosX][botPosY + distance] == 2) {
                            distance++;
                        }
                        for (int i = 0; i < myGame.posedBombCount; i++) {
                            if (myGame.posedBomb[i].posX == botPosX && myGame.posedBomb[i].posY == botPosY + 1) {
                                myGame.posedBomb[i].posY = botPosY + distance - 1;
                            }
                        }
                        myGame.gameMap.map[botPosX][botPosY + distance - 1] = 4;
                        myGame.gameMap.map[botPosX][botPosY + 1] = botPosCode;
                    }
                } else {
                    myGame.gameMap.map[botPosX][botPosY + 1] = botPosCode;
                }
            }
            break;
    }
}