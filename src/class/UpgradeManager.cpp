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
#include "../../include/class/UpgradesManager.h"
#include "../../include/class/ResourcesManager.h"

// UpgradesManager::UpgradesManager(UpgradesList& upgrades_list, ResourcesManager& resources_manager)
//     : _list_of_upgrades(upgrades_list), _resources_manager(resources_manager)
// {}

UpgradesManager::UpgradesManager(){}

UpgradesManager::UpgradesManager(const UpgradesManager& original)
    :_list_of_upgrades(original._list_of_upgrades), _resources_manager(original._resources_manager)
{}

UpgradesManager::~UpgradesManager(){}

UpgradesManager& UpgradesManager::operator=(UpgradesManager& original){
  return original;
}

void UpgradesManager::init_manager(UpgradesList upgrades, ResourcesManager* resourcesManager){
  _list_of_upgrades = upgrades;
  _resources_manager = resourcesManager;
}


bool UpgradesManager::is_affordable(Upgrade_ID upgrade, unsigned int amount) const{
  /**
   * If price of upgrade is lower that amount of resource, return true.
   */
  Price price_upgrade =  _list_of_upgrades.get_price_increase_level(upgrade, amount);

  return price_upgrade.can_be_payed(_resources_manager);
}

void UpgradesManager::buy_upgrade(Upgrade_ID upgrade, unsigned int amount){
  /**
   * Store amount of upgrade in the vector list
   */
  _list_of_upgrades.increase_upgrade_level(upgrade, amount);
}

const History& UpgradesManager::get_purchase_history() const{
  /**
   * Return a constant reference to the purchase history
   */
  return _purchases_history;
}

Time UpgradesManager::time_until_affordable(Upgrade_ID upgrade, unsigned int amount) const{

  //Upgrade upgrade = get_list_of_upgrades()->
  _list_of_upgrades.get_price_increase_level(upgrade, 1);
  Price price = _list_of_upgrades.get_price_increase_level(upgrade, amount);

  return _resources_manager->get_time_until_in_stock(price);
}

std::string UpgradesManager::get_upgrade_name(Upgrade_ID upgrade_id) const{
  return _list_of_upgrades.get_upgrade_name(upgrade_id);
}

const UpgradesList& UpgradesManager::get_list_of_upgrades() const{
  return _list_of_upgrades;
}
