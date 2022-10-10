#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[5][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 2, 1, 1, 1, 1, 1, 0},
    {0, 2, 0, 1, 0, 1, 0, 2, 0},
    {0, 1, 1 ,1, 1, 1, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int main(){
    int nbJoueurs = 1;
    for(int i = 0;i < 5; i++){
        for(int j = 0; j < 9; j++){
            if(map[i][j] == 0){
                printf("%c", 219);
            }
            else if(map[i][j] == 1){
                printf("%c", 177);
            }
            else if(map[i][j] == 2){
                printf("%c", ' ');
            }
            else{
                printf("%d", map[i][j]-3);
            }
        }
        printf("\n");
    }
}