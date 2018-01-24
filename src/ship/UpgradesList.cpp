// -*- compile-command: "./../../compile.sh"; -*-
// UpgradesList.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "ship/UpgradesList.h"

UpgradesList::UpgradesList()
{
}

UpgradesList::~UpgradesList(){}

void UpgradesList::set_list_upgrades(std::vector<Upgrade> list_of_upgrades)
{
  _list_of_upgrades = list_of_upgrades;
}

// CORRIGER LES DEUX get_real_upgrade
Upgrade& UpgradesList::get_real_upgrade(Upgrade_ID upgrade_id)
{
  /**
   * Return copy of
   */

  for (auto &upgrade : _list_of_upgrades)
  {
    if (upgrade.has_id(upgrade_id))
    {
      return upgrade;
    }
  }
  // Should never reach that point
}

const Upgrade& UpgradesList::get_real_upgrade(Upgrade_ID upgrade_id) const
{
  for (auto &upgrade : _list_of_upgrades)
  {
    if (upgrade.has_id(upgrade_id))
    {
      return upgrade;
    }
  }

}

std::vector<Upgrade_ID> UpgradesList::get_all_upgrades() const
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

std::vector<Upgrade_ID> UpgradesList::get_available_upgrades() const
{
  std::vector<Upgrade_ID> available_upgrades;
  for (auto upgrade : _list_of_upgrades) {
    if (upgrade.is_available()) {
      available_upgrades.push_back(upgrade.get_ID());
    }
  }
  return available_upgrades;
}


void UpgradesList::increase_upgrade_level(Upgrade_ID upgrade, int amount)
{
  get_real_upgrade(upgrade).increase_level(amount);
}

Price UpgradesList::get_price_increase_level(Upgrade_ID upgrade_id, int amount_new_levels) const
{
  return get_real_upgrade(upgrade_id).get_cost_increase_level(amount_new_levels);
}


int UpgradesList::get_upgrade_level(Upgrade_ID upgrade) const
{
  return get_real_upgrade(upgrade).get_current_level();
}

std::string UpgradesList::get_upgrade_name(Upgrade_ID upgrade_id) const
{
  return get_real_upgrade(upgrade_id).get_name();
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
