// -*- compile-command: "./../../compile.sh"; -*-
// Game.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef GAME_H
#define GAME_H 1

#include <vector>
#include "BigNum.h"
#include "GameState.h"
#include "PurchaseManager.h"
#include "Distance.h"

class Game{
 private:

  GameState _game_state;
  PurchaseManager _purchase_manager;

  // Compute game state
  Acceleration compute_new_acceleration(Time time) const;
  Speed compute_new_speed(Time time) const;
  Distance compute_new_distance(Time time) const;

 public:
  // Constructor
  Game();
  ~Game();

  // Getters
  const GameState& state() const;
  const PurchaseManager& manage_purchase() const;


  // Misc
  void wait(Time time);
  bool is_affordable(Upgrade_ID upgrade, int amount);
  void buy_upgrade(Upgrade_ID upgrade, int amount);

  void click();
};


#endif // GAME_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
