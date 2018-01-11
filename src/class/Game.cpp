
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
#include "../../include/helpers/Initiate.h"

Game::Game()
{
  std::cout << "Creation of the Game instance..."  << "\n";
  _stock_of_resources = Init::initiate_resources_list();
  _list_of_upgrades = Init::initiate_upgrades_list();

  _resources_manager.init_manager(_stock_of_resources, &_upgrades_manager);
  _upgrades_manager.init_manager(_list_of_upgrades, &_resources_manager);
  std::cout << "Game instance created!"  << "\n";
}

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
  BigNum acceleration = state().get_acceleration().get_numerical_value();
  Speed speed = Speed(acceleration * time.get_numerical_value());
  return speed;

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

  _resources_manager.gather_resources(time);
}

void Game::buy_upgrade(Upgrade_ID upgrade, int amount){
  /**
   * Add ugprade if possible
     If not, do nothing
   */
  std::cout << "about to buy"  << "\n";
  if (_upgrades_manager.is_affordable(upgrade, amount)) {
    std::cout << "affordable"  << "\n";
    _upgrades_manager.buy_upgrade(upgrade, amount);
  }
  else{
    std::cout << "Upgrade " << _upgrades_manager.get_upgrade_name(upgrade) << " (x" << std::to_string(amount) << ")  is too expensive."  << "\n";
  }
}

void Game::click(){
  /**
   *
   */
}

const UpgradesManager& Game::manage_upgrades() const{
  return _upgrades_manager;
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
