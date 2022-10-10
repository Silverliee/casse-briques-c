#ifndef player_h
#define player_h
#include <stdio.h>
#include "bomb.h"
#include "gameEntity.h"
#include "inventory.h"
#include "map.h"
#include "game.h"

/**
	Cette fonction devra déposer une bombe à la case ou se situe un joueur et décrémenter
	de un son nombre de bomb disponible
**/
void dropBomb(Player *player, Map map);

/**
	Effectue le déplacement en fonction de la direction
	- 1 Haut
	- 2 Bas
	- 3 Gauche
	- 4 Droite
**/
void movement(Game myGame, int direction);

#endif