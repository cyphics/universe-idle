// -*- compile-command: "./../../compile.sh"; -*-
// simulate_clicker.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "ship/Upgrade.h"
#include "main/Game.h"
#include "simulation/Simulate_game.h"
#include "simulation/Strategy.h"

using Physics::Time;

Game simulate_game(Strategy_ID strategy_id, Time duration)
{
  /**
   Function to run a game simulation fro the given
   duration with the given stragety.
   Returns a Game object corresponding to the final state of the game.
   */
  Game game = Game();
  bool loop = true;
  Time time_to_wait(0);

  while (loop)
  {
    // check if time of game is over simulation time
    if (game.state().get_time() > duration)
      loop = false;
    // else it looks for next upgrade and buys it
    else
    {
      // Identify next upgrade according to strategy

      Upgrade_ID upgrade_to_buy = strategy::strategy(strategy_id, &game);
      time_to_wait = game.time_until_affordable(upgrade_to_buy, 1);

      // Either time is over -> stop simulation
      if (time_to_wait > duration - game.state().get_time())
      {
        game.wait(duration - game.state().get_time());
        loop = false;
      }
        // Or we wait and buy
      else
      {
        game.wait(Time(time_to_wait + Time(0.1))); // Add Time(1) to avoid errors due to bad comparison


        game.buy_upgrade(upgrade_to_buy, 1);
      }
    }
  }

  return game;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
