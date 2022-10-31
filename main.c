#include <stdio.h>
#include <stdlib.h>
#include "code/prototypes/bomb.h"
#include "code/prototypes/game.h"
#include "code/prototypes/inventory.h"
#include "code/prototypes/gameEntity.h"
#include "code/prototypes/map.h"
#include "code/prototypes/player.h"

int main() {
    printf("Hello, World!\n");
    Player playerList[1] = {createPlayer("testPlayer",5)};
    Game *testGame = createGame(3,playerList,1);
    printMap(testGame);
    return 0;
}
