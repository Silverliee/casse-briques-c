#include <stdio.h>
#include "../prototypes/map.h"

void printMap(Game myGame) {
    for (int i = 0; i < myGame.gameMap.row; i++) {
        for (int j = 0; j < myGame.gameMap.column; j++) {
            if (myGame.gameMap.map[i][j] == 0) {
                printf("x");
            }
            else if (myGame.gameMap.map[i][j] == 1) {
                printf("m");
            }
            else if (myGame.gameMap.map[i][j] == 2) {
                printf(" ");
            }
            else if (myGame.gameMap.map[i][j] == 3) {
                printf(" ");
            }
            /*else if (myGame.gameMap.map[i][j] == 4) {
                printf(".");
            }*/
            else if (myGame.gameMap.map[i][j] > 3 && myGame.gameMap.map[i][j] < 10) {
                int playerNumb;
                switch (myGame.gameMap.map[i][j]) {
                    case 4:
                        playerNumb = 1;
                        break;
                    case 5:
                        playerNumb = 2;
                        break;
                    case 6:
                        playerNumb = 3;
                        break;
                    case 7:
                        playerNumb = 4;
                        break;
                    default:
                        break;
                }
                printf("%d",playerNumb);
            }
            else if (myGame.gameMap.map[i][j] <= 10) {
                printf("Po");
            }

        }
        printf("\n");
    }
}