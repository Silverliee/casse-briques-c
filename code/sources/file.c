#include <stdio.h>
#include <dirent.h>
#include <malloc.h>
#include "../prototypes/menu.h"

Game chooseFile() {
    //var init
    int playerCount;
    int validator = 0;
    int baseBombNumber;
    int cursor = -2;
    int mapChoice = 0;
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
        printf("######################################################################\n");
        printf("#~~ Veuillez choisir la carte a importer ~~#\n");
        while ((displayedDir = readdir(displayedDirectory)) != NULL) {
            if (cursor == -2 || cursor == -1) {
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
    for (int i = 0; i < mapChoice + 3; i++) {
        choiceDir = readdir(choiceDirectory);
    }
    int largeEnoughBufferLen = 500;
    char *fileName = (char *) malloc(largeEnoughBufferLen * sizeof(char));
    sprintf(fileName, "../Maps/%s", choiceDir->d_name);
    FILE *mapFile = fopen(fileName, "r");
    char lineReader[100] = {0};
    baseBombNumber = atoi(fgets(lineReader, 100, mapFile));
    fscanf(mapFile, "%d %d", &column, &row);
    int **customMap = calloc(row + 1, sizeof(int *));
    for (int i = 0; i < row; i++) {
        customMap[i] = malloc(sizeof(int) * column + 1);
    }
    fgetc(mapFile);
    int playerIndex = 5;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column + 1; j++) {
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
        printf("######################################################################\n");
        printf("Veuillez entrer le nombre de joueur de 1 a 4 :\n");
        scanf("%d", &playerCount);
        if (playerCount >= 1 && playerCount <= 4) {
            validator = 1;
        }
    }

    //create playerList
    Player *playerList = malloc(sizeof(Player) * playerCount);
    for (int i = 0; i < playerCount; i++) {
        char playerName[100] = {0};
        printf("######################################################################\n");
        printf("Veuillez saisir le nom du joueur %d\n", i + 1);
        scanf("%s", playerName);
        playerList[i] = createPlayer(playerName, baseBombNumber);
    }

    //create the game
    Game myGame = createGame(playerCount, playerList, 0);
    return myGame;
}