// -*- compile-command: "./../compile.sh"; -*-
// Upgrade.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UPGRADE_H
#define UPGRADE_H 1

#include <vector>
#include "BigNum.h"
#include "Price.h"
#include "../helpers/resources_helper.h"
#include "../helpers/upgrades_helper.h"

class Upgrade{
 private:
  Upgrade_ID _upgrade_id;
  std::string _upgrade_name;
  Price _initial_cost;
  std::vector<UpgradeCostTableElement> _upgrade_cost_table;
  std::vector <Resource_ID> _required_resources;
  std::vector<double> _price_factor;
  int _current_level = 0; // Equals number bought
  bool _is_available = false;

  void compute_cost_next_level();

 public:
  Upgrade(Upgrade_ID upgrade_id, std::string name, std::vector<UpgradeCostTableElement> cost_table);
  ~Upgrade();
  Price get_cost_given_level(int level) const;
  int get_current_level() const;
  void increase_level(int number_levels);
  bool is_available() const;
  bool has_id(Upgrade_ID) const;
};


#endif // UPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
