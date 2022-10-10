#ifndef bomb_h
#define  bomb_h
#include <stdio.h>
#include "gameEntity.h"
#include "inventory.h"
#include "map.h"
#include "player.h"
#include "game.h"

/**
	Cette fonction fait explosé une bombe, modifie la map, et les pv des joueurs
**/
void Boom(Game myGame, Bomb myBomb);

#endif