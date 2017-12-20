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
 private:
  Upgrade _upgrade_type;
  int _time;
  BigNum _cost;

 public:
  BoughtUpgrade(Upgrade, int, BigNum);
  ~BoughtUpgrade();


};

#endif // BOUGHTUPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
