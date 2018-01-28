// Speed.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef SPEED_CLASS_H
#define SPEED_CLASS_H 1

#include "physics/PhysicalUnit.h"
//#include "BigNum.h"
//#include "Distance.h"
//#include "Time.h"

class BigNum;

namespace Physics{

class Speed : public PhysicalUnit{
 public:
  Speed(BigNum num_value);
  Speed(const Speed&);
  ~Speed();

  Speed& operator=(const Speed& rhs);
  Speed& operator+=(const Speed& rhs);
  Speed& operator-=(const Speed& rhs);
  Speed& operator*=(const int rhs);

};

inline bool operator==(const Speed& lhs, const Speed& rhs){ return lhs.num() == rhs.num(); }
inline bool operator!=(const Speed& lhs, const Speed& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const Speed& lhs, const Speed& rhs){ return lhs.num() < rhs.num(); }
inline bool operator> (const Speed& lhs, const Speed& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const Speed& lhs, const Speed& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const Speed& lhs, const Speed& rhs){return !operator< (lhs,rhs);}

inline Speed operator-(const Speed& lhs, const Speed& rhs){
  Speed temp = lhs;
  temp -= rhs;
  return temp;
}

inline Speed operator+(const Speed& lhs, const Speed& rhs){
  Speed temp = lhs;
  temp += rhs;
  return temp;
}

inline Speed operator*(const Speed& lhs, const int rhs){
  Speed temp = lhs;
  temp *= rhs;
  return temp;
}

}
#endif // SPEED_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
