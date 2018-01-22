// Distance.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef DISTANCE_H
#define DISTANCE_H 1

//#include "Speed.h"

#include "physics/PhysicalUnit.h"
//#include "BigNum.h"
//#include "Time.h"

class BigNum;

namespace Physics{

class Distance: public PhysicalUnit{

 public:
  Distance(BigNum numerical_value);
  //Distance(const Time& elapsed_time, const Speed& speed);
  ~Distance();

  Distance& operator=(const Distance& rhs);
  Distance& operator+=(const Distance& rhs);
  Distance& operator-=(const Distance& rhs);
  Distance& operator*=(const int& rhs);
  //Distance& operator*=(const long& rhs);
  Distance& operator*=(const double& rhs);
  std::string to_string() const;
};

inline bool operator==(const Distance& lhs, const Distance& rhs){ return lhs.num() == rhs.num(); }
inline bool operator!=(const Distance& lhs, const Distance& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const Distance& lhs, const Distance& rhs){ return lhs.num() < rhs.num(); }
inline bool operator> (const Distance& lhs, const Distance& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const Distance& lhs, const Distance& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const Distance& lhs, const Distance& rhs){return !operator< (lhs,rhs);}

inline Distance operator-(const Distance& lhs, const Distance& rhs){
  Distance temp = lhs;
  temp -= rhs;
  return temp;
}

inline Distance operator+(const Distance& lhs, const Distance& rhs){
  Distance temp = lhs;
  temp += rhs;
  return temp;
}

inline Distance operator*(const Distance& lhs, const int& rhs){
  Distance temp = lhs;
  temp *= rhs;
  return temp;
}

// inline Distance operator*(const Distance& lhs, const long& rhs){
//   Distance temp = lhs;
//   temp *= rhs;
//   return temp;
// }

inline Distance operator*(const Distance& lhs, const double& rhs){
  Distance temp = lhs;
  temp *= rhs;
  return temp;
}

}
#endif // DISTANCE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
