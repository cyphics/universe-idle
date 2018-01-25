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
#include "ship/Price.h"
#include "ship/resources_helper.h"
#include "ship/upgrades_helper.h"


class Upgrade{
 private:
  Upgrade_ID _upgrade_id;
  Price _initial_cost;
  Price _cost_last_level; // what it costed to buy that level
  std::vector<UpgradeCostTableElement> _cost_table;
  std::vector <Resource_ID> _required_resources;
  double _increase_factor;
  int _current_level = 0; // Equals number bought
  bool _is_available = false;
  bool _uniqueness = false;

 public:
  Upgrade(Upgrade_ID upgrade_id, std::vector<UpgradeCostTableElement> cost_table, double increase_factor);
  ~Upgrade();

  // Getters
  Price get_cost_increase_level(int level) const;
  int get_current_level() const;
  std::string get_name() const;
  bool is_available() const;
  bool has_id(Upgrade_ID) const;
  Upgrade_ID get_ID() const;
  const UpgradeCostTableElement& get_cost_table_element(Resource_ID queried_resource_id) const;

  void increase_level(int number_levels);
  void set_availability(bool availability);
  void set_uniqueness(bool availability);
};


#endif // UPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
