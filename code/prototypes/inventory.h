#ifndef inventory_h
#define inventory_h
#include <stdio.h>
#include "gameEntity.h"

/**
	Ajoute un item au joueur en paramettre en fonction de l'itemCode
	-  0 bombUp;
	-  1 bombDown;
	-  2 yellowFlame;
	-  3 blueFlame;
	-  4 redFlame;
	-  5 bombPass;
	-  6 bombKick;
	-  7 invincibility;
	-  8 heart;
	-  9 life;
**/
void addItem(Player *player, int itemCode);

/**
	genère un itemCode en prennant en compte la notion de rareté des items
**/
int generateRandomItem();

#endif