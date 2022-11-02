#include <stdio.h>
#include "../prototypes/gameEntity.h"
#include <stdlib.h>

int SELECTED_MAP_1[5][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 2, 1, 1, 1, 1, 1, 0},
        {0, 2, 0, 1, 0, 1, 0, 2, 0},
        {0, 1, 1 ,1, 1, 1, 2, 6, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int SELECTED_MAP_2[13][15] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,5,2,1,1,1,1,1,1,1,1,1,2,6,0},
        {0,2,0,1,0,1,0,1,0,1,0,1,0,2,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,2,0,1,0,1,0,1,0,1,0,1,0,2,0},
        {0,7,2,1,1,1,1,1,1,1,1,1,2,8,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

Player *createPlayer(char* name, int bombCount) {
    Player *myPlayer = malloc(sizeof(Player));
    myPlayer->name = name;
    myPlayer->bombCount = bombCount;
    Inventory inventaire;
    inventaire.bombUp = 0;
    inventaire.bombDown = 0;
    inventaire.yellowFlame = 0;
    inventaire.blueFlame = 0;
    inventaire.redFlame = 0;
    inventaire.bombPass = 0;
    inventaire.bombKick = 0;
    inventaire.invincibility = 0;
    inventaire.heart = 0;
    inventaire.life = 0;

    myPlayer->inventory = inventaire;
    return myPlayer;
}

Map createMap(int selectedMap) {
    Map myMap;
    switch (selectedMap) {
        case 1:
            myMap.row = 5;
            myMap.column = 9;
            myMap.map = calloc(myMap.row+1, sizeof(int *));
            for (int i = 0; i < myMap.row; i++) {
                myMap.map[i] = malloc(sizeof(int)*myMap.column+1);
            }
            for (int i = 0; i < myMap.row ; i++) {
                for (int j = 0; j < myMap.column ; j++) {
                    myMap.map[i][j] = SELECTED_MAP_1[i][j];
                }
            }
            break;
        case 2:
            myMap.row = 13;
            myMap.column = 15;
            myMap.map = calloc(myMap.row+1, sizeof(int *));
            for (int i = 0; i < myMap.row; i++) {
                myMap.map[i] = malloc(sizeof(int)*myMap.column+1);
            }
            for (int i = 0; i < myMap.row ; i++) {
                for (int j = 0; j < myMap.column ; j++) {
                    myMap.map[i][j] = SELECTED_MAP_2[i][j];
                }
            }
            break;
        default:
            break;
    }
    return myMap;
}

Game *createGame(int playerCount,Player *playerList,int mapSelected) {
    Game *myGame = malloc(sizeof(Player));
    myGame->playerCount = playerCount;
    myGame->mapSelected = mapSelected;
    myGame->WhoPlay = 1;
    myGame->gameMap = createMap(mapSelected);
    myGame->posedBomb =  malloc(sizeof(Bomb)*100);
    myGame->posedBombCount = 0;
    myGame->players = malloc(sizeof(Player)*playerCount);
    for (int i = 0; i < playerCount ; i++) {
        myGame->players[i] = playerList[i];
    }
    return myGame;
}
