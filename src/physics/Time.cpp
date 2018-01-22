// Time.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// $Log:$
//

#include "physics/Time.h"
#include "physics/constants_physics.h"

using namespace Physics;

Time::Time(BigNum amount)
    :PhysicalUnit(amount)
{}


Time::~Time(){}

Time& Time::operator+=(const Time& rhs)
{
  _numerical_value += rhs.num();
  return *this;
}

Time& Time::operator-=(const Time& rhs)
{
  _numerical_value -= rhs.num();
  return *this;
}

Time& Time::operator=(const Time& rhs)
{
  _numerical_value = rhs.num();
  return *this;
}

Time& Time::operator*=(const int& rhs){
  _numerical_value *= rhs;
  return *this;
}

std::string Time::to_string() const
{
  BigNum total = num();

  int seconds = 0;
  int minutes = 0;
  int hours = 0;
  int days = 0;
  int years = 0;
  double galac = 0;
  std::string output = "";
  //BigNum galac(0);


  // Treat galactic years

  galac = (total / Physics::Units::galactical_year.num()).get_value();

  if (galac > 1) {
    output += std::to_string(galac) + " galactic years";
    return output;
  }

  years = total.get_value() / 31536000;

  total %= 31536000;
  days = total.get_value() / 86400;
  total %= 86400;
  hours = total.get_value() / 3600;
  total %= 3600;
  minutes = total.get_value() / 60;
  total %= 60;
  seconds = total.get_value();


  // if (galac > 0) {
  //   output += galac.to_string() + " galactic years ";
  // }
  // else{
    if (years > 0) {
      output += std::to_string(years) + " years ";
    }
    if (days > 0) {
      output += std::to_string(days) + " days ";
    }
    if (hours > 0) {
      output += std::to_string(hours) + " hours ";
    }
    if (minutes > 0) {
      output += std::to_string(minutes) + " minutes ";
    }
    output += std::to_string(seconds) + " seconds";
    //}

  return output;

}
