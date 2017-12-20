// -*- compile-command: "./../../compile.sh"; -*-
// simulate_clicker.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/helpers/Simulate_game.h"
#include "../../include/class/Upgrade.h"

#include "../../include/helpers/Strategy.h"


Game simulate_game(std::string strategy_name, unsigned int duration){
  /**
   Function to run a game simulation fro the given
   duration with the given stragety.
   Returns a Game object corresponding to the final state of the game.
   */

  Game game = Game();
  bool loop = true;
  int time_to_wait = 0;
  while (loop) {
    if (game.get_time() > duration)
      loop = false;
    else{
      // Identify next upgrade according to strategy
      Upgrade upgrade_to_buy = strategy::strategy(strategy_name, game.get_gamestate());


      if (upgrade_to_buy.get_name() == "None") {
        game.wait(duration - game.get_time());
        loop = false;
      }
      else {
        time_to_wait = game.time_until(upgrade_to_buy);
        if (time_to_wait > duration - game.get_time()) {
          game.wait(duration - game.get_time());
          loop = false;
        }
        else {
          game.wait(time_to_wait);
          game.buy_upgrade(upgrade_to_buy);
        }
      }
    }
  }

  return game;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
