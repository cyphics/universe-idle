// -*- compile-command: "./../../compile.sh"; -*-
// Strategies.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "managment/GameState.h"
#include "simulation/Strategy.h"
#include "physics/Time.h"

using Physics::Time;

Upgrade_ID strategy::strategy(Strategy_ID strategy_id, const UpgradesManager* upgrades_manager)
{
  /**
   * Return the best upgrade to buy according to strategy
   */

  switch (strategy_id)
  {
    case Strategy_ID::broken:
      {
        return Upgrade_ID::boost_1;
        break;
      }
    case Strategy_ID::cheapest:
      {
        Time remaining_time(BigNum(1, 99)); // arbitrarily huge value
        Upgrade_ID good_ID;

        for (auto upgrade_id: upgrades_manager->get_available_upgrades()) {
          Time buy_time = upgrades_manager->time_until_affordable(upgrade_id, 1);
          if (buy_time < remaining_time)
          {
            remaining_time = buy_time;
            good_ID = upgrade_id;
          }
        }
        return good_ID;
      break;
      }
    default:
      std::cout << "ERROR: Strategy returned nothing!"  << "\n";
      break;
  }

}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
