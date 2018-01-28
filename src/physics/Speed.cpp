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
{}

// Speed::Speed(const Distance& distance, const Time& time)
//     : PhysicalUnit(distance.num() * time.num())
// {}

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

//////////////////////////////////////////////////////////////////////
// $Log:$
//
