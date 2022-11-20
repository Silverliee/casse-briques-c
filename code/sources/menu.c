#include <stdio.h>
#include "../prototypes/menu.h"
#include "../prototypes/file.h"

Game chooseMap() {
    Game myGame;
    int mapChoice;
    printf("######################################################################\n");
    printf("- 1: Grande carte \n- 2: Petite carte \n");
    printf("######################################################################\n");
    scanf("%d", &mapChoice);

}

void uniqueGameMenu() {
    int menuChoice = 0;
    Game myGame;
    while (menuChoice != 1 && menuChoice != 2) {
        printf("######################################################################\n");
        printf("- 1: Sélectionner une carte \n- 2: Importer une carte \n");
        scanf("%d", &menuChoice);
    }
    switch (menuChoice) {
        case 1:
            break;
        case 2:
            myGame = chooseFile();
            play(myGame);
            break;
        default:
            printf("Bizarre, il y a un bug dans la matrice votre choix n'est pas prévu");
            break;
    }
}

void multipleGameMenu() {
    //selectionne les maps
    //joue
}

void onlineGameMenu() {

}

void gameMenu() {
    int menuChoice = 0;
    while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3) {
        printf("######################################################################\n");
        printf("#                                                                    #\n");
        printf("#         BIENVENUE SUR BOMBER....JE VEUX DIRE CASSE BRIQUE !        #\n");
        printf("#                                                                    #\n");
        printf("######################################################################\n");
        printf("- 1: Partie Rapide\n- 2: Mode Battle \n- 3: Partie en ligne\n");
        scanf("%d", &menuChoice);
    }
    switch (menuChoice) {
        case 1:
            uniqueGameMenu();
            break;
        case 2:
            multipleGameMenu();
            break;
        case 3:
            onlineGameMenu();
            break;
        default:
            printf("Bizarre, il y a un bug dans la matrice votre choix n'est pas prévu");
            break;
    }
}