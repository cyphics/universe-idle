// BigNum.h
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
#include <cmath>

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
  BigNum& operator*=(const double& rhs);
  BigNum& operator/=(const BigNum& rhs);
  BigNum& operator/=(const int& rhs);

  //friend std::ostream& operator<<(std::ostream& os, const BigNum& num);

};


inline bool operator==(const BigNum& lhs, const BigNum& rhs){ return lhs.get_value() == rhs.get_value();}
inline bool operator!=(const BigNum& lhs, const BigNum& rhs){ return !operator==(lhs, rhs);}
inline bool operator<(const BigNum& lhs, const BigNum& rhs){ return lhs.get_value() < rhs.get_value(); }
inline bool operator>(const BigNum& lhs, const BigNum& rhs){ return operator<(rhs, lhs);}
inline bool operator>=(const BigNum& lhs, const BigNum& rhs){ return !operator>(lhs, rhs);}
inline bool operator<=(const BigNum& lhs, const BigNum& rhs){ return !operator>(lhs, rhs);}

inline BigNum operator+(const BigNum& lhs, const BigNum& rhs){
  BigNum sum = lhs;
  sum += rhs;
  return sum;
}

inline BigNum operator-(const BigNum& lhs, const BigNum& rhs){
  BigNum sub = lhs;
  sub -= rhs;
  return sub;
}

inline BigNum operator*(const BigNum& lhs, const BigNum& rhs){
  BigNum mul = lhs;
  mul *= rhs;
  return mul;
}

inline BigNum operator*(const BigNum& lhs, const int& rhs ){
  BigNum mul = lhs;
  mul *= rhs;
  return mul;
}

inline BigNum operator*(const BigNum& lhs, const double& rhs ){
  BigNum mul = lhs;
  mul *= rhs;
  return mul;
}

inline BigNum operator/(const BigNum& lhs, const int& rhs){
  BigNum div = lhs;
  div /= rhs;
  return div;
}

inline BigNum operator/(const BigNum& lhs, const BigNum& rhs){
  BigNum div = lhs;
  div /= rhs;
  return div;
}


inline bool CompareBignums(BigNum lhs, BigNum rhs){
  double comparison_offset = 0.0000001;
  BigNum diff = lhs;
  diff -= rhs;
  return (std::abs(diff.get_value()) < comparison_offset);
}


#endif // LIBBIGNUM_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
