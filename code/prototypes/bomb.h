#ifndef bomb_h
#define  bomb_h
#include <stdio.h>
#include "gameEntity.h"

/**
	Cette fonction fait exploser une bombe, modifie la map, et les pv des joueurs
**/
void Boom(Game myGame, Bomb myBomb);

<<<<<<< HEAD
void makeThemBoom(Game myGame);
=======

/**
	Fonction qui vérifie si des bombes présentes sur la map explosent
	Le timer d'une bombe est décrémenté lors du tour du joueur qui l'a posé
*/
void verifBoom(Game myGame);
>>>>>>> 81d18fd (encore)

#endif