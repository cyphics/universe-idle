// -*- compile-command: "./../../compile.sh"; -*-
// simulate_clicker.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/Upgrade.h"
#include "../../include/class/Game.h"
#include "../../include/helpers/Simulate_game.h"
#include "../../include/helpers/Strategy.h"

Game simulate_game(Strategy_ID strategy_id, Time duration){
  /**
   Function to run a game simulation fro the given
   duration with the given stragety.
   Returns a Game object corresponding to the final state of the game.
   */
  Game game = Game();
  bool loop = true;
  Time time_to_wait(0);
  while (loop) {
    // check if time of game is over simulation time
    if (game.state().get_time() > duration)
      loop = false;
    // else it looks for next upgrade and buys it
    else{
      // Identify next upgrade according to strategy
      Upgrade_ID upgrade_to_buy = strategy::strategy(strategy_id, game.state());

      time_to_wait = game.manage_upgrades()->time_until_affordable(upgrade_to_buy, 1);
      // Either time is over -> stop simulation
      if (time_to_wait > duration - game.state().get_time()) {
        game.wait(duration - game.state().get_time());
        loop = false;
      }
        // Or we wait and buy
      else {
        std::cout << ""  << "\n";
        std::cout << "Next price: " << game.manage_upgrades()->get_list_of_upgrades().get_price_increase_level(upgrade_to_buy, 1).to_string()  << "\n";
        std::cout << "Current amount: " << game.manage_resources()->get_resource_amount(Resource_ID::cinetic_energy)  << "\n";
        std::cout << "Waiting " << time_to_wait.to_string()  << "\n";
        game.wait(Time(time_to_wait + Time(1))); // Add Time(1) to avoid errors due to bad comparison

        std::cout << "New amount: " << game.manage_resources()->get_resource_amount(Resource_ID::cinetic_energy)  << "\n";

        game.buy_upgrade(upgrade_to_buy, 1);
      }
    }
  }

  return game;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
