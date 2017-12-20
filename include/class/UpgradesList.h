// -*- compile-command: "make -sk"; -*-
// UpgradesList.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UPGRADESLIST_H
#define UPGRADESLIST_H 1

#include "Upgrade.h"

class UpgradesList{
 private:
  std::vector<Upgrade> _list_of_upgrades;

 public:
  UpgradesList();
  ~UpgradesList();

  std::vector<Upgrade> get_available_upgrades() const;
  std::vector<Upgrade> get_all_upgrades() const;
  Upgrade get_upgrade(std::string name) const;

};


#endif // UPGRADESLIST_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
