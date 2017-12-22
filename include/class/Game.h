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

class Game{
 private:

  GameState _game_state;
  PurchaseManager _purchase_manager;

 public:
  // Constructor
  Game();
  ~Game();

  // Getters
  BigNum get_distance() const;
  BigNum get_speed() const;
  BigNum get_acceleration() const;
  //BigNum get_resource_amount(Resource_ID) const;
  GameState get_gamestate() const;
  History get_history() const;

  // Setters
  void set_distance();
  void set_speed();
  void set_acceleration();
  void set_time();
  const GameState& state() const;
  Time time_until(Upgrade_ID next_upgrade) const;

  // Compute game state
  BigNum compute_new_acceleration(Time time) const;
  BigNum compute_new_speed(Time time) const;
  BigNum compute_new_distance(Time time) const;

  // Misc
  std::string to_string() const;
  void wait(Time time);
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
