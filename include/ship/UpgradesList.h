// UpgradesList.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UPGRADESLIST_H
#define UPGRADESLIST_H 1

#include "ship/Upgrade.h"
#include "ship/upgrades_helper.h"

/**
 * Class that plays interface between game and upgrades
 */
class UpgradesList{
 private:
  std::vector<Upgrade> _list_of_upgrades;
  Upgrade& get_real_upgrade(Upgrade_ID);
  const Upgrade& get_real_upgrade(Upgrade_ID) const;


 public:
  UpgradesList();
  ~UpgradesList();

  void set_list_upgrades(std::vector<Upgrade>);
  // Getters
  std::vector<Upgrade_ID> get_available_upgrades() const;
  std::vector<Upgrade_ID> get_all_upgrades() const;
  Price get_price_increase_level(Upgrade_ID ugprade, int amount_new_levels) const;
  std::string get_upgrade_name(Upgrade_ID upgrade_id) const;
  int get_upgrade_level(Upgrade_ID upgrade) const;

  void increase_upgrade_level(Upgrade_ID upgrade, int amount_new_levels);


};


#endif // UPGRADESLIST_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
