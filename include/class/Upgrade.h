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
#include "Price.h"
#include "../helpers/resources_helper.h"
#include "../helpers/upgrades_helper.h"


class Upgrade{
 private:
  Upgrade_ID _upgrade_id;
  Price _initial_cost;
  Price _current_cost;
  std::vector<UpgradeCostTableElement> _cost_table;
  std::vector <Resource_ID> _required_resources;
  double _increase_factor;
  int _current_level = 0; // Equals number bought
  bool _is_available = false;

  void compute_cost_next_level();

 public:
  Upgrade(Upgrade_ID upgrade_id, std::string name, std::vector<UpgradeCostTableElement> cost_table, double increase_factor);
  ~Upgrade();
  Price get_cost_given_level(int level) const;
  int get_current_level() const;
  void increase_level(int number_levels);
  std::string get_name() const;
  bool is_available() const;
  bool has_id(Upgrade_ID) const;
  const UpgradeCostTableElement& get_cost_table_element(Resource_ID queried_resource_id) const;
};


#endif // UPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
