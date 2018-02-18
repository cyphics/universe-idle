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

#include "PhysicalUnit.h"
#include "constant_distances.h"


namespace Physics{

class Distance: public PhysicalUnit{
 private:
  DistanceUnit _unit;
 public:
  Distance(BigNum numerical_value);
  Distance(BigNum numerical_value, DistanceUnit unit);

  ~Distance();

  Distance& operator=(const Distance& rhs);
  Distance& operator+=(const Distance& rhs);
  Distance& operator-=(const Distance& rhs);
  Distance& operator*=(const int& rhs);
  //Distance& operator*=(const long& rhs);
  Distance& operator*=(const double& rhs);
  std::string to_string() const;
  void set_unit(Physics::DistanceUnit unit);

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
