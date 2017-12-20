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

class Upgrade{
 private:
  std::string _name = "";
  BigNum _initial_cost;
  double _price_factor;
  BigNum _cost_next_level;
  int _level = 0; // Equals number bought
  bool _is_available = false;


 public:
  Upgrade(std::string name, BigNum initial_cost, double price_factor);
  ~Upgrade();
  BigNum get_price(int number_levels) const;
  int get_current_level() const;
  void increase_level(int number_levels);
  std::string get_name() const;
  bool is_available() const;

};


#endif // UPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
