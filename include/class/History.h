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
//#include "Price.h"
//#include "Time.h"

//class BoughtUpgrade;
class Price;
class Time;

class History{
 private:
  std::vector<BoughtUpgrade> _history;

 public:
  History();
  ~History();

  void add_upgrade(Upgrade_ID new_upgrade, Price price, Time time_when_bought);
  std::string to_string(const ResourcesManager*) const;
};

#endif // HISTORY_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
