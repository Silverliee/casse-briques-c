#include <stdio.h>
#include <stdlib.h>
#include "code/prototypes/gameEntity.h"
#include "code/prototypes/map.h"
#include "code/prototypes/player.h"
#include "code/prototypes/menu.h"

int main() {
    //gameMenu()

    Player j1 = createPlayer("quentin", 2);
    Player j2 = createPlayer("alex", 2);

    Player* listeJoueurs = malloc(sizeof(Player)*2);

    listeJoueurs[0] = j1;
    listeJoueurs[1] = j2;

    int nbJoueurs = 2;
    int direction;
    int action;

    int tour = 0;

    Game myGame = *createGame(2, listeJoueurs, 2);
    while(tour < 2){
        action = 0;
        printMap(myGame);
        printf("Choisissez une action joueur %d:\n", myGame.WhoPlay);
        while(action < 1 || action > 3){
            printf("- 1: Se deplacer\n- 2: Poser une bombe\n- 3: Ne rien faire\n");
            scanf("%d", &action);
            if(action == 1){
                printf("Choisissez une direction:\n");
                printf("- 1: Haut\n- 2: Bas\n- 3: Gauche\n- 4: Droite\n");
                scanf("%d", &direction);
                movement(myGame, direction);
            }
            else if(action == 2){
                dropBomb(&myGame, myGame.players[myGame.WhoPlay-1]);
            }
            else if(action == 3){
                continue;
            }
            else{
                printf("Cette action n'existe pas, veuillez en selectionner une autre\n");
            }
<<<<<<< HEAD
            tour++;
=======
>>>>>>> 81d18fd (encore)
        }
        tour++; 
        myGame.WhoPlay += 1;
    }
    printMap(myGame);
    return 0;
}
