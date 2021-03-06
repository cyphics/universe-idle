// BoughtUpgrade.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef BOUGHTUPGRADE_H
#define BOUGHTUPGRADE_H 1

#include "ship/upgrades_helper.h"
#include "ship/Price.h"
#include "physics/Time.h"

class BoughtUpgrade{
  /**
   * Class used to store history of bought upgrades
   */
 private:
  Upgrade_ID _upgrade_type;
  Physics::Time _time;
  Price _cost;
  int _number_bought;


 public:
  BoughtUpgrade(Upgrade_ID related_upgrade, Physics::Time time_when_bought, Price price, int amount_mought);
  BoughtUpgrade(Upgrade_ID related_upgrade, Physics::Time time_when_bought, Price price);
  ~BoughtUpgrade();

  std::string to_string() const;

};

#endif // BOUGHTUPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
