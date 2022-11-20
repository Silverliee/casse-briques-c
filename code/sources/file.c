#include <stdio.h>
#include <dirent.h>
#include <malloc.h>
#include "../prototypes/menu.h"

Map chooseImportedMap() {
    //var init
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

    //create map
    Map myMap;
    myMap.row = row;
    myMap.column = column;
    myMap.map = customMap;
    myMap.playersDefaultBombCount = baseBombNumber;
    myMap.mapMaxPlayer = playerIndex - 5;

    return myMap;
}