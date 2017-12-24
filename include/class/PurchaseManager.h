// -*- compile-command: "./compile.sh"; -*-
// PurchaseManager.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef PURCHASEMANAGER_H
#define PURCHASEMANAGER_H 1

#include "UpgradesList.h"
#include "ResourcesList.h"
#include "History.h"
#include "Time.h"
#include "Price.h"
#include "../helpers/upgrades_helper.h"
#include "../helpers/resources_helper.h"

class PurchaseManager{
  /**
   * Class that manages the amount of resources, the purchases of upgrades
   */

 private:
  UpgradesList _upgrades_list;
  ResourcesList _resources_list;
  History _purchases_history;

 public:
  PurchaseManager(UpgradesList&, ResourcesList&);
  ~PurchaseManager();

  bool is_affordable(Upgrade_ID upgrade, unsigned int amount) const;
  const History& get_purchase_history() const;
  Time time_until_affordable(Upgrade_ID upgrade, unsigned int amount) const;
  std::string get_upgrade_name(Upgrade_ID) const;

  void buy_upgrade(Upgrade_ID upgrade, unsigned int amount);
};


#endif // PURCHASEMANAGER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
