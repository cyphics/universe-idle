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
    std::cout << "LOOP"  << "\n";
    if (game.state().get_time() > duration)
      loop = false;
    else{
      // Identify next upgrade according to strategy
      Upgrade_ID upgrade_to_buy = strategy::strategy(strategy_id, game.state());

      // Useless debug case
      if (upgrade_to_buy == Upgrade_ID::empty_upgrade) {
        Time wait_time = duration;
        game.wait(duration);// - game.state().get_time());
        loop = false;
      }
      // PURCHASE LOOP
      else {

        time_to_wait = game.manage_upgrades()->time_until_affordable(upgrade_to_buy, 1);

        // Either time is over -> stop simulation
        if (time_to_wait > duration - game.state().get_time()) {
          game.wait(duration - game.state().get_time());
          loop = false;
        }
        // Or we wait and buy
        else {
          game.wait(Time(10));
          std::cout << "Game time: " << game.state().get_time().get_numerical_value()  << "\n";
          game.buy_upgrade(upgrade_to_buy, 1);
        }
      }
    }
  }

  return game;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
