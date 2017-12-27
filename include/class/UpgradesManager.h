// -*- compile-command: "./compile.sh"; -*-
// PurchaseManager.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UPGRADESMANAGER_H
#define UPGRADESMANAGER_H 1

#include "UpgradesList.h"
#include "ResourcesManager.h"
#include "History.h"
#include "Time.h"
#include "../helpers/upgrades_helper.h"
//#include "../helpers/resources_helper.h"

class ResourcesManager;

class UpgradesManager{
  /**
   * Class that  manages the purchases of upgrades.

     Gets a pointer to the list of upgrades of the game
     and a resource manager
   */

 private:
  UpgradesList* _list_of_upgrades;
  ResourcesManager* _resources_manager;
  History _purchases_history;

 public:
  UpgradesManager(UpgradesList*, ResourcesManager*);
  ~UpgradesManager();

  // Getters
  const History& get_purchase_history() const;
  Time time_until_affordable(Upgrade_ID upgrade, unsigned int amount) const;
  std::string get_upgrade_name(Upgrade_ID) const;
  bool is_affordable(Upgrade_ID upgrade, unsigned int amount) const;
  const UpgradesList* get_list_of_upgrades() const;

  void buy_upgrade(Upgrade_ID upgrade, unsigned int amount);
};


#endif // PURCHASEMANAGER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
