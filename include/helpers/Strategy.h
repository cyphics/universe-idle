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
#include "../class/GameState.h"
#include "../helpers/upgrades_helper.h"

enum class Strategy_ID { broken, cheapest, expensive };

namespace strategy{

Upgrade_ID strategy(Strategy_ID strategy_id, GameState gamestate);

}

#endif // STRATEGY_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
