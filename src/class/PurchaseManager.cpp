// -*- compile-command: "./compile.sh"; -*-
// PurchaseManager.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// $Log:$
//
#include "../../include/class/PurchaseManager.h"

PurchaseManager::PurchaseManager(UpgradesList& upgrades_list, ResourcesList& resources_list)
    : _upgrades_list(upgrades_list), _resources_list(resources_list)
{}
PurchaseManager::~PurchaseManager(){}

bool PurchaseManager::is_affordable(Upgrade_ID upgrade, unsigned int amount) const{
  /**
   * If price of upgrade is lower that amount of resource, return true.
   */
  Price price_upgrade =  _upgrades_list.get_price_increase_level(upgrade, amount);

  return price_upgrade.can_be_payed(_resources_list);

}

void PurchaseManager::buy_upgrade(Upgrade_ID upgrade, unsigned int amount){
  /**
   * Store amount of upgrade in the vector list
   */

  _upgrades_list.increase_upgrade_level(upgrade, amount);
}

const History& PurchaseManager::get_purchase_history() const{
  /**
   * Return a constant reference to the purchase history
   */
  return _purchases_history;
}

Time PurchaseManager::time_until_affordable(Upgrade_ID upgrade, unsigned int amount) const{
  return Time(1000);
}

std::string PurchaseManager::get_upgrade_name(Upgrade_ID) const{

}
