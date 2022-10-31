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

//Affiche la map a partir d'un tableau a double entrée
void afficheMap(int tab[][9]){
    for(int i = 0;i < 5; i++){
        for(int j = 0; j < 9; j++){
            if(tab[i][j] == 0){
                printf("%c", 219);
            }
            else if(tab[i][j] == 1){
                printf("%c", 177);
            }
            else if(tab[i][j] == 2){
                printf("%c", ' ');
            }
            else if(tab[i][j] == 3){
                    printf("%c", 'O');
            }
            else if(tab[i][j] == -1){
                    printf("%c", '*');
            }
            else if(tab[i][j] == -2){
                    printf("%c", '#');
            }
            else{
                if(tab[i][j] > 30){
                    printf("%d", (tab[i][j]/10)-3);
                }
                else{
                    printf("%d", tab[i][j]-3);
                }
            }
        }
        printf("\n");
    }
}


//renvoie un tableau avec les coordonnées X et Y avec la position du joueur
int* positionJoueur(int Joueur, int map[][9]){
    int *position = malloc(2 * sizeof(int));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 9; j++){
            if(map[i][j]-3 == Joueur || (map[i][j]/10) - 3 == Joueur){
                position[0] = i;
                position[1] = j;
            }
        }
    }
    return position;
}

typedef struct {
    int timer;
    int blastRange;
    int posX;
    int posY;
    //Player *owner;
} Bomb;

void mapApres(int tab[][9]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 9; j++){
            if(tab[i][j] == -1 || tab[i][j] == -2 || tab[i][j] == 3){
                tab[i][j] = 2;
            }
        }
    }
}

void explosion(Bomb bombe, int tab[][9]){
    //explosion vers la droite
    for(int i = 1; i <= bombe.blastRange; i++){
        if(tab[bombe.posX][bombe.posY+i] == 1){
            tab[bombe.posX][bombe.posY+i] = -2;
            break;
        }
        else if(tab[bombe.posX][bombe.posY+i] == 2){
            tab[bombe.posX][bombe.posY+i] = -1;
        }
        else if(tab[bombe.posX][bombe.posY+i] == 0){
            break;
        }
    }
    //explosion vers la gauche
    for(int i = 1; i <= bombe.blastRange; i++){
        if(tab[bombe.posX][bombe.posY-i] == 1){
            tab[bombe.posX][bombe.posY-i] = -2;
            break;
        }
        else if(tab[bombe.posX][bombe.posY-i] == 2){
            tab[bombe.posX][bombe.posY-i] = -1;
        }
        else if(tab[bombe.posX][bombe.posY-i] == 0){
            break;
        }
    }
    //explosion vers le bas
    for(int i = 1; i <= bombe.blastRange; i++){
        if(tab[bombe.posX+i][bombe.posY] == 1){
            tab[bombe.posX+i][bombe.posY] = -2;
            break;
        }
        else if(tab[bombe.posX+i][bombe.posY] == 2){
            tab[bombe.posX+i][bombe.posY] = -1;
        }
        else if(tab[bombe.posX+i][bombe.posY] == 0){
            break;
        }
    }
    //explosion vers le haut
    for(int i = 1; i <= bombe.blastRange; i++){
        if(tab[bombe.posX-i][bombe.posY] == 1){
            tab[bombe.posX-i][bombe.posY] = -2;
            break;
        }
        else if(tab[bombe.posX-i][bombe.posY] == 2){
            tab[bombe.posX-i][bombe.posY] = -1;
        }
        else if(tab[bombe.posX-i][bombe.posY] == 0){
            break;
        }
    }
    afficheMap(tab);
    mapApres(tab);
}

void reducTimer(Bomb tab[]){
    for(int i = 0; i < 21; i++){
        tab[i].timer--;
    }
}

void verifBoum(Bomb tab[], int map[][9]){
    for(int i = 0; i < 21; i++){
        if(tab[i].timer == 0){
            explosion(tab[i], map);
        }
    }
}

int main(){
    int action;
    int joueur = 1;
    int tour = 20;

    int bombePos = 0;

    Bomb bombes[21];

    Bomb init ={
        .blastRange = -1,
        .posX = -1,
        .posY = -1,
        .timer = -1,
    };

    for(int i = 0; i < 21; i++){
        bombes[i] = init;
    }

    afficheMap(map);

    while(tour > 0){
        reducTimer(bombes);
        printf("Joueur %d, choissisez une action:\n- 1 : Se deplacer\n- 2 : Poser une bombe\n- 3 : Ne rien faire\n", joueur);
        scanf("%d", &action);
        int *positions = positionJoueur(joueur, map);
            int posX = positions[0];
            int posY = positions[1];
        if(action == 1){
            int direction;
            printf("Choissisez une direction:\n- 1 : Haut\n- 2 : Bas\n- 3 : Droite\n- 4 : Gauche\n");
            scanf("%d", &direction);
            if(direction == 1 && map[posX-1][posY] == 2){
                if((map[posX][posY]/10)-3 == joueur){
                    map[posX-1][posY] = map[posX][posY]/10;
                    map[posX][posY] = 3;
                }
                else{
                    map[posX-1][posY] = map[posX][posY];
                    map[posX][posY] = 2;
                }
            }
            else if(direction == 2 && map[posX+1][posY] == 2){
                if((map[posX][posY]/10)-3 == joueur){
                    map[posX+1][posY] = map[posX][posY]/10;
                    map[posX][posY] = 3;
                }
                else{
                    map[posX+1][posY] = map[posX][posY];
                    map[posX][posY] = 2;
                }
            }
            else if(direction == 3 && map[posX][posY+1] == 2){
                if((map[posX][posY]/10)-3 == joueur){
                    map[posX][posY+1] = map[posX][posY]/10;
                    map[posX][posY] = 3;
                }
                else{
                    map[posX][posY+1] = map[posX][posY];
                    map[posX][posY] = 2;
                }
            }
            else if(direction == 4 && map[posX][posY-1] == 2){
                if((map[posX][posY]/10)-3 == joueur){
                    map[posX][posY-1] = map[posX][posY]/10;
                    map[posX][posY] = 3;
                }
                else{
                    map[posX][posY-1] = map[posX][posY];
                    map[posX][posY] = 2;
                }
            }
        }
        else if(action == 2){
            map[posX][posY] *= 10;
            Bomb bombe ={
                .blastRange = 2,
                .posX = posX,
                .posY = posY,
                .timer = 4,
            };
            bombes[bombePos] = bombe;
            bombePos++;
        }
        if(joueur == 1){
            joueur = 2;
        }
        else{
            joueur = 1;
        }
        tour--;
        verifBoum(bombes, map);
        afficheMap(map);
    }
}