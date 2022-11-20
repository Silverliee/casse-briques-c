#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../prototypes/bomb.h"
#include "../prototypes/inventory.h"

void boomDestructibleWall(int *map) {
    srand(time(NULL));
    int lowerLimit = 1, upperLimit = 100;
    int cursor = lowerLimit + rand() % (upperLimit - lowerLimit);
    if (cursor >= 50) {
        *map = generateRandomItem();
    } else {
        *map = 2;
    }
}

void boomPlayer(Game myGame, int *map) {
    switch (*map) {
        case 5 :
            if (myGame.players[0].inventory.invincibility == 0) {
                if (myGame.players[0].inventory.heart == 0) {
                    myGame.players[0].life -= 1;
                } else {
                    myGame.players[0].inventory.heart = 0;
                }
            }
            break;
        case 50:
            if (myGame.players[0].inventory.invincibility == 0) {
                if (myGame.players[0].inventory.heart == 0) {
                    myGame.players[0].life -= 1;
                } else {
                    myGame.players[0].inventory.heart = 0;
                }
            }
            break;
        case 6:
            if (myGame.players[1].inventory.invincibility == 0) {
                if (myGame.players[1].inventory.heart == 0) {
                    myGame.players[1].life -= 1;
                } else {
                    myGame.players[1].inventory.heart = 0;
                }
            }
            break;
        case 60:
            if (myGame.players[1].inventory.invincibility == 0) {
                if (myGame.players[1].inventory.heart == 0) {
                    myGame.players[1].life -= 1;
                } else {
                    myGame.players[1].inventory.heart = 0;
                }
            }
            break;
        case 7:
            if (myGame.players[2].inventory.invincibility == 0) {
                if (myGame.players[2].inventory.heart == 0) {
                    myGame.players[2].life -= 1;
                } else {
                    myGame.players[2].inventory.heart = 0;
                }
            }
            break;
        case 70:
            if (myGame.players[2].inventory.invincibility == 0) {
                if (myGame.players[2].inventory.heart == 0) {
                    myGame.players[2].life -= 1;
                } else {
                    myGame.players[2].inventory.heart = 0;
                }
            }
            break;
        case 8:
            if (myGame.players[3].inventory.invincibility == 0) {
                if (myGame.players[3].inventory.heart == 0) {
                    myGame.players[3].life -= 1;
                } else {
                    myGame.players[3].inventory.heart = 0;
                }
            }
            break;
        case 80:
            if (myGame.players[3].inventory.invincibility == 0) {
                if (myGame.players[3].inventory.heart == 0) {
                    myGame.players[3].life -= 1;
                } else {
                    myGame.players[3].inventory.heart = 0;
                }
            }
            break;
    }
}

void verticalBoom(Game myGame, Bomb myBomb) {
    //vers le bas
    for (int i = 1; i < myBomb.blastRange + 1; i++) {
        //rencontre de murs destructibles
        if (myGame.gameMap.map[myBomb.posX + i][myBomb.posY] == 1) {
            boomDestructibleWall(&myGame.gameMap.map[myBomb.posX + i][myBomb.posY]);
            break;
        }

        //rencontre de bombe
        if (myGame.gameMap.map[myBomb.posX + i][myBomb.posY] == 4) {
            for (int j = 0; j < myGame.posedBombCount; j++) {
                if (myGame.posedBomb[j].posX == myBomb.posX + i && myGame.posedBomb[j].posY == myBomb.posY) {
                    Boom(myGame, myGame.posedBomb[j]);
                }
            }
        }

        //rencontre de joueurs
        if (myGame.gameMap.map[myBomb.posX + i][myBomb.posY] > 4) {
            boomPlayer(myGame, &myGame.gameMap.map[myBomb.posX + i][myBomb.posY]);
        }

        //fin de l'explosion si mur indestructible
        if (myGame.gameMap.map[myBomb.posX + i][myBomb.posY] == 0) {
            break;
        }

        //rencontre de cases vides
        if (myGame.gameMap.map[myBomb.posX + i][myBomb.posY] == 2) {
            continue;
        }
    }

    //vers le haut
    for (int i = 1; i < myBomb.blastRange + 1; i++) {
        //rencontre de murs destructibles
        if (myGame.gameMap.map[myBomb.posX - i][myBomb.posY] == 1) {
            boomDestructibleWall(&myGame.gameMap.map[myBomb.posX - i][myBomb.posY]);
            break;
        }

        //rencontre de bombe
        if (myGame.gameMap.map[myBomb.posX - i][myBomb.posY] == 4) {
            for (int j = 0; j < myGame.posedBombCount; j++) {
                if (myGame.posedBomb[j].posX == myBomb.posX - i && myGame.posedBomb[j].posY == myBomb.posY) {
                    Boom(myGame, myGame.posedBomb[j]);
                }
            }
        }

        //rencontre de joueurs
        if (myGame.gameMap.map[myBomb.posX - i][myBomb.posY] > 4) {
            boomPlayer(myGame, &myGame.gameMap.map[myBomb.posX - i][myBomb.posY]);
        }

        //fin de l'explosion si mur indestructible
        if (myGame.gameMap.map[myBomb.posX - i][myBomb.posY] == 0) {
            break;
        }

        //rencontre de cases vides
        if (myGame.gameMap.map[myBomb.posX - i][myBomb.posY] == 2) {
            continue;
        }
    }
}

