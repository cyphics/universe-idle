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
#include "managment/BoughtUpgrade.h"

class Price;


class History{
 private:
  std::vector<BoughtUpgrade> _history;

 public:
  History();
  ~History();

  void add_upgrade(Upgrade_ID new_upgrade, Price price, Physics::Time time_when_bought);
  std::string to_string() const;
};

#endif // HISTORY_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
