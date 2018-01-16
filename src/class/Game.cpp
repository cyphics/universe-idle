
// Game.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////


#include <cmath>
#include "../../include/class/Game.h"
#include "../../include/class/Speed.h"
#include "../../include/helpers/resources_helper.h"
#include "../../include/helpers/Initiate.h"
#include "../../include/helpers/game_global_variables.h"
#include "../../include/helpers/computations.h"

Game::Game()
    :_stock_of_resources(Init::initiate_resources_list()),
     _list_of_upgrades(Init::initiate_upgrades_list())
{
  //std::cout << "Creation of the Game instance..."  << "\n";

  _resources_manager.init_manager(_stock_of_resources, &_upgrades_manager);
  _upgrades_manager.init_manager(_list_of_upgrades, &_resources_manager);

  _resources_manager.add_resource_amount(Resource_ID::cinetic_energy, BigNum(10));

  //std::cout << "Game instance created!"  << "\n";
}

Game::~Game(){}

const GameState& Game::state() const{
/**
 * Returns a constant reference to the state of the game
 */
  return _game_state;
}

GameState& Game::state(){
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

  // final_speed = (acceleration * time) + initial_speed
  Speed new_speed = (state().get_acceleration().num() * time.num()) + state().get_speed().num();

  return new_speed;

}

Distance Game::compute_new_distance(Time time) const{
  /**
   * Return the distance traveled at current speed, during given time
   */



// dist = init_speed * time + 1/2 acceleration * time^2
  Distance new_dist = state().get_speed().num() * time.num() + 0.5 * state().get_acceleration().num() * time.num() * time.num();

  return new_dist;
}


void Game::wait(Time time){
  /**
   * Postpone game state to given time
   */
  _game_state.increase_time(time);
  state().set_speed(compute_new_speed(time));
  state().set_distance(compute_new_distance(time));
  _resources_manager.gather_resources(time);
}

void Game::buy_upgrade(Upgrade_ID upgrade, int amount){
  /**
   * Add ugprade if possible
     If not, do nothing
   */
  if (_upgrades_manager.is_affordable(upgrade, amount)) {
    //std::cout << "Buy upgrade " << global::upgrade_name(upgrade) << "\n";
    _upgrades_manager.buy_upgrade(upgrade, amount, state().get_time());
    //std::cout << "Remaining resource: " << _resources_manager.get_resource_amount(Resource_ID::cinetic_energy)  << "\n";

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

const UpgradesManager* Game::manage_upgrades() const{
  return &_upgrades_manager;
}

const ResourcesManager* Game::manage_resources() const{
  return &_resources_manager;
}

void Game::update_state(){
  state().set_acceleration(computation::get_current_acceleration(&_upgrades_manager));

}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
