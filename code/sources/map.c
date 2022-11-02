#include <stdio.h>
#include "../prototypes/map.h"

void printMap(Game myGame) {
    for (int i = 0; i < myGame.gameMap.row; i++) {
        for (int j = 0; j < myGame.gameMap.column; j++) {
            if (myGame.gameMap.map[i][j] == 0) {
                //x
                printf("%c", 219);
            }
            else if (myGame.gameMap.map[i][j] == 1) {
                //m
                printf("%c", 177);
            }
            else if (myGame.gameMap.map[i][j] == 2) {
                printf(" ");
            }
            else if (myGame.gameMap.map[i][j] == 3) {
                printf(" ");
            }
            else if (myGame.gameMap.map[i][j] == 4) {
                printf("O");
            }
            else if (myGame.gameMap.map[i][j] > 4 && myGame.gameMap.map[i][j] < 10) {

                printf("%d",myGame.gameMap.map[i][j]-4);
            }
            else if (myGame.gameMap.map[i][j] >= 10) {
                printf("%d", (myGame.gameMap.map[i][j]/10)-4);
            }

        }
        printf("\n");
    }
}