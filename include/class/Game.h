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
#include "UpgradesManager.h"
#include "ResourcesManager.h"
#include "Distance.h"

class Game{
 private:

  UpgradesList _list_of_upgrades;
  ResourcesList _stock_of_resources;
  GameState _game_state;
  UpgradesManager _upgrades_manager;
  ResourcesManager _resources_manager;

  // Compute game state
  Acceleration compute_new_acceleration(Time time) const;
  Speed compute_new_speed(Time time) const;
  Distance compute_new_distance(Time time) const;
  void gather_resources(Time elapsed_time);

 public:
  // Constructor
  Game();
  ~Game();

  // Getters
  const GameState& state() const;
  const UpgradesManager& manage_upgrades() const;
  const ResourcesManager& manage_resources() const;

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
