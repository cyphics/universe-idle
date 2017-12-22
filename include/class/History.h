// -*- compile-command: "./../../compile.sh"; -*-
// History.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef HISTORY_H
#define HISTORY_H 1

#include <vector>
#include "BoughtUpgrade.h"

class History{
 private:
  std::vector<BoughtUpgrade> _history;

 public:
  History();
  ~History();

  void add_upgrade(Upgrade_ID new_upgrade, BigNum price, int time);
  std::string to_string();
};

#endif // HISTORY_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
