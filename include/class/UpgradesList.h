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

/**
 * Class that plays interface between game and upgrades
 */
class UpgradesList{
 private:
  std::vector<Upgrade> _list_of_upgrades;
  Upgrade& get_real_upgrade(Upgrade_ID);


 public:
  UpgradesList();
  ~UpgradesList();

  // Getters
  std::vector<Upgrade_ID> get_available_upgrades() const;
  std::vector<Upgrade_ID> get_all_upgrades() const;
  BigNum get_price_increase_level(int amount_new_levels, Upgrade_ID ugprade);
  std::string get_name() const;
  Resource_ID get_resource(Upgrade_ID) const;

  void increase_upgrade_level(Upgrade_ID upgrade, int amount_new_levels);


};


#endif // UPGRADESLIST_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
