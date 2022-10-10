#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[5][9] = {
    {'x','x','x','x','x','x','x','x','x'},
    {'x','p',' ','m','m','m','m','m','x'},
    {'x',' ','x','m','x','m','x',' ','x'},
    {'x','m','m','m','m','m',' ','p','x'},
    {'x','x','x','x','x','x','x','x','x'}
};

int main(){
    for(int i = 0;i < 5; i++){
        for(int j = 0; j < 9; j++){
            if(map[i][j] == 'x'){
                printf("%c", 219);
            }
            else if(map[i][j] == 'm'){
                printf("%c", 177);
            }
            else if(map[i][j] == ' '){
                printf("%c", map[i][j]);
            }
            else{
                printf("%c", 'J');
            }
        }
        printf("\n");
    }
}