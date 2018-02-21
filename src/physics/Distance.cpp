// Distance.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "physics/Distance.h"
#include "physics/Speed.h"
#include "physics/constants_physics.h"

using namespace Physics;

Distance::Distance(BigNum num_distance)
    :PhysicalUnit(num_distance)
{
  _unit = DistanceUnit::yoctometer;
}

Distance::Distance(BigNum num, DistanceUnit unit)
    :PhysicalUnit(num)
{
  _unit = unit;
  _numerical_value *= Physics::distance_value(_unit);
}
Distance::~Distance(){}

Distance& Distance::operator=(const Distance& rhs){
  _numerical_value = rhs.num();
  return *this;
}

Distance& Distance::operator+=(const Distance& rhs){
  _numerical_value += rhs.num();
  return *this;
}

Distance& Distance::operator-=(const Distance& rhs)
{
  _numerical_value -= rhs.num();
  return *this;
}

Distance& Distance::operator*=(const int& rhs){
  _numerical_value *= rhs;
  return *this;
}

Distance& Distance::operator*=(const double& rhs){
  _numerical_value *= rhs;
  return *this;
}


std::string Distance::to_string() const
{
  std::string output = "";


  BigNum num = _numerical_value / Physics::distance_value(_unit);

  output += num.to_string();
  output += " ";
  output += Physics::distance_name(_unit);

  return output;
}

void Distance::set_unit(Physics::DistanceUnit unit)
{
  _unit = unit;
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
