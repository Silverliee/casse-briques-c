#include <stdio.h>
#include "../prototypes/game.h"
#include "../prototypes/map.h"
#include "../prototypes/player.h"
#include "../prototypes/bomb.h"

int isThereAWinner(Game myGame) {
    int playerAlive = 0;
    for (int i = 0; i < myGame.playerCount; i++) {
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

void playLocalMultiplayer(Game myGame) {
    int direction;
    int action;
    while (1) {
        action = 0;
        makeThemBoom(myGame);
        isDead(&myGame);
        if (isThereAWinner(myGame) != 0) {
            break;
        }
        printMap(myGame);
        printf("Choisissez une action joueur %d:\n", myGame.WhoPlay);
        while (action < 1 || action > 3) {
            printf("- 1: Se deplacer\n- 2: Poser une bombe\n- 3: Ne rien faire\n");
            scanf("%d", &action);
            if (action == 1) {
                printf("Choisissez une direction:\n");
                direction = 0;
                while (direction < 1 || direction > 4) {
                    printf("- 1: Haut\n- 2: Bas\n- 3: Gauche\n- 4: Droite\n");
                    scanf("%d", &direction);
                    if (direction < 1) {
                        printf("Merci de choisir une direction existante\n");
                    } else {
                        movement(myGame, direction);
                    }
                }
            } else if (action == 2) {
                dropBomb(&myGame, &myGame.players[myGame.WhoPlay - 1]);
            } else if (action == 3) {
                continue;
            } else {
                printf("Cette action n'existe pas, veuillez en selectionner une autre\n");
            }
        }
        if (myGame.players[myGame.WhoPlay - 1].inventory.invincibleTimer > 0) {
            myGame.players[myGame.WhoPlay - 1].inventory.invincibleTimer--;
            if (myGame.players[myGame.WhoPlay - 1].inventory.invincibleTimer == 0) {
                myGame.players[myGame.WhoPlay - 1].inventory.invincibility = 0;
            }
        }
        if (myGame.WhoPlay == myGame.playerCount) {
            myGame.WhoPlay = 1;
            while (myGame.players[myGame.WhoPlay - 1].life == 0) {
                myGame.WhoPlay++;
            }
        } else {
            myGame.WhoPlay++;
            while (myGame.players[myGame.WhoPlay - 1].life == 0) {
                myGame.WhoPlay++;
            }
        }
    }
    printMap(myGame);
    switch (isThereAWinner(myGame)) {
        case 1:
            for (int i = 0; i < myGame.playerCount; i++) {
                if (myGame.players[i].life > 0) {
                    printf("Le gagnant est le joueur %d, %s", i + 1, myGame.players[i].name);
                }
            }
            break;
        case 2:
            printf("Match nul !!");
            break;
    }
}

void playSolo(Game myGame) {
    int direction;
    int action;
    while (1) {
        action = 0;
        makeThemBoom(myGame);
        isDead(&myGame);
        if (isThereAWinner(myGame) != 0) {
            break;
        }
        printMap(myGame);
        if (myGame.WhoPlay == 1) {
            printf("Choisissez une action:\n");
            while (action < 1 || action > 3) {
                printf("- 1: Se deplacer\n- 2: Poser une bombe\n- 3: Ne rien faire\n");
                scanf("%d", &action);
                if (action == 1) {
                    printf("Choisissez une direction:\n");
                    direction = 0;
                    while (direction < 1 || direction > 4) {
                        printf("- 1: Haut\n- 2: Bas\n- 3: Gauche\n- 4: Droite\n");
                        scanf("%d", &direction);
                        if (direction < 1) {
                            printf("Merci de choisir une direction existante\n");
                        } else {
                            movement(myGame, direction);
                        }
                    }
                } else if (action == 2) {
                    dropBomb(&myGame, &myGame.players[myGame.WhoPlay - 1]);
                } else if (action == 3) {
                    continue;
                } else {
                    printf("Cette action n'existe pas, veuillez en selectionner une autre\n");
                }
            }
            if (myGame.players[myGame.WhoPlay - 1].inventory.invincibleTimer > 0) {
                myGame.players[myGame.WhoPlay - 1].inventory.invincibleTimer--;
                if (myGame.players[myGame.WhoPlay - 1].inventory.invincibleTimer == 0) {
                    myGame.players[myGame.WhoPlay - 1].inventory.invincibility = 0;
                }
            }
            if (myGame.WhoPlay == myGame.playerCount) {
                myGame.WhoPlay = 1;
                while (myGame.players[myGame.WhoPlay - 1].life == 0) {
                    myGame.WhoPlay++;
                }
            } else {
                myGame.WhoPlay++;
                while (myGame.players[myGame.WhoPlay - 1].life == 0) {
                    myGame.WhoPlay++;
                }
            }
        } else {
            //Ecrire fonction des ia ici
        }
    }

    printMap(myGame);
    switch (isThereAWinner(myGame)) {
        case 1:
            for (int i = 0; i < myGame.playerCount; i++) {
                if (myGame.players[i].life > 0) {
                    printf("Le gagnant est le joueur %d, %s", i + 1, myGame.players[i].name);
                }
            }
            break;
        case 2:
            printf("Match nul !!");
            break;
    }
}