// PurchaseManager.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UPGRADESMANAGER_H
#define UPGRADESMANAGER_H 1

#include "ship/Upgrade.h"
#include "managment/History.h"
#include "ship/upgrades_helper.h"

class UpgradesManager{
  /**
   * Class that  manages the purchases of upgrades.

     Gets a reference to the list of upgrades of the game
     and a resource manager
   */

 private:
  std::vector<Upgrade> _list_of_upgrades;
  History _purchases_history;
  Upgrade& get_upgrade(Upgrade_ID upgrade_id);
  const Upgrade& get_upgrade(Upgrade_ID upgrade_id) const;

 public:
  UpgradesManager(std::vector<Upgrade>);
  UpgradesManager(const UpgradesManager& original);
  ~UpgradesManager();
  UpgradesManager& operator=(UpgradesManager&);

  // Getters
  const History& get_purchase_history() const;
  std::string get_upgrade_name(Upgrade_ID) const;
  bool is_available(Upgrade_ID upgrade) const;
  bool is_unique(Upgrade_ID upgrade) const;
  bool has_dependencies(Upgrade_ID) const;
  bool is_bought(Upgrade_ID) const;
  int get_upgrade_level(Upgrade_ID) const;
  std::vector<Upgrade_ID> get_available_upgrades() const;
  std::vector<Upgrade_ID> get_all_upgrades() const;
  Price get_price_increase_level(Upgrade_ID upgrade, int amount_new_levels) const;
  void increase_upgrade_level(Upgrade_ID upgrade, int amount_new_levels);

};


#endif // PURCHASEMANAGER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
