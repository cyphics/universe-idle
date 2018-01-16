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
//#include "BigNum.h"
//#include "Distance.h"
//#include "Time.h"

class BigNum;


class Speed : public PhysicalUnit{
 public:
  Speed(BigNum num_value);
  Speed(const Speed&);
  ~Speed();

  Speed& operator=(const Speed& rhs);
  Speed& operator+=(const Speed& rhs);
  Speed& operator-=(const Speed& rhs);

};

inline bool operator==(const Speed& lhs, const Speed& rhs){ return lhs.get_numerical_value() == rhs.get_numerical_value(); }
inline bool operator!=(const Speed& lhs, const Speed& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const Speed& lhs, const Speed& rhs){ return lhs.get_numerical_value() < rhs.get_numerical_value(); }
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


#endif // SPEED_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
