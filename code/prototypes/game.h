#ifndef game_h
#define game_h
#include <stdio.h>
#include "bomb.h"
#include "gameEntity.h"
#include "inventory.h"
#include "map.h"
#include "player.h"

/**
	Cette fonction devra juste ajouter le joueur newPlayer à la partie myGame
**/
void addPlayerToGame(Player newPlayer,Game myGame);

#endif
