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

#include "../helpers/upgrades_helper.h"
#include "BigNum.h"

class BoughtUpgrade{
  /**
   * Class used to store history of bought upgrades
   */
 private:
  Upgrade_ID _upgrade_type;
  std::string _upgrade_name;
  int _time;
  BigNum _cost;

 public:
  BoughtUpgrade(Upgrade_ID related_upgrade, std::string ugprade_name, int time_when_bought, BigNum cost);
  ~BoughtUpgrade();

  std::string to_string() const;

};

#endif // BOUGHTUPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
