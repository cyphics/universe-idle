// Distance.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef DISTANCE_H
#define DISTANCE_H 1

#include "Speed.h"

#include "PhysicalUnit.h"
#include "BigNum.h"
#include "Time.h"

class Distance: public PhysicalUnit{

 public:
  Distance(BigNum numerical_value);
  //Distance(const Time& elapsed_time, const Speed& speed);
  ~Distance();

};

#endif // DISTANCE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
