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

  friend bool operator ==(const BigNum&, const BigNum&);
  friend bool operator !=(const BigNum&, const BigNum&);
  friend bool operator <(const BigNum&, const BigNum&);
  friend bool operator >(const BigNum&, const BigNum&);
  friend bool operator >=(const BigNum&, const BigNum&);
  friend bool operator <=(const BigNum&, const BigNum&);

  friend BigNum operator +(const BigNum&, const BigNum&);
  friend BigNum operator -(const BigNum&, const BigNum&);
  friend BigNum operator *(const BigNum&, const BigNum&);
  friend BigNum operator *(const BigNum&, const int&);
  friend BigNum operator /(const BigNum&, const BigNum&);
  friend BigNum operator /(const BigNum&, const BigNum&);

};


#endif // LIBBIGNUM_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
