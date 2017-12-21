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

#include "BigNum.h"
#include "../helpers/resources_helper.h"
#include "../helpers/upgrades_helper.h"

class Upgrade{
 private:
  Upgrade_ID _upgrade_id;
  std::string _upgrade_name;
  BigNum _initial_cost;
  Resource_ID _resource_type;
  double _price_factor;
  BigNum _cost_next_level;
  int _level = 0; // Equals number bought
  bool _is_available = false;


 public:
  Upgrade(Upgrade_ID upgrade_id, std::string name, BigNum initial_cost, double price_factor);
  ~Upgrade();
  BigNum get_cost(int number_levels) const;
  int get_current_level() const;
  void increase_level(int number_levels);
  bool is_available() const;
};


#endif // UPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
