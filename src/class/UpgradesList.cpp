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

  //_list_of_upgrades.push_back(Upgrade(Upgrade_ID::small_boost, "small boost", BigNum(10), 1.1));
}

UpgradesList::~UpgradesList(){}

Upgrade& UpgradesList::get_real_upgrade(Upgrade_ID upgrade_id){
  /**
   * Return copy of
   */
  for (auto &upgrade : _list_of_upgrades) {
    if (upgrade.has_id(upgrade_id)) {
      return upgrade;
    }
  }
  // Should never reach that point
}

// Upgrade& get_real_upgrade(Upgrade_ID upgrade_id){
//   return get_real_upgrade(upgrade_id);
// }

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


void UpgradesList::increase_upgrade_level(Upgrade_ID upgrade, int amount){

}

Price UpgradesList::get_price_increase_level(Upgrade_ID ugprade, int amount_new_levels) const{

}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
