#include <stdio.h>
#include "../prototypes/gameEntity.h"
//Les objets
//ça serait plus pertinant que bombDown reduise juste la valeur de bombUp.. peut-être le retirer
typedef struct {
    int bombUp;
    int bombDown;
    int yellowFlame;
    int blueFlame;
    int redFlame;
    int bombPass;
    int bombKick;
    int invincibility;
    int heart;
    int life;
} Inventory;

//Le joueur
typedef struct {
    char* name;
    int bombCount;
    Inventory inventory;
} Player;

//Les bombes
typedef struct {
    int timer;
    int blastRange;
    Player *owner;
} Bomb;

//La map, note : ça serait intéréssant de représenter
//notre map sous forme de matrice d'entier (tableau a deux dimensions) avec
// - 0 pour les murs indestructibles
// - 1 pour les murs destructibles
// - 2 pour les trous
// - 3 pour les bombes
// - 4 pour le joueur 1
// - 3 + n pour le joueur n;
typedef struct {
    int **map;
} Map;

//La partie
typedef struct {
    Player **players;
    int playerCount;
    int mapSelected;
} Game;