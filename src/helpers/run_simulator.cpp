// -*- compile-command: "./../../compile.sh"; -*-
// run_simulator.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "../../include/helpers/run_simulator.h"
#include "../../include/helpers/Simulate_game.h"
#include "../../include/class/Game.h"

void run_simulator(Time duration, Strategy_ID strategy){

  // Run simulation
  Game game = simulate_game(strategy, duration);

  // Print history of upgrades puchased
  std::cout <<  game.manage_upgrades().get_purchase_history().to_string() << "\n";

}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
