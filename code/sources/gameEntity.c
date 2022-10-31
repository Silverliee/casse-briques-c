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
    Map *myMap = malloc(sizeof(Map));
    switch (selectedMap) {
        case 1:
            myMap->row = 5;
            myMap->column = 9;
            myMap->map = (int **) SELECTED_MAP_1;
            break;
        case 2:
            myMap->row = 13;
            myMap->column = 15;
            myMap->map = (int **) SELECTED_MAP_2;
            break;
        default:
            break;
    }
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
