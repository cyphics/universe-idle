// -*- compile-command: "./../../compile.sh"; -*-
// Game.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/Game.h"
#include "../../include/helpers/resources_helper.h"

Game::Game(){}
Game::~Game(){}


const GameState& Game::state() const{
/**
 * Returns a constant reference to the state of the game
 */
  return _game_state;
}


BigNum Game::compute_new_acceleration(Time time) const{
  BigNum new_acceleration;
  return new_acceleration;
}

BigNum Game::compute_new_speed(Time time) const{
  BigNum new_speed;
  //new_speed += _current_acceleration;
  return new_speed;
}

BigNum Game::compute_new_distance(Time time) const{
  BigNum new_distance;
  return new_distance;
}


void Game::wait(Time time){
  /**
   * Postpone game state to given time
   */
  _game_state.increase_time(time);
}

void Game::buy_upgrade(Upgrade_ID upgrade, int amount){
  /**
   * Add ugprade if possible
     If not, do nothing
   */
  if (_purchase_manager.is_affordable(upgrade, amount)) {
    _purchase_manager.buy_upgrade(upgrade, amount);
  }
  else{
    std::cout << "Upgrade " << _purchase_manager.get_upgrade_name(upgrade) << " (x" << std::to_string(amount) << ")  is too expensive."  << "\n";
  }
}

void Game::click(){
  /**
   *
   */
}

const PurchaseManager& Game::manage_purchase() const{
  return _purchase_manager;
}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
