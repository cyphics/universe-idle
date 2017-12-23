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

BigNum PhysicalUnit::get_numerical_value() const{
  return _numerical_value;
}

bool operator ==(const PhysicalUnit& first, const PhysicalUnit& second) {
  return first.get_numerical_value() == second.get_numerical_value();
}

/**
 * Overlad != operator
 */
bool operator !=(const PhysicalUnit& first, const PhysicalUnit& second) {
    return !(first == second);
}

/**
 * Overload << operator
 */
std::ostream& operator<<(std::ostream& os, const PhysicalUnit& num){
    return os <<  num.to_string();
}

PhysicalUnit operator +(const PhysicalUnit& a, const PhysicalUnit& b){
  return PhysicalUnit(a.get_numerical_value() + b.get_numerical_value());
}

void PhysicalUnit::operator +=(const PhysicalUnit& b){
  this->_numerical_value += b.get_numerical_value();
}

PhysicalUnit operator -(const PhysicalUnit& a, const PhysicalUnit& b){
  return PhysicalUnit(a.get_numerical_value() - b.get_numerical_value());
}

void PhysicalUnit::operator -=(const PhysicalUnit& b){
  this->_numerical_value -= b.get_numerical_value();
}

PhysicalUnit operator *(const PhysicalUnit& a, const PhysicalUnit& b){
  return PhysicalUnit(a.get_numerical_value() * b.get_numerical_value());
}

PhysicalUnit operator *(const PhysicalUnit& a, const int& b){
  return PhysicalUnit(a.get_numerical_value() * b);
}

PhysicalUnit operator /(const PhysicalUnit& a, const PhysicalUnit& b){
  return PhysicalUnit(a.get_numerical_value() / b.get_numerical_value());
}

bool operator <(const PhysicalUnit& a, const PhysicalUnit& b){
  return a.get_numerical_value() < b.get_numerical_value();
}

bool operator >(const PhysicalUnit& a, const PhysicalUnit& b){
  return a.get_numerical_value() < b.get_numerical_value();
}

bool operator >=(const PhysicalUnit& a, const PhysicalUnit& b){
  return a.get_numerical_value() >= b.get_numerical_value();
}

bool operator <=(const PhysicalUnit& a, const PhysicalUnit& b){
  return a.get_numerical_value() <= b.get_numerical_value();
}

std::string PhysicalUnit::to_string() const{
  return _numerical_value.to_string();
}
