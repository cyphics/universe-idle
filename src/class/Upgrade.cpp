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

Upgrade::Upgrade(Upgrade_ID upgrade_id, std::string upgrade_name, std::vector<UpgradeCostTableElement> cost_table, double increase_factor)
    : _upgrade_id(upgrade_id), _upgrade_name(upgrade_name), _cost_table(cost_table), _increase_factor(increase_factor)
{
  // Set _initial_cost
  // _initial_cost = get_cost_given_level(1);
  // _current_cost = _initial_cost;
  // // Set _required_resources
  // for (auto cost_elem: _cost_table) {
  //   _required_resources.push_back(cost_elem.resource);
  // }

}

Upgrade::~Upgrade(){}

Price Upgrade::get_cost_given_level(int additional_levels) const{
  /**
   * Get cost to buy <number_levels> new levels
     Return BigNum
   */
  std::cout << "get_cost_given_level"  << "\n";
  assert(additional_levels > 0);

  Price price;
  // Go through all required resources
  // ERROR

  for (auto resource_id : _required_resources) {
    // Get required amount
    std::cout << "test"  << "\n";


    BigNum required_amout = _current_cost.get_resource_amount(resource_id); // Set at current amount first

    for (int i = 0; i < additional_levels; ++i) {
      required_amout *= _increase_factor; // Increase it by factor, <level> times
    }

    price.add_resource(resource_id, required_amout); // Store it in Price object

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
  return _upgrade_name;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
