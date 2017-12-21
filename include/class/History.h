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

  void add_upgrade(BoughtUpgrade new_upgrade);
  std::string to_string();
};

#endif // HISTORY_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
