// -*- compile-command: "./../../compile.sh"; -*-
// Upgrade.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <math.h>
#include <assert.h>
#include "../../include/class/Upgrade.h"
#include "../../include/helpers/game_global_variables.h"

Upgrade::Upgrade(Upgrade_ID upgrade_id, std::vector<UpgradeCostTableElement> cost_table, double increase_factor)
    : _upgrade_id(upgrade_id), _cost_table(cost_table), _increase_factor(increase_factor)
{
  // Set _initial_cost
  for (auto cost: cost_table) {
    _initial_cost.add_resource(cost.resource, cost.initial_cost);
  }

  //_cost_last_level = _initial_cost;

  // Set _required_resources
  for (auto cost_elem: _cost_table) {
    _required_resources.push_back(cost_elem.resource);
  }
}

Upgrade::~Upgrade(){}



Price Upgrade::get_cost_increase_level(int additional_levels) const{
  /**
   * Get cost to buy <number_levels> new levels
     Return Price
   */
  assert(additional_levels > 0);

  if (_current_level == 0) {
    return _initial_cost;
  }

  Price price;

  // Go through all required resources
  for (auto resource_id : _required_resources) {
    BigNum required_amount = _cost_last_level.get_resource_amount(resource_id); // Set at cost for last level first

    for (int i = 0; i < additional_levels; i++) {
      required_amount *= _increase_factor;
    }

    price.add_resource(resource_id, required_amount); // Store it in Price object

  }
  return price;
}



int Upgrade::get_current_level() const{
  return _current_level;
}

void Upgrade::increase_level(int number_new_levels){
  /**
   * Increase current level with <number_levels>
   */
  _cost_last_level = get_cost_increase_level(number_new_levels);
  _current_level += number_new_levels;
}

bool Upgrade::has_id(Upgrade_ID upgrade_id) const{
  /**
   * Checks if upgrade has the correct ID
   */
  return upgrade_id == _upgrade_id;
}


const UpgradeCostTableElement& Upgrade::get_cost_table_element(Resource_ID queried_resource_id) const{
  for (auto const &resource : _cost_table) {
    if (queried_resource_id == resource.resource) {
      return resource;
    }
  }
}

std::string Upgrade::get_name() const{
  return global::upgrade_name(_upgrade_id);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
