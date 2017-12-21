// -*- compile-command: "./../../compile.sh"; -*-
// Strategies.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "../../include/class/GameState.h"
#include "../../include/helpers/Strategy.h"


Upgrade_ID strategy::strategy(Strategy_ID strategy_id, GameState gamestate){
  /**
   * Return the best upgrade to buy according to strategy
   */
  if (strategy_id == Strategy_ID::broken)
    return Upgrade_ID::empty_upgrade;

}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
