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

void run_simulator(int duration, Strategy_ID strategy){

  Game game = simulate_game(strategy, duration);
  std::cout <<  game.get_history().to_string() << "\n";

}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
