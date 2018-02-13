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
#include "managment/GameState.h"
#include "ship/upgrades_helper.h"
#include "ship/UpgradesManager.h"
#include "main/Game.h"


enum class Strategy_ID { broken, cheapest, expensive };

namespace strategy{

Upgrade_ID strategy(Strategy_ID strategy_id, const Game* game);

}

#endif // STRATEGY_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
