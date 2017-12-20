// -*- compile-command: "./../../compile.sh"; -*-
// Strategies.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "../../include/class/Upgrade.h"
#include "../../include/class/GameState.h"
#include "../../include/helpers/Strategy.h"


std::string strategy::strategy(std::string strategy_name, GameState gamestate){
  /**
   * Return the best upgrade to buy according to strategy
   */
  if (strategy_name == "broken")
    return "Small boost";

}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
