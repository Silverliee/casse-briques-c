#include <stdio.h>
#include <malloc.h>
#include "../prototypes/menu.h"
#include "../prototypes/file.h"

Game createDefaultGameMenu(){
    //var initialisation
    Game myGame;
    int validator = 0;
    int mapChoice;
    int mapPlayerCapacity;
    int playerCount;
    //choose the map
    while (!validator) {
        printf("######################################################################\n");
        printf("- 1: Petite carte \n- 2: Grande carte\n");
        scanf("%d", &mapChoice);
        if(mapChoice == 1 || mapChoice == 2) {
            validator = 1;
        }
    }
    //create the game with preselected map number one
    if(mapChoice == 1) {
        validator = 0;
        while (!validator) {
            mapPlayerCapacity = 2;
            printf(" Veuillez saisir le nombre de joueur pour la partie ( Entre 1 et %d) : \n", mapPlayerCapacity);
            scanf("%d", &playerCount);
            printf("######################################################################\n");
            if(playerCount >= 1 && playerCount <= mapPlayerCapacity) {
                validator = 1;
            }
        }
        Player* playerList = malloc(sizeof(Player) * playerCount);
        for (int i = 0; i < playerCount ; i++) {
            char playerName[100] = {0};
            printf("Veuillez saisir le nom du joueur %d\n",i+1);
            scanf("%s", playerName);
            playerList[i] = createPlayer(playerName,2);
        }
        myGame = createGameWithDefaultMap(playerCount,playerList,1);
    }
    //create the game with preselected map number two
    if(mapChoice == 2) {
        validator = 0;
        while (!validator) {
            mapPlayerCapacity = 4;
            printf("######################################################################\n");
            printf(" Veuillez saisir le nombre de joueur pour la partie ( Entre 1 et %d) : \n", mapPlayerCapacity);
            scanf("%d", &playerCount);
            printf("######################################################################\n");
            if(playerCount >= 1 && playerCount <= mapPlayerCapacity) {
                validator = 1;
            }
        }
        Player* playerList = malloc(sizeof(Player) * playerCount);
        for (int i = 0; i < playerCount ; i++) {
            char playerName[100] = {0};
            printf("Veuillez saisir le nom du joueur %d\n",i+1);
            scanf("%s", playerName);
            printf("######################################################################\n");
            playerList[i] = createPlayer(playerName,2);
        }
        myGame = createGameWithDefaultMap(playerCount,playerList,2);
    }

    return myGame;
}

Game  createImportedGameMenu() {
    //var initialisation
    Game myGame;
    Map myMap = chooseImportedMap();
    int playerCount;
    int validator = 0;

    //create game
    while (!validator) {
        printf("######################################################################\n");
        printf(" Veuillez saisir le nombre de joueur pour la partie ( Entre 1 et %d) : \n", myMap.mapMaxPlayer);
        scanf("%d", &playerCount);
        if(playerCount >= 1 && playerCount <= myMap.mapMaxPlayer) {
            validator = 1;
        }
    }
    Player* playerList = malloc(sizeof(Player) * playerCount);
    for (int i = 0; i < playerCount ; i++) {
        char playerName[100] = {0};
        printf("######################################################################\n");
        printf("Veuillez saisir le nom du joueur %d\n",i+1);
        scanf("%s", playerName);
        playerList[i] = createPlayer(playerName,myMap.playersDefaultBombCount);
    }
    myGame = createGameWithImportedMap(playerCount,playerList,myMap);

    return myGame;
}

void uniqueGameMenu() {
    int menuChoice = 0;
    Game myGame;
    while (menuChoice != 1 && menuChoice != 2) {
        printf("######################################################################\n");
        printf("- 1: Selectionner une carte \n- 2: Importer une carte \n");
        scanf("%d", &menuChoice);
    }
    switch (menuChoice) {
        case 1:
            myGame = createDefaultGameMenu();
            if(myGame.playerCount == 1) {

            } else {
                playLocalMultiplayer(myGame);
            }
            break;
        case 2:
            myGame = createImportedGameMenu();
            if(myGame.playerCount == 1) {

            } else {
                playLocalMultiplayer(myGame);
            }
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