// Acceleration.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef ACCELERATION_H
#define ACCELERATION_H 1

#include "PhysicalUnit.h"
#include "BigNum.h"
#include "Speed.h"
#include "Time.h"

class Acceleration : public PhysicalUnit{

 public:
  Acceleration(BigNum num_value);
  Acceleration(const Speed& speed_beginning, const Speed& speed_end, const Time& time);
  ~Acceleration();

};


#endif // ACCELERATION_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
