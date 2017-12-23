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
 private:
  BigNum _numerical_value;

 public:
  PhysicalUnit(BigNum numerical_value);
  ~PhysicalUnit();

  BigNum get_numerical_value() const;
  std::string to_string() const;


  friend bool operator ==(const PhysicalUnit&, const PhysicalUnit&);
  friend bool operator !=(const PhysicalUnit&, const PhysicalUnit&);
  friend bool operator <(const PhysicalUnit&, const PhysicalUnit&);
  friend bool operator >(const PhysicalUnit&, const PhysicalUnit&);
  friend bool operator >=(const PhysicalUnit&, const PhysicalUnit&);
  friend bool operator <=(const PhysicalUnit&, const PhysicalUnit&);

  friend PhysicalUnit operator +(const PhysicalUnit&, const PhysicalUnit&);
  void operator +=(const PhysicalUnit&);
  friend PhysicalUnit operator -(const PhysicalUnit&, const PhysicalUnit&);
  void operator -=(const PhysicalUnit&);
  friend PhysicalUnit operator *(const PhysicalUnit&, const PhysicalUnit&);
  friend PhysicalUnit operator *(const PhysicalUnit&, const int&);
  friend PhysicalUnit operator /(const PhysicalUnit&, const PhysicalUnit&);
  friend PhysicalUnit operator /(const PhysicalUnit&, const PhysicalUnit&);

};

#endif // PHYSICALUNIT_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
