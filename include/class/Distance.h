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

  Distance& operator=(const Distance& rhs);
  Distance& operator+=(const Distance& rhs);
  Distance& operator-=(const Distance& rhs);

};

inline bool operator==(const Distance& lhs, const Distance& rhs){ return lhs.get_numerical_value() == rhs.get_numerical_value(); }
inline bool operator!=(const Distance& lhs, const Distance& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const Distance& lhs, const Distance& rhs){ return lhs.get_numerical_value() < rhs.get_numerical_value(); }
inline bool operator> (const Distance& lhs, const Distance& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const Distance& lhs, const Distance& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const Distance& lhs, const Distance& rhs){return !operator< (lhs,rhs);}


#endif // DISTANCE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
