// Game.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/Game.h"
#include "../../include/class/Speed.h"
#include "../../include/helpers/resources_helper.h"

Game::Game(){}

Game::~Game(){}

const GameState& Game::state() const{
/**
 * Returns a constant reference to the state of the game
 */
  return _game_state;
}


Acceleration Game::compute_new_acceleration(Time time) const{
  Acceleration new_acceleration = Acceleration(state().get_acceleration());

  // Add computation...

  return new_acceleration;
}

Speed Game::compute_new_speed(Time time) const{
  /**
   * Compute speed
   */

  // WRONG CALCULATION!!
  return Speed(state().get_acceleration().get_numerical_value() * time.get_numerical_value());

}

Distance Game::compute_new_distance(Time time) const{
  /**
   * Return the distance traveled at current speed, during given time
   */

  //return Distance(time, state().get_speed());
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
