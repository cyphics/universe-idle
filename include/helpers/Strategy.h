// -*- compile-command: "./../../compile.sh"; -*-
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef STRATEGY_H
#define STRATEGY_H 1

#include <iostream>
#include "../class/Upgrade.h"
#include "../class/GameState.h"

namespace strategy{

Upgrade strategy(std::string strategy_name, GameState gamestate);
}

#endif // STRATEGY_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
