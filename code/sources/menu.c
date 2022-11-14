#include <stdio.h>
#include <dirent.h>
#include <malloc.h>
#include "../prototypes/menu.h"
#include "../prototypes/game.h"
#include "../prototypes/map.h"

void chooseFile() {
    //var init
    int playerCount;
    int validator = 0;
    int baseBombNumber;
    int cursor = -2;
    int mapChoice;
    int column;
    int row;

    //displayed dir section
    DIR *displayedDirectory;
    struct dirent *displayedDir;
    displayedDirectory = opendir("../Maps");

    //choice dir section
    DIR *choiceDirectory;
    struct dirent *choiceDir;
    choiceDirectory = opendir("../Maps");

    //Display files to players
    if (displayedDirectory) {
        printf("#~~ Veuillez choisir la carte a importer ~~# \n");
        while ((displayedDir = readdir(displayedDirectory)) != NULL) {
            if(cursor == -2 || cursor == -1) {
                cursor++;
                continue;
            }
            printf("%d %s\n", cursor, displayedDir->d_name);
            cursor++;
        }
        closedir(displayedDirectory);
        scanf("%d", &mapChoice);
    }

    //open the correct file
    for(int i = 0; i < mapChoice + 3; i++) {
        choiceDir = readdir(choiceDirectory);
    }
    int largeEnoughBufferLen = 500;
    char *fileName = (char*)malloc(largeEnoughBufferLen * sizeof(char));
    sprintf(fileName, "../Maps/%s", choiceDir->d_name);
    FILE *mapFile = fopen(fileName,"r");
    char lineReader[100]= {0};
    baseBombNumber = atoi(fgets(lineReader,100,mapFile));
    fscanf(mapFile,"%d %d",&column,&row);
    int **customMap = calloc(row+1, sizeof(int *));
    for (int i = 0; i < row; i++) {
        customMap[i] = malloc(sizeof(int)*column+1);
    }
    fgetc(mapFile);
    int playerIndex = 5;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column+1; j++) {
            switch (fgetc(mapFile)) {
                case 120:
                    customMap[i][j] = 0;
                    break;
                case 112:
                    customMap[i][j] = playerIndex;
                    playerIndex++;
                    break;
                case 109:
                    customMap[i][j] = 1;
                    break;
                case 32:
                    customMap[i][j] = 2;
                    break;
                case 10:

                    break;
            }
        }
    }

    fclose(mapFile);


    //select the number of player :
    while (!validator) {
        printf("Veuillez entrer le nombre de joueur de 1 a 4 : ");
        scanf("%d", &playerCount);
        if(playerCount >= 1 && playerCount <= 4 ) {
            validator = 1;
        }
    }

    //create the game structure
    Game *myGame = malloc(sizeof(Game));
    myGame->playerCount = playerCount;
    myGame->mapSelected;
    myGame->WhoPlay = 1;
    myGame->gameMap.row = row;
    myGame->gameMap.column = column;
    myGame->gameMap.map = customMap;
    myGame->posedBomb =  malloc(sizeof(Bomb)*100);
    myGame->posedBombCount = 0;
    myGame->players = malloc(sizeof(Player)*playerCount);
    for (int i = 0; i < playerCount ; i++) {
        myGame->players[i] = createPlayer("rand",baseBombNumber);
    }
    printMap(*myGame);
}

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