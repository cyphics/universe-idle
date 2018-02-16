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
#include "physics/Speed.h"
#include "ship/resources_helper.h"
#include "main/game_configuration.h"
#include "ship/computations.h"

using Physics::Time;
using Physics::Speed;
using Physics::Distance;




Game::Game()
    :_resources(Init::initiate_resources_manager()),
     _upgrades(Init::initiate_upgrades_manager()),
     _computer(&_upgrades, &_game_state)
{
  _resources.add_resource_amount(Resource_ID::kinetic_energy, GameConfig::initial_game_resources);
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

const UpgradesManager* Game::upgrades() const
{
  return &_upgrades;
}

const ResourcesManager* Game::resources() const
{
  return &_resources;
}

Physics::Time Game::time_until_affordable(Upgrade_ID upgrade, unsigned int amount) const
{
  Price price = _upgrades.get_price_increase_level(upgrade, amount);
  return time_until_in_stock(price);
}

Physics::Time Game::time_until_in_stock(const Resource_ID& resource_id, BigNum required_amount) const
{
  Time time(0);
  BigNum current_amount = _resources.get_resource_amount(resource_id);
  BigNum needed_amount = required_amount - current_amount;

  // Compute
  if (needed_amount > 0)
  {
    BigNum resource_per_second = _computer.resource_per_second(resource_id);
    time = Time(needed_amount/resource_per_second);
  }
  return time;
}

Physics::Time Game::time_until_in_stock(const Price& price) const
{
    Time time(0);

    for (auto resourceAmount : price.get_resources_to_pay())
    {
      Time remain_time = time_until_in_stock(resourceAmount._resource_ID, resourceAmount._amount);
      if (remain_time > time)
      {
        time = remain_time;
      }
    }

    return time;
}

bool Game::is_affordable(Upgrade_ID upgrade, int amount) const
{
  Price price_upgrade =  _upgrades.get_price_increase_level(upgrade, amount);
  return _resources.can_be_payed(price_upgrade);
}

const Computer& Game::compute() const
{
  return _computer;
}


void Game::update_state()
{
  state().set_acceleration(compute().current_acceleration());
}


void Game::wait(Time time)
{
  /**
   * Postpone game state to given time
   */

  _game_state.increase_time(time);
  state().set_speed(compute().new_speed(time));
  state().add_distance(compute().traveled_distance(time));
  gather_resources(time);

  update_state();
}


void Game::buy_upgrade(Upgrade_ID upgrade, int amount)
{
  /**
   * Add upgrade if possible
     If not, do nothing
   */
  if (is_affordable(upgrade, amount))
  {
    _upgrades.increase_upgrade_level(upgrade, amount);
    _resources.pay_price(_upgrades.get_price_increase_level(upgrade, amount));
    // FIXME: ADD ENTRY TO HISTORY
    //_upgrades_manager.buy_upgrade(upgrade, amount, state().get_time());
  }
  else
  {
    std::cout << "Upgrade " << _upgrades.get_upgrade_name(upgrade) << " (x" << std::to_string(amount) << ")  is too expensive."  << "\n";
    BigNum cost = _upgrades.get_price_increase_level(upgrade, amount).get_resource_amount(Resource_ID::kinetic_energy);
    BigNum current_amount = _resources.get_resource_amount(Resource_ID::kinetic_energy);
    std::cout << current_amount << " < " << cost  << "\n";
  }
}

void Game::gather_resources(Physics::Time time)
{
    for (auto resource : _resources.get_resources())
    {
      BigNum resource_per_second = compute().resource_per_second(resource.get_ID());
      BigNum new_amount(0);
      new_amount = BigNum(resource_per_second * time.num());

      _resources.add_resource_amount(resource.get_ID(), new_amount);
    }

}

void Game::click()
{
  /**
   *
   */
  BigNum new_amount = 1;

  _resources.add_resource_amount(Resource_ID::kinetic_energy, BigNum(GameConfig::global_multiplier));

  if (_upgrades.is_bought(Upgrade_ID::u_kinetic_impulsor)) {
    state().add_speed(Speed(
        GameConfig::Computations::kinetic_impulsor_speed_gain *
        GameConfig::global_multiplier));
  }

}



std::vector<std::string> Game::ui_data()
{
  std::vector<std::string> data;
  data.push_back(_resources.get_resource_amount(Resource_ID::kinetic_energy).to_string());

  return data;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
