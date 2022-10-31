#include <stdio.h>
#include <stdlib.h>
#include "code/sources/bomb.c"
#include "code/sources/game.c"
#include "code/sources/inventory.c"
#include "code/sources/gameEntity.c"
#include "code/sources/map.c"
#include "code/sources/player.c"

int main() {

    Player j1 = *createPlayer("quentin", 2);
    Player j2 = *createPlayer("alex", 2);

    Player* listeJoueurs = malloc(sizeof(Player)*2);

    listeJoueurs[0] = j1;
    listeJoueurs[1] = j2;

    int nbJoueurs = 2;

    Game myGame = *createGame(2, listeJoueurs, 1);

    printf("%s", myGame.players[1].name);

    return 0;
}
