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

const Upgrade& UpgradesList::get_real_upgrade(Upgrade_ID upgrade_id) const{
  //std::cout << "Get real upgrade"  << "\n";

  return get_real_upgrade(upgrade_id);
}

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
  get_real_upgrade(upgrade).increase_level(amount);
}

Price UpgradesList::get_price_increase_level(Upgrade_ID upgrade, int amount_new_levels) const{

  return get_real_upgrade(upgrade).get_cost_given_level(amount_new_levels);

}


int UpgradesList::get_upgrade_level(Upgrade_ID upgrade) const{
  return get_real_upgrade(upgrade).get_current_level();
}

std::string UpgradesList::get_upgrade_name(Upgrade_ID upgrade_id) const{
  return get_real_upgrade(upgrade_id).get_name();
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
