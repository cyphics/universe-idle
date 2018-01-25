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
#include "ship/UpgradesManager.h"
#include "ship/ResourcesManager.h"

using Physics::Time;

UpgradesManager::UpgradesManager(std::vector<Upgrade> list_upgrades)
{
  _list_of_upgrades = list_upgrades;
}

UpgradesManager::UpgradesManager(const UpgradesManager& original)
    :_list_of_upgrades(original._list_of_upgrades), _resources_manager(original._resources_manager)
{}

UpgradesManager::~UpgradesManager(){}

UpgradesManager& UpgradesManager::operator=(UpgradesManager& original)
{
  return original;
}

void UpgradesManager::set_resources_manager(ResourcesManager* resourcesManager)
{
  _resources_manager = resourcesManager;
}


bool UpgradesManager::is_affordable(Upgrade_ID upgrade, unsigned int amount) const
{
  /**
   * If price of upgrade is lower that amount of resource, return true.
   */

  Price price_upgrade =  get_price_increase_level(upgrade, amount);
  return price_upgrade.can_be_payed(_resources_manager);
}

void UpgradesManager::buy_upgrade(Upgrade_ID upgrade, unsigned int amount, Time time_when_bought)
{
  /**
   * Increment level of upgrade, and pay price in resource manager
   */
  Price price_to_pay = get_price_increase_level(upgrade, amount);
  increase_upgrade_level(upgrade, amount);
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
  Price price = get_price_increase_level(upgrade, 1);
  return _resources_manager->get_time_until_in_stock(price);
}

std::string UpgradesManager::get_upgrade_name(Upgrade_ID upgrade_id) const
{
  /**
   * Take an upgrade_id
     Return the name of the upgrade, as a string
   */
  return get_upgrade(upgrade_id).get_name();
}


int UpgradesManager::get_upgrade_level(Upgrade_ID upgrade_id) const
{
  return get_upgrade(upgrade_id).get_current_level();
}


Price UpgradesManager::get_price_increase_level(Upgrade_ID upgrade_id, int amount_new_levels) const
{
  return get_upgrade(upgrade_id).get_cost_increase_level(amount_new_levels);
}


void UpgradesManager::increase_upgrade_level(Upgrade_ID upgrade, int amount_new_levels)
{
  get_upgrade(upgrade).increase_level(amount_new_levels);
}


std::vector<Upgrade_ID> UpgradesManager::get_available_upgrades() const
{
  std::vector<Upgrade_ID> available_upgrades;
  for (auto upgrade : _list_of_upgrades) {
    if (upgrade.is_available()) {
      available_upgrades.push_back(upgrade.get_ID());
    }
  }
  return available_upgrades;

}

std::vector<Upgrade_ID> UpgradesManager::get_all_upgrades() const
{
  /**
   * Return vector containing all upgrades
   */
  std::vector<Upgrade_ID> upgrade_vector;

  for (auto upgrade : _list_of_upgrades) {
    upgrade_vector.push_back(upgrade.get_ID());
  }

  return upgrade_vector;

}

Upgrade& UpgradesManager::get_upgrade(Upgrade_ID upgrade_id)
{
  for (auto &upgrade : _list_of_upgrades)
  {
    if (upgrade.has_id(upgrade_id))
    {
      return upgrade;
    }
  }
}

const Upgrade& UpgradesManager::get_upgrade(Upgrade_ID upgrade_id) const
{
  for (auto &upgrade : _list_of_upgrades)
  {
    if (upgrade.has_id(upgrade_id))
    {
      return upgrade;
    }
  }
}
