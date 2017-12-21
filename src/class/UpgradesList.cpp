// -*- compile-command: "./../../compile.sh"; -*-
// UpgradesList.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/UpgradesList.h"

UpgradesList::UpgradesList(){
  /**
   * Constructor that sequentially adds all upgrades to vector
   */

  _list_of_upgrades.push_back(Upgrade(Upgrade_ID::small_boost, BigNum(10), 1.1));
}

UpgradesList::~UpgradesList(){}

std::vector<Upgrade_ID> UpgradesList::get_all_upgrades() const{
  /**
   * Return vector containing all upgrades
   */
  //return _list_of_upgrades;
}

std::vector<Upgrade_ID> UpgradesList::get_available_upgrades() const{
  std::vector<Upgrade_ID> available_upgrades;

  return available_upgrades;
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
