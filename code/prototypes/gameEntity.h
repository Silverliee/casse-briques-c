#ifndef gameEntity_h
#define gameEntity_h

#include <stdio.h>

/**
 * Les objets
 * ça serait plus pertinant que bombDown reduise juste la valeur de bombUp.. peut-être le retirer
 **/
typedef struct {
    int yellowFlame;
    int blueFlame;
    int redFlame;
    int bombPass;
    int bombKick;
    int invincibility;
    int invincibleTimer;
    int heart;
    int life;
    int pickHeart;
} Inventory;

//Le joueur
typedef struct {
    char *name;
    int life;
    int bombCount;
    Inventory inventory;
} Player;

//Les bombes
typedef struct {
    int timer;
    int blastRange;
    int owner;
    int posX;
    int posY;
    int isExplode;
} Bomb;

/**La map, note : ça serait intéréssant de représenter
    Notre map sous forme de matrice d'entier (tableau a deux dimensions) avec
    - 0 pour les murs indestructibles
    - 1 pour les murs destructibles
    - 2 pour les case vides
    - 3 pour les trous
    - 4 pour les bombes
    - 5 pour le joueur 1
    - 4 + n pour le joueur n;
    - (4 + n)*10 Quand le joueur n pose une bombe a son emplacement
 **/
typedef struct {
    int **map;
    int row;
    int column;
} Map;

//La partie
typedef struct {
    Player *players;
    int WhoPlay;
    int playerCount;
    int mapSelected;
    Map gameMap;
    Bomb *posedBomb;
    int posedBombCount;
} Game;

/**
	Cette fonction crée et renvoie un nouveau joueur avec le nom et le nombre de bomb par
	défaut donné en parametre
**/
Player createPlayer(char *name, int bombCount);

/**
	Cette fonction prend en paramettre le nombre de joueur et la map selectionné,
	Elle devra crée une Entité game, set le playerCount en paramettre dans l'entité et
	crée la carte lié au numéro donné sans oublié de crée et de set une liste vide de bomb
	pour l'attribut posedBomb
**/
Game createGame(int playerCount, Player playerList[], int mapSelected);

/**
	Crée la map en fonction du genre de map selectionné
**/
Map createMap(int selectedMap);

#endif