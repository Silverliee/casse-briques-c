#ifndef game_h
#define game_h

#include <stdio.h>
#include "gameEntity.h"

// La fonction renvoie :
// - 0 -> si il reste plusieurs joueurs en vie -> Continuer la partie
// - 1 -> si il reste un joueur en vie -> Fin de la partie
// - 2 -> si il reste plus de joueur en vie -> C'est un match null
// - 3 -> il y a une incohérence à gérer;
int isThereAWinner(Game myGame);

void playLocalMultiplayer(Game myGame);

void playSolo(Game myGame);

#endif
