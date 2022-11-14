#include <stdio.h>
#include <stdlib.h>
#include "code/sources/gameEntity.c"
#include "code/sources/map.c"
#include "code/sources/player.c"
#include "code/sources/menu.c"
#include "code/sources/bomb.c"
#include "code/sources/game.c"

int main() {
    //gameMenu();

    Player j1 = createPlayer("quentin", 2);
    Player j2 = createPlayer("alex", 2);
    Player j3 = createPlayer("jean", 2);
    Player j4 = createPlayer("paul", 2);

    Player* listeJoueurs = malloc(sizeof(Player)*2);

    listeJoueurs[0] = j1;
    listeJoueurs[1] = j2;
    /*listeJoueurs[2] = j3;
    listeJoueurs[3] = j4;*/

    int nbJoueurs = 2;
    int direction;
    int action;

    int game = 1;

    Game myGame = *createGame(nbJoueurs, listeJoueurs, 1);
    while(game == 1){
        action= 0;
        makeThemBoom(myGame);
        isDead(&myGame);
        if(isThereAWinner(myGame) != 0){
            break;
        }
        printMap(myGame);
        printf("Choisissez une action joueur %d:\n", myGame.WhoPlay);
        while(action < 1 || action > 3){
            printf("- 1: Se deplacer\n- 2: Poser une bombe\n- 3: Ne rien faire\n");
            scanf("%d", &action);
            if(action == 1){
                printf("Choisissez une direction:\n");
                direction = 0;
                while(direction < 1 || direction > 4){
                    printf("- 1: Haut\n- 2: Bas\n- 3: Gauche\n- 4: Droite\n");
                    scanf("%d", &direction);
                    if(direction < 1){
                        printf("Merci de choisir une direction existante\n");
                    }
                    else{
                        movement(myGame, direction);
                    }
                }
            }
            else if(action == 2){
                dropBomb(&myGame, &myGame.players[myGame.WhoPlay-1]);
            }
            else if(action == 3){
                continue;
            }
            else{
                printf("Cette action n'existe pas, veuillez en selectionner une autre\n");
            }
        }
        if(myGame.players[myGame.WhoPlay-1].inventory.invincibleTimer > 0){
            myGame.players[myGame.WhoPlay-1].inventory.invincibleTimer--;
            if(myGame.players[myGame.WhoPlay-1].inventory.invincibleTimer == 0){
                myGame.players[myGame.WhoPlay-1].inventory.invincibility = 0;
            }
        }
        if(myGame.WhoPlay == myGame.playerCount){
            myGame.WhoPlay = 1;
            while(myGame.players[myGame.WhoPlay-1].life == 0){
                myGame.WhoPlay++;
            }
        }
        else{
            myGame.WhoPlay ++;
            while(myGame.players[myGame.WhoPlay-1].life == 0){
                myGame.WhoPlay++;
            }
        } 
    }
    printMap(myGame);
    switch(isThereAWinner(myGame)){
        case 1:
            for(int i = 0; i < myGame.playerCount; i++){
                if(myGame.players[i].life > 0){
                    printf("Le gagnant est le joueur %d, %s",i+1,  myGame.players[i].name);
                }
            }
            break;
        case 2:
           printf("Match nul !!"); 
           break;
    }
    return 0;
}
