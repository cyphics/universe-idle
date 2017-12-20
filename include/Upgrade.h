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
  std::string _name;
  BigNum _initial_cost;
  double _price_factor;
  BigNum _current_cost;
  int _number_bought;


 public:
  Upgrade();
  ~Upgrade();
  BigNum get_price() const;
  int get_number_updates() const;
  void buy();
  int get_value() const;
  std::string get_name() const;

};


#endif // UPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
