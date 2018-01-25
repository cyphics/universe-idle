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


std::string Distance::to_string() const
{
  std::string output = "";
  if ( *this < Physics::Units::kilometer)
  {
    int exposant = _numerical_value.get_exponant() - Physics::Units::meter.num().get_exponant();
    int mantissa = _numerical_value.get_significand();
    output += std::to_string(mantissa);
    output += "e";
    output += std::to_string(exposant);
    output += " meters";
  }
  else if (*this < Physics::Units::astro_unit)
  {
    int exposant = _numerical_value.get_exponant() - Physics::Units::kilometer.num().get_exponant();
    double mantissa = _numerical_value.get_significand();
    output += std::to_string(mantissa);
    output += "e";
    output += std::to_string(exposant);
    output += " kilometers";
  }
  return output;
}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
