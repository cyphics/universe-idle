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
#include "ship/Computer.h"
//#include "Distance.h"


class Game{
 private:
  Computer _computer;
  Physics::Time _time_played = Physics::Time(0);
  GameState _game_state;
  UpgradesManager _upgrades;
  ResourcesManager _resources;

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
  const UpgradesManager* upgrades() const;
  const ResourcesManager* resources() const;
  Physics::Time time_until_affordable(Upgrade_ID upgrade, unsigned int amount) const;
  Physics::Time time_until_in_stock(const Resource_ID& resource_id, BigNum required_amount) const;
  Physics::Time time_until_in_stock(const Price& price) const;

  bool is_affordable(Upgrade_ID upgrade, int amount) const;
  const Computer& compute() const;


  // Misc
  void update_state();
  void wait(Physics::Time time);
  void buy_upgrade(Upgrade_ID upgrade, int amount);
  void gather_resources(Physics::Time time);

  void click();

  std::vector<std::string> ui_data();
};


#endif // GAME_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
