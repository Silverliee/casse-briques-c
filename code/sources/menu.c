#include <stdio.h>
#include "../prototypes/menu.h"



void uniqueGameMenu() {
    //selectionne la map
    //joue
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
        printf("######################################################################");
        printf("#                                                                    #");
        printf("#         BIENVENUE SUR BOMBER....JE VEUX DIRE CASSE BRIQUE !        #");
        printf("#                                                                    #");
        printf("######################################################################");
        printf("- 1: Partie Rapide\n- 2: Mode Battle \n- 3: Multijoueur\n");
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