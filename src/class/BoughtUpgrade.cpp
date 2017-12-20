// -*- compile-command: "./../../compile.sh"; -*-
// BoughtUpgrade.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/BoughtUpgrade.h"

BoughtUpgrade::BoughtUpgrade(Upgrade related_upgrade, int time_when_bought, BigNum cost)
    : _upgrade_type(related_upgrade), _time(time_when_bought), _cost(cost)
{}

BoughtUpgrade::~BoughtUpgrade(){}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
