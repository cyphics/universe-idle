// -*- compile-command: "./../../compile.sh"; -*-
// UpgradesList.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UPGRADESLIST_H
#define UPGRADESLIST_H 1

#include "Upgrade.h"
#include "../helpers/upgrades_helper.h"

class UpgradesList{
 private:
  std::vector<Upgrade> _list_of_upgrades;

 public:
  UpgradesList();
  ~UpgradesList();

  // Getters
  std::vector<Upgrade_ID> get_available_upgrades() const;
  std::vector<Upgrade_ID> get_all_upgrades() const;
  BigNum get_price_increase_level(int amount_new_levels, Upgrade_ID ugprade);

  void increase_upgrade_level(int amount_new_levels, Upgrade_ID upgrade);

  //Upgrade get_upgrade(std::string name) const;

};


#endif // UPGRADESLIST_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
