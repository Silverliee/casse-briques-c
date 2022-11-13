#include <stdio.h>
#include "../prototypes/game.h"

int isThereAWinner(Game myGame) {
    int playerAlive = 0;
    for (int i = 0; i < myGame.playerCount ; i++) {
        if (myGame.players[i].life > 0) {
            playerAlive++;
        }
    }
    if (playerAlive > 1) {
        return 0;
    } else if (playerAlive == 1) {
        return 1;
    } else if (playerAlive == 0) {
        return 2;
    }
    return 3;
}

void playTurn(Game myGame) {

}

void play(Game myGame) {
    while (isThereAWinner(myGame) != 1 && isThereAWinner(myGame) != 2 && isThereAWinner(myGame) != 3) {
        playTurn(myGame);
    }
}