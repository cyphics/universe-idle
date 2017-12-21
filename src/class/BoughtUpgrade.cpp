// -*- compile-command: "./../../compile.sh"; -*-
// BoughtUpgrade.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/BoughtUpgrade.h"
#include "../../include/class/UpgradesList.h"

BoughtUpgrade::BoughtUpgrade(Upgrade_ID upgrade_id, std::string upgrade_name, int time_when_bought, BigNum cost)
    : _upgrade_type(upgrade_id), _upgrade_name(upgrade_name), _time(time_when_bought), _cost(cost)
{}

BoughtUpgrade::~BoughtUpgrade(){}


std::string BoughtUpgrade::to_string() const{
  std::string output = "";
  output += _upgrade_name + " : ";
  output += "bought at " + std::to_string(_time) + ", ";
  output += "at cost of " + _cost.to_string();
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
