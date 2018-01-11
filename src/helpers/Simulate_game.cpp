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
      else {
        time_to_wait = game.manage_upgrades().time_until_affordable(upgrade_to_buy, 1);
        if (time_to_wait > duration - game.state().get_time()) {
          game.wait(duration - game.state().get_time());
          loop = false;
        }
        else {
          game.wait(time_to_wait);
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
