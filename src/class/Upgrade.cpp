// -*- compile-command: "./../../compile.sh"; -*-
// Upgrade.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <math.h>
#include "../../include/class/Upgrade.h"

Upgrade::Upgrade(Upgrade_ID upgrade_id, std::string upgrade_name, std::vector<UpgradeCostTableElement> cost_table)
    : _upgrade_cost_table(cost_table)
{}

Upgrade::~Upgrade(){}

Price Upgrade::get_cost_given_level(int level) const{
  /**
   * Get cost to buy <number_levels> new levels
     Return BigNum
   */

  Price price;

  for (int i = 0; i < _required_resources.size(); ++i) {

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

//////////////////////////////////////////////////////////////////////
// $Log:$
//
