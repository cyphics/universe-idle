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
    :_list_of_upgrades(original._list_of_upgrades)
{}

UpgradesManager::~UpgradesManager(){}

UpgradesManager& UpgradesManager::operator=(UpgradesManager& original)
{
  return original;
}


const History& UpgradesManager::get_purchase_history() const
{
  /**
   * Return a constant reference to the purchase history
   */

  return _purchases_history;
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
    if (is_available(upgrade.get_ID())) {
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

bool UpgradesManager::is_available(Upgrade_ID upgrade) const
{
  // If upgrade is unique and already paid, return false.
  // Otherwise, simply test dependencies

  if (get_upgrade(upgrade).is_unique() && get_upgrade(upgrade).get_current_level() > 0)
    return false;

  return has_dependencies(upgrade);

}

bool UpgradesManager::is_unique(Upgrade_ID upgrade) const
{
  return get_upgrade(upgrade).is_unique();
}

bool UpgradesManager::has_dependencies(Upgrade_ID upgrade_id) const{
  // If one of the dependencies has a level == 0, it means it hasn't been
  // bought yet, and therefore is satisfied => false. Otherwise, return true.

  for (auto dep : get_upgrade(upgrade_id).dependencies()) {
    if (get_upgrade(dep).get_current_level() == 0) {
      return false;
    }
  }
  return true;
}

bool UpgradesManager::is_bought(Upgrade_ID id) const
{
  return get_upgrade_level(id) > 0;
}

Upgrade_Type UpgradesManager::type(Upgrade_ID id) const
{
  return get_upgrade(id).type();
}

std::string UpgradesManager::get_desc(Upgrade_ID id) const
{
  return get_upgrade(id).get_desc();
}
