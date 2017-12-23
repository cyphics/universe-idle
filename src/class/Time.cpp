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

#include "../../include/class/Time.h"

Time::Time(BigNum amount)
    :PhysicalUnit(amount)
{}

Time operator -(const Time& time1, const Time& time2){
  return Time(time1 - time2);
}



Time::~Time(){}
