// Acceleration.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <math.h>
#include "physics/PhysicalUnit.h"
#include "physics/Acceleration.h"

using namespace Physics;

Acceleration::Acceleration(BigNum num_value)
    : PhysicalUnit(num_value)
{
  _unit = DistanceUnit::yoctometer;
}

Acceleration::Acceleration(BigNum num_value, DistanceUnit unit)
    : Acceleration(num_value)
{
  _unit = unit;
}

Acceleration::~Acceleration(){}

Acceleration& Acceleration::operator=(const Acceleration& rhs){
  _numerical_value = rhs.num();
  return *this;
}

Acceleration& Acceleration::operator+=(const Acceleration& rhs){
  _numerical_value += rhs.num();
  return *this;
}
Acceleration& Acceleration::operator-=(const Acceleration& rhs){
  _numerical_value -= rhs.num();
  return *this;
}

void Acceleration::set_unit(Physics::DistanceUnit unit)
{
  _unit = unit;
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
