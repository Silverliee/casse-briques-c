#include <stdio.h>
#include "../prototypes/gameEntity.h"
#include <stdlib.h>

int SELECTED_MAP_1[5][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 2, 1, 1, 1, 1, 1, 0},
        {0, 2, 0, 1, 0, 1, 0, 2, 0},
        {0, 1, 1 ,1, 1, 1, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int SELECTED_MAP_2[13][15] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,2,2,1,1,1,1,1,1,1,1,1,2,2,0},
        {0,2,0,1,0,1,0,1,0,1,0,1,0,2,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,2,0,1,0,1,0,1,0,1,0,1,0,2,0},
        {0,2,2,1,1,1,1,1,1,1,1,1,2,2,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

Player *createPlayer(char* name, int bombCount) {
    Player *myPlayer = malloc(sizeof(Player));
    myPlayer->name = name;
    myPlayer->bombCount = bombCount;
    return myPlayer;
}

Map createMap(int selectedMap) {
    Map myMap;
    myMap.map = calloc(myMap.column, sizeof(int *));
    switch (selectedMap) {
        case 1:
            myMap.row = 5;
            myMap.column = 9;
            myMap.map = (int **) SELECTED_MAP_1;
            myMap.row = 5;
            myMap.column = 9;
            myMap.map = calloc(myMap.column+1, sizeof(int *));
            for (int i = 0; i < myMap.row; i++) {
                myMap.map[i] = calloc(myMap.column+1, sizeof(int));
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
            myMap.map = (int **) SELECTED_MAP_2;
            myMap.row = 13;
            myMap.column = 15;
            myMap.map = malloc(sizeof(int)*myMap.row*myMap.column);
            for (int i = 0; i < myMap.column ; i++) {
                for (int j = 0; j < myMap.row ; j++) {
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
    Bomb myPosedBombSubMap[200];
    //myGame->posedBomb =  myPosedBombSubMap;
    myGame->players = malloc(sizeof(Player)*playerCount);
    for (int i = 0; i < playerCount ; i++) {
        myGame->players[i] = playerList[i];
    }
    return myGame;
}
