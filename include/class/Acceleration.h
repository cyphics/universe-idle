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
  ~Acceleration();

  Acceleration& operator=(const Acceleration& rhs);
  Acceleration& operator+=(const Acceleration& rhs);
  Acceleration& operator-=(const Acceleration& rhs);

};

inline bool operator==(const Acceleration& lhs, const Acceleration& rhs){ return lhs.get_numerical_value() == rhs.get_numerical_value(); }
inline bool operator!=(const Acceleration& lhs, const Acceleration& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const Acceleration& lhs, const Acceleration& rhs){ return lhs.get_numerical_value() < rhs.get_numerical_value(); }
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




#endif // ACCELERATION_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
