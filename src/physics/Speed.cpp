// Speed.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////
#include "physics/Speed.h"

using namespace Physics;

Speed::Speed(BigNum num_value)
    : PhysicalUnit(num_value)
{
  _unit = DistanceUnit::yoctometer;
}

Speed::Speed(BigNum num_value, DistanceUnit unit)
    : Speed(num_value)
{
  _unit = unit;
  _numerical_value *= Physics::distance_value(_unit);
}

Speed::Speed(const Speed& speed)
    : PhysicalUnit(speed.num())
{}

Speed::~Speed(){}

Speed& Speed::operator=(const Speed& rhs)
{
  _numerical_value = rhs.num();
  return *this;
}
Speed& Speed::operator+=(const Speed& rhs)
{
  _numerical_value += rhs.num();
  return *this;
}

Speed& Speed::operator-=(const Speed& rhs)
{
  _numerical_value += rhs.num();
  return *this;
}

Speed& Speed::operator*=(const int rhs)
{
  _numerical_value *= rhs;
  return *this;
}

std::string Speed::to_string() const
{
  std::string output = "";

  BigNum num = _numerical_value / Physics::distance_value(_unit);

  output += num.to_string();
  output += " ";
  output += Physics::distance_name(_unit);
  output += "/s";

  return output;


}

void Speed::set_unit(DistanceUnit unit)
{
  _unit = unit;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
