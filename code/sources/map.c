#include <stdio.h>
#include "../prototypes/map.h"

void printMap(Game *myGame) {
    for (int i = 0; i < myGame->gameMap.row; i++) {
        for (int j = 0; j < myGame->gameMap.column; j++) {
            printf("%d",myGame->gameMap.map[j][i]);
        }
    }
}