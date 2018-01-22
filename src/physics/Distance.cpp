// Distance.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "physics/Distance.h"
#include "physics/Speed.h"

using namespace Physics;

Distance::Distance(BigNum num_distance)
    :PhysicalUnit(num_distance)
{}

// Distance::Distance(const Time& elapsed_time, const Speed& speed)
//     :PhysicalUnit(elapsed_time.get_numerical_value() * speed)
// {
//   /**
//    * Build a Distance object based on given speed and time spent
//    */
// }

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

// Distance& Distance::operator*=(const long& rhs){
//   _numerical_value *= rhs;
//   return *this;
// }

Distance& Distance::operator*=(const double& rhs){
  _numerical_value *= rhs;
  return *this;
}



//////////////////////////////////////////////////////////////////////
// $Log:$
//
