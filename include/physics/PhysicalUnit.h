// PhysicalUnit.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef PHYSICALUNIT_H
#define PHYSICALUNIT_H 1

#include "util/BigNum.h"

namespace Physics{

class PhysicalUnit{
 protected:
  BigNum _numerical_value;

 public:
  PhysicalUnit(BigNum numerical_value);
  ~PhysicalUnit();

  const BigNum& num() const;
  std::string to_string() const;


  // Assignment operator
  PhysicalUnit& operator=(const PhysicalUnit& rhs);

  // Binary arithmetic operators
  PhysicalUnit& operator+=(const PhysicalUnit& rhs);
  PhysicalUnit& operator-=(const PhysicalUnit& rhs);

};

// Comparison operators
inline bool operator==(const PhysicalUnit& lhs, const PhysicalUnit& rhs){ return lhs.num() == rhs.num(); }
inline bool operator!=(const PhysicalUnit& lhs, const PhysicalUnit& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const PhysicalUnit& lhs, const PhysicalUnit& rhs){ return lhs.num() < rhs.num(); }
inline bool operator> (const PhysicalUnit& lhs, const PhysicalUnit& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const PhysicalUnit& lhs, const PhysicalUnit& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const PhysicalUnit& lhs, const PhysicalUnit& rhs){return !operator< (lhs,rhs);}

inline PhysicalUnit operator-(const PhysicalUnit& lhs, const PhysicalUnit& rhs){
  PhysicalUnit temp = lhs;
  temp -= rhs;
  return  temp;
}

inline PhysicalUnit operator+(const PhysicalUnit& lhs, const PhysicalUnit& rhs){
  PhysicalUnit temp = lhs;
  temp += rhs;
  return  temp;
}

}
#endif // PHYSICALUNIT_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