void horizontalBoom(Game myGame, Bomb myBomb) {
    //vers la droite
    for (int i = 1; i < myBomb.blastRange + 1; i++) {
        //rencontre de murs destructibles
        if (myGame.gameMap.map[myBomb.posX][myBomb.posY + i] == 1) {
            boomDestructibleWall(&myGame.gameMap.map[myBomb.posX][myBomb.posY + i]);
            break;
        }

        //rencontre de bombe
        if (myGame.gameMap.map[myBomb.posX][myBomb.posY + i] == 4) {
            for (int j = 0; j < myGame.posedBombCount; j++) {
                if (myGame.posedBomb[j].posX == myBomb.posX && myGame.posedBomb[j].posY == myBomb.posY + i) {
                    Boom(myGame, myGame.posedBomb[j]);
                }
            }
        }

        //rencontre de joueurs
        if (myGame.gameMap.map[myBomb.posX][myBomb.posY + i] > 4) {
            boomPlayer(myGame, &myGame.gameMap.map[myBomb.posX][myBomb.posY + i]);
        }

        //fin de l'explosion si mur indestructible
        if (myGame.gameMap.map[myBomb.posX][myBomb.posY + i] == 0) {
            break;
        }

        //rencontre de cases vides
        if (myGame.gameMap.map[myBomb.posX][myBomb.posY + i] == 2) {
            continue;
        }
    }

    //vers la gauche
    for (int i = 1; i <= myBomb.blastRange; i++) {
        //rencontre de murs destructibles
        if (myGame.gameMap.map[myBomb.posX][myBomb.posY - i] == 1) {
            boomDestructibleWall(&myGame.gameMap.map[myBomb.posX][myBomb.posY - i]);
            break;
        }

        //rencontre de bombe
        if (myGame.gameMap.map[myBomb.posX][myBomb.posY - i] == 4) {
            for (int j = 0; j < myGame.posedBombCount; j++) {
                if (myGame.posedBomb[j].posX == myBomb.posX && myGame.posedBomb[j].posY == myBomb.posY - i) {
                    Boom(myGame, myGame.posedBomb[j]);
                }
            }
        }

        //rencontre de joueurs
        if (myGame.gameMap.map[myBomb.posX][myBomb.posY - i] > 4) {
            boomPlayer(myGame, &myGame.gameMap.map[myBomb.posX][myBomb.posY - i]);
        }

        //fin de l'explosion si mur indestructible
        if (myGame.gameMap.map[myBomb.posX][myBomb.posY - i] == 0) {
            break;
        }

        //rencontre de cases vides
        if (myGame.gameMap.map[myBomb.posX][myBomb.posY - i] == 2) {
            continue;
        }
    }
}

void Boom(Game myGame, Bomb myBomb) {
    verticalBoom(myGame, myBomb);
    horizontalBoom(myGame, myBomb);
    for (int i = 0; i < myGame.posedBombCount; i++) {
        if (myGame.posedBomb[i].posX == myBomb.posX && myGame.posedBomb[i].posY == myBomb.posY) {
            myGame.posedBomb[i].isExplode = 1;
        }
    }
}

void makeThemBoom(Game myGame) {
    for (int i = 0; i < myGame.posedBombCount; i++) {
        if (myGame.posedBomb[i].timer == 0 && myGame.posedBomb[i].isExplode != 1) {
            Boom(myGame, myGame.posedBomb[i]);
            myGame.players[myGame.posedBomb[i].owner - 1].bombCount++;
            myGame.gameMap.map[myGame.posedBomb[i].posX][myGame.posedBomb[i].posY] = 2;
        } else if (myGame.posedBomb[i].owner == myGame.WhoPlay) {
            myGame.posedBomb[i].timer--;
        }
    }
}