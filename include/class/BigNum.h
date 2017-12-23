// -*- compile-command: "./../compile.sh"; -*-
// libbignum.h
//
// last-edit-by: <cyphix>
//
// Description:
// Class that manipulates huge (10^300) numbers
//
//////////////////////////////////////////////////////////////////////

#ifndef LIBBIGNUM_H
#define LIBBIGNUM_H 1

#include <iostream>
#include <vector>

class BigNum
{
 private:
  double _num_value;
  std::pair<double, int> _factorized_form;
  static const std::vector<std::string> _scales;

  void factorize();

 public:
  // Constructors
  BigNum();
  BigNum(double);
  BigNum(double, int);
  ~BigNum();

  // Getters
  double get_value() const;
  double get_significand() const;
  int get_exponant() const;

  std::string to_string() const;
  std::string to_string_human() const;

  // Operators
  friend std::ostream& operator<<(std::ostream&, const BigNum&);

  BigNum& operator=(const BigNum& rhs);

  BigNum& operator+=(const BigNum& rhs);
  BigNum& operator-=(const BigNum& rhs);
  BigNum& operator*=(const BigNum& rhs);
  BigNum& operator*=(const int& rhs);
  BigNum& operator/=(const BigNum& rhs);
  BigNum& operator/=(const int& rhs);

};

inline bool operator ==(const BigNum& lhs, const BigNum& rhs){ return lhs.get_value() == rhs.get_value();}
inline bool operator !=(const BigNum& lhs, const BigNum& rhs){ return !operator==(lhs, rhs);}
inline bool operator <(const BigNum& lhs, const BigNum& rhs){ return lhs.get_value() < rhs.get_value(); }
inline bool operator >(const BigNum& lhs, const BigNum& rhs){ return operator<(rhs, lhs);}
inline bool operator >=(const BigNum& lhs, const BigNum& rhs){ return !operator>(lhs, rhs);}
inline bool operator <=(const BigNum& lhs, const BigNum& rhs){ return !operator>(lhs, rhs);}

inline BigNum operator +(BigNum& lhs, const BigNum& rhs){
  lhs += rhs;
  return lhs;
}

inline BigNum operator -(BigNum& lhs, const BigNum& rhs){
  lhs -= rhs;
  return lhs;
}
inline BigNum operator *(BigNum& lhs, const BigNum& rhs){
  lhs *= rhs;
  return lhs;
}

inline BigNum operator *(BigNum& lhs, const int& rhs){
  lhs *= rhs;
  return lhs;
}
inline BigNum operator /(BigNum& lhs, const int& rhs){
  lhs *= rhs;
  return lhs;
}
inline BigNum operator /(BigNum& lhs, const BigNum& rhs){
  lhs *= rhs;
  return lhs;
}



#endif // LIBBIGNUM_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
