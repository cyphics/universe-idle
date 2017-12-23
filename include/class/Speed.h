// Speed.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef SPEED_CLASS_H
#define SPEED_CLASS_H 1

#include "PhysicalUnit.h"
#include "BigNum.h"
#include "Distance.h"
#include "Time.h"

class Speed : public PhysicalUnit{
 public:
  Speed(BigNum num_value);
  //Speed(const Distance& distance, const Time& time);
  Speed(const Speed&);
  ~Speed();

};


#endif // SPEED_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
