// PhysicalUnit.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// $Log:$
//

#include "../../include/class/PhysicalUnit.h"

PhysicalUnit::PhysicalUnit(BigNum numerical_value)
    :_numerical_value(numerical_value)
{}

PhysicalUnit::~PhysicalUnit(){}

const BigNum& PhysicalUnit::get_numerical_value() const{
  return _numerical_value;
}

/**
 * Overload << operator
 */


PhysicalUnit& PhysicalUnit::operator=(const PhysicalUnit& rhs){
  _numerical_value = rhs.get_numerical_value();
  return *this;
}

PhysicalUnit& PhysicalUnit::operator+=(const PhysicalUnit& rhs){
  _numerical_value += rhs.get_numerical_value();
  return *this;
}

PhysicalUnit& PhysicalUnit::operator-=(const PhysicalUnit& rhs){
  _numerical_value -= rhs.get_numerical_value();
  return *this;
}





std::string PhysicalUnit::to_string() const{
  return _numerical_value.to_string();
}

std::ostream& operator<<(std::ostream& os, const PhysicalUnit& num){
  return os <<  num.to_string();
}