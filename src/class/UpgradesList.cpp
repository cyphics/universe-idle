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
  Upgrade first_upgrade = Upgrade("first boost", BigNum(10), 1.1);

}

UpgradesList::~UpgradesList(){}

std::vector<Upgrade> UpgradesList::get_all_upgrades() const{
  return _list_of_upgrades;
}

std::vector<Upgrade> UpgradesList::get_available_upgrades() const{
  std::vector<Upgrade> available_upgrades;

  return available_upgrades;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
