// -*- compile-command: "./../compile.sh"; -*-
// BoughtUpgrade.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef BOUGHTUPGRADE_H
#define BOUGHTUPGRADE_H 1

#include "Upgrade.h"

class BoughtUpgrade{
  /**
   * Class used to store history of bought upgrades
   */
 private:
  Upgrade _upgrade_type;
  int _time;
  BigNum _cost;

 public:
  BoughtUpgrade(Upgrade related_upgrade, int time_when_bought, BigNum cost);
  ~BoughtUpgrade();

};

#endif // BOUGHTUPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
