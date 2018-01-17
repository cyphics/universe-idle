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

UpgradesManager::UpgradesManager()
{
}

UpgradesManager::UpgradesManager(const UpgradesManager& original)
    :_list_of_upgrades(original._list_of_upgrades), _resources_manager(original._resources_manager)
{}

UpgradesManager::~UpgradesManager(){}

UpgradesManager& UpgradesManager::operator=(UpgradesManager& original)
{
  return original;
}

void UpgradesManager::init_manager(UpgradesList upgrades, ResourcesManager* resourcesManager)
{
  _list_of_upgrades = upgrades;
  _resources_manager = resourcesManager;
}


bool UpgradesManager::is_affordable(Upgrade_ID upgrade, unsigned int amount) const
{
  /**
   * If price of upgrade is lower that amount of resource, return true.
   */

  Price price_upgrade =  _list_of_upgrades.get_price_increase_level(upgrade, amount);
  return price_upgrade.can_be_payed(_resources_manager);
}

void UpgradesManager::buy_upgrade(Upgrade_ID upgrade, unsigned int amount, Time time_when_bought)
{
  /**
   * Increment level of upgrade, and pay price in resource manager
   */
  Price price_to_pay = _list_of_upgrades.get_price_increase_level(upgrade, amount);
  _list_of_upgrades.increase_upgrade_level(upgrade, amount);
  _resources_manager->pay_price(price_to_pay);
  _purchases_history.add_upgrade(upgrade, price_to_pay, time_when_bought);
}

const History& UpgradesManager::get_purchase_history() const
{
  /**
   * Return a constant reference to the purchase history
   */

  return _purchases_history;
}

Time UpgradesManager::time_until_affordable(Upgrade_ID upgrade, unsigned int amount) const
{
  /**
   * Take an upgrade_id and an amount of levels to increase
     Return time until purchase is available
   */

  // For now, only returns price for next level...

  Price price = _list_of_upgrades.get_price_increase_level(upgrade, 1);
  return _resources_manager->get_time_until_in_stock(price);
}

std::string UpgradesManager::get_upgrade_name(Upgrade_ID upgrade_id) const
{
  /**
   * Take an upgrade_id
     Return the name of the upgrade, as a string
   */
  return _list_of_upgrades.get_upgrade_name(upgrade_id);
}

const UpgradesList& UpgradesManager::get_list_of_upgrades() const
{
  /**
   * Return a constant reference to the list of upgrades
   */

  return _list_of_upgrades;
}

int UpgradesManager::get_upgrade_level(Upgrade_ID upgrade_id) const
{
  return get_list_of_upgrades().get_upgrade_level(upgrade_id);
}
