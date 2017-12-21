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
#include "History.h"
#include "GameState.h"
#include "UpgradesList.h"
#include "ResourcesList.h"
#include "../helpers/resources_helper.h"

class Game{
 private:
  BigNum _traveled_distance;
  BigNum _current_speed;
  BigNum _current_acceleration;
  unsigned int _current_time;
  History _history;
  UpgradesList _upgrades_list;
  ResourcesList _resources_list;



 public:
  // Constructor
  Game();
  ~Game();

  // Getters
  BigNum get_distance() const;
  BigNum get_speed() const;
  BigNum get_acceleration() const;
  //BigNum get_resource_amount(Resource_ID) const;
  unsigned int get_time() const;
  unsigned int time_until(Upgrade_ID next_upgrade) const;
  GameState get_gamestate() const;
  History get_history() const;

  // Setters
  void set_distance();
  void set_speed();
  void set_acceleration();
  void set_time();

  // Compute game state
  BigNum compute_new_acceleration(unsigned int time) const;
  BigNum compute_new_speed(unsigned int time) const;
  BigNum compute_new_distance(unsigned int time) const;

  // Misc
  std::string to_string() const;
  void wait(unsigned int time);
  bool is_affordable(Upgrade_ID upgrade, int amount);
  void buy_upgrade(Upgrade_ID upgrade, int amount);

  void click();

  // Update
  void update_game_state();
};


#endif // GAME_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
