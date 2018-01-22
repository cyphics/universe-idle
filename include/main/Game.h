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
#include <map>

//#include "BigNum.h"
#include "managment/GameState.h"
#include "ship/UpgradesManager.h"
#include "ship/ResourcesManager.h"
//#include "Distance.h"


class Game{
 private:

  Physics::Time _time_played = Physics::Time(0);
  ResourcesList _stock_of_resources;
  UpgradesList _list_of_upgrades;
  GameState _game_state;
  UpgradesManager _upgrades_manager;
  ResourcesManager _resources_manager;

  // Compute game state
  Physics::Speed compute_new_speed(Physics::Time time) const;
  Physics::Distance compute_new_distance(Physics::Time time) const;

 public:
  // Constructor
  Game();
  ~Game();

  // Getters
  const GameState& state() const;
  GameState& state();
  const UpgradesManager* manage_upgrades() const;
  const ResourcesManager* manage_resources() const;

  // Misc
  void update_state();
  void wait(Physics::Time time);
  bool is_affordable(Upgrade_ID upgrade, int amount);
  void buy_upgrade(Upgrade_ID upgrade, int amount);

  void click();

  Physics::Time time_until_affordable(Upgrade_ID upgrade, unsigned int amount) const;

};


#endif // GAME_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
