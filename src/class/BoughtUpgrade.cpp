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
#include "../../include/helpers/game_global_variables.h"

BoughtUpgrade::BoughtUpgrade(Upgrade_ID upgrade_id, Time time_when_bought, Price cost, int amount_bought)
    : _upgrade_type(upgrade_id), _time(time_when_bought), _cost(cost), _number_bought(amount_bought)
{}

BoughtUpgrade::BoughtUpgrade(Upgrade_ID upgrade_id, Time time_when_bought, Price cost)
    : _upgrade_type(upgrade_id), _time(time_when_bought), _cost(cost), _number_bought(1)
{}

BoughtUpgrade::~BoughtUpgrade(){}


std::string BoughtUpgrade::to_string() const{
  std::string output = "";

  //  output += upgrades_manager->get_upgrade_name(_upgrade_type) + " : ";
  output += global::upgrade_name(_upgrade_type) + " : " ;
  output += "bought at " + _time.to_string() + ", ";
  output += "at cost of " + _cost.to_string();
  return output;
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
