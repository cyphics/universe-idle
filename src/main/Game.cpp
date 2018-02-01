// Game.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////


#include <cmath>
#include "main/Game.h"
#include "main/initiate.h"
#include "main/game_global_variables.h"
#include "physics/Speed.h"
#include "ship/resources_helper.h"
#include "ship/computations.h"

using Physics::Time;
using Physics::Speed;
using Physics::Distance;

Game::Game()
    :_resources_manager(Init::initiate_resources_manager()),
     _upgrades_manager(Init::initiate_upgrades_manager())
{
  _resources_manager.set_upgrades_manager(&_upgrades_manager);
  _upgrades_manager.set_resources_manager(&_resources_manager);

  _resources_manager.add_resource_amount(Resource_ID::cinetic_energy, BigNum(10));

}

Game::~Game(){}

const GameState& Game::state() const
{
/**
 * Returns a constant reference to the state of the game
 */
  return _game_state;
}

GameState& Game::state()
{
  return _game_state;
}

Speed Game::compute_new_speed(Time time) const
{
  // final_speed = (acceleration * time) + initial_speed
  Speed new_speed = (state().get_acceleration().num() * time.num()) + state().get_speed().num();

  return new_speed;
}

Distance Game::compute_new_distance(Time time) const
{
  /**
   * Return the distance traveled at current speed, during given time
   */

  // dist = init_speed * time + 1/2 acceleration * time^2

  Distance new_dist = state().get_speed().num() * time.num() \
                      + 0.5 * state().get_acceleration().num() \
                      * time.num() * time.num();
  return new_dist;
}


void Game::wait(Time time)
{
  /**
   * Postpone game state to given time
   */

  _game_state.increase_time(time);
  state().set_speed(compute_new_speed(time));
  state().add_distance(compute_new_distance(time));
  _resources_manager.gather_resources(time);
  update_state();
}

void Game::buy_upgrade(Upgrade_ID upgrade, int amount)
{
  /**
   * Add upgrade if possible
     If not, do nothing
   */
  if (_upgrades_manager.is_affordable(upgrade, amount))
  {
    _upgrades_manager.buy_upgrade(upgrade, amount, state().get_time());
  }
  else
  {
    std::cout << "Upgrade " << _upgrades_manager.get_upgrade_name(upgrade) << " (x" << std::to_string(amount) << ")  is too expensive."  << "\n";
    BigNum cost = _upgrades_manager.get_price_increase_level(upgrade, amount).get_resource_amount(Resource_ID::cinetic_energy);
    BigNum current_amount = _resources_manager.get_resource_amount(Resource_ID::cinetic_energy);
    std::cout << current_amount << " < " << cost  << "\n";
  }
}

void Game::click()
{
  /**
   *
   */

  BigNum new_amount = 1;
  int click_level = manage_upgrades()->get_upgrade_level(Upgrade_ID::unique_upgrade_1);
  //state().add_speed(Speed(1) *( 1 + ( click_level * 10 ) ));
  //  std::cout << state().get_speed().to_string() << "\n";
  _resources_manager.add_resource_amount(Resource_ID::cinetic_energy, BigNum(1));
}

const UpgradesManager* Game::manage_upgrades() const
{
  return &_upgrades_manager;
}

const ResourcesManager* Game::manage_resources() const
{
  return &_resources_manager;
}

void Game::update_state()
{
  state().set_acceleration(computation::compute_current_acceleration(&_upgrades_manager));

}

std::vector<std::string> Game::ui_data()
{
  std::vector<std::string> data;
  data.push_back(_resources_manager.get_resource_amount(Resource_ID::cinetic_energy).to_string());

  return data;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
