// -*- compile-command: "./../../compile.sh"; -*-
// Simulate_game.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef SIMULATE_GAME_H
#define SIMULATE_GAME_H 1

//#include "../class/Game.h"
#include "simulation/Strategy.h"
#include "ship/UpgradesManager.h"

class Game;

/**
 * Runs a game with a given strategy, for a certain duration.
   Returns a played game
 */
Game simulate_game(Strategy_ID strategy_id, Physics::Time duration);


#endif // SIMULATE_GAME_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
