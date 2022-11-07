#ifndef bomb_h
#define  bomb_h
#include <stdio.h>
#include "gameEntity.h"

/**
	Cette fonction fait exploser une bombe, modifie la map, et les pv des joueurs
**/
void Boom(Game *myGame, Bomb myBomb);


/**
	Fonction qui vérifie si des bombes présentes sur la map explosent
	Le timer d'une bombe est décrémenté lors du tour du joueur qui l'a posé
*/
void makeThemBoom(Game *myGame);


#endif