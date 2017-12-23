// PhysicalUnit.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef PHYSICALUNIT_H
#define PHYSICALUNIT_H 1

#include "BigNum.h"


class PhysicalUnit{
 protected:
  BigNum _numerical_value;

 public:
  PhysicalUnit(BigNum numerical_value);
  ~PhysicalUnit();

  const BigNum& get_numerical_value() const;
  std::string to_string() const;


  // Assignment operator
  PhysicalUnit& operator=(const PhysicalUnit& rhs);

  // Binary arithmetic operators
  PhysicalUnit& operator+=(const PhysicalUnit& rhs);
  PhysicalUnit& operator-=(const PhysicalUnit& rhs);

};

// Comparison operators
inline bool operator==(const PhysicalUnit& lhs, const PhysicalUnit& rhs){ return lhs.get_numerical_value() == rhs.get_numerical_value(); }
inline bool operator!=(const PhysicalUnit& lhs, const PhysicalUnit& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const PhysicalUnit& lhs, const PhysicalUnit& rhs){ return lhs.get_numerical_value() < rhs.get_numerical_value(); }
inline bool operator> (const PhysicalUnit& lhs, const PhysicalUnit& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const PhysicalUnit& lhs, const PhysicalUnit& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const PhysicalUnit& lhs, const PhysicalUnit& rhs){return !operator< (lhs,rhs);}

inline PhysicalUnit operator-(PhysicalUnit lhs, const PhysicalUnit& rhs){
  lhs -= rhs;
  return  lhs;
}

inline PhysicalUnit operator+(PhysicalUnit lhs, const PhysicalUnit& rhs){
  lhs += rhs;
  return  lhs;
}

#endif // PHYSICALUNIT_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
