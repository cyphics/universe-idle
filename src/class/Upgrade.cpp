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

Upgrade::Upgrade(Upgrade_ID upgrade_id, std::string upgrade_name, BigNum initial_cost, double price_factor): _initial_cost(initial_cost), _price_factor(price_factor)
{}

Upgrade::~Upgrade(){}

BigNum Upgrade::get_cost(int number_levels) const{
  /**
   * Get cost to buy <number_levels> new levels
     Return BigNum
   */
  BigNum price = _initial_cost * pow(_price_factor, _level);
  return price;
}

int Upgrade::get_current_level() const{
  return _level;
}

void Upgrade::increase_level(int number_levels){
  /**
   * Increase current level with <number_levels>
   */
}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
