// Acceleration.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef ACCELERATION_H
#define ACCELERATION_H 1

#include "physics/PhysicalUnit.h"
#include "constant_distances.h"

class BigNum;

namespace Physics{

class Acceleration : public PhysicalUnit{
 private:
  Physics::DistanceUnit _unit;

 public:
  Acceleration(BigNum num_value);
  Acceleration(BigNum num_value, DistanceUnit unit);
  ~Acceleration();

  Acceleration& operator=(const Acceleration& rhs);
  Acceleration& operator+=(const Acceleration& rhs);
  Acceleration& operator-=(const Acceleration& rhs);

  void set_unit(Physics::DistanceUnit unit);

};



inline bool operator==(const Acceleration& lhs, const Acceleration& rhs){ return lhs.num() == rhs.num(); }
inline bool operator!=(const Acceleration& lhs, const Acceleration& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const Acceleration& lhs, const Acceleration& rhs){ return lhs.num() < rhs.num(); }
inline bool operator> (const Acceleration& lhs, const Acceleration& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const Acceleration& lhs, const Acceleration& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const Acceleration& lhs, const Acceleration& rhs){return !operator< (lhs,rhs);}

inline Acceleration operator-(const Acceleration& lhs, const Acceleration& rhs){
  Acceleration sub = lhs;
  sub -= rhs;
  return  sub;
}

inline Acceleration operator+(const Acceleration& lhs, const Acceleration& rhs){
  Acceleration add = lhs;
  add += rhs;
  return  add;
}


}

#endif // ACCELERATION_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
