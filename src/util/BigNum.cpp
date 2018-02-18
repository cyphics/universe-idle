#include <iostream>
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include <math.h>
#include <vector>
#include <assert.h>
//#include <boost/algorithm/string.hpp>

#include "util/BigNum.h"

BigNum::BigNum()
{
  _num_value = 0;
}

BigNum::BigNum( double num_value )
{
  set_value(num_value);
}

BigNum::BigNum( double num_value, int exponant )
{
  _factorized_form = std::make_pair(0.0, 0);
  set_value(num_value * pow(10, exponant));
}

BigNum::~BigNum(){}



/**
 * Return the float value of object
 */
double BigNum::get_value() const
{
  return _num_value;
}

double BigNum::get_significand() const
{
  return _factorized_form.first;
}

int BigNum::get_exponant() const
{
  return _factorized_form.second;
}


/**
 * Operators
 */
std::ostream& operator<<(std::ostream& os, const BigNum& num)
{
  return os <<  num.to_string();
}



BigNum& BigNum::operator=(const BigNum& rhs)
{
  set_value(rhs.get_value());

  return *this;
}

BigNum& BigNum::operator+=(const BigNum& rhs)
{
  set_value(_num_value + rhs.get_value());
  return *this;
}

BigNum& BigNum::operator-=(const BigNum& rhs)
{
  set_value(_num_value - rhs.get_value());
  return *this;
}

BigNum& BigNum::operator*=(const BigNum& rhs)
{
  set_value(_num_value * rhs.get_value());
  return *this;
}

BigNum& BigNum::operator*=(const int& rhs)
{
  set_value(_num_value * rhs);
  return *this;
}

BigNum& BigNum::operator*=(const double& rhs)
{
  set_value(_num_value * rhs);
  return *this;
}

BigNum& BigNum::operator/=(const BigNum& rhs)
{
  set_value(_num_value / rhs.get_value());
  return *this;
}

BigNum& BigNum::operator/=(const int& rhs)
{
  set_value(_num_value / rhs);
  return *this;
}

BigNum& BigNum::operator%=(const BigNum& rhs)
{
  set_value(fmod(_num_value, rhs.get_value()));
  return *this;
}

/**
 * Transforms _num_value into pair(x, e) so that _num_value = x*10^e
 */
void BigNum::factorize()
{
  /**
   * Get exposant and mantissa.
   */

  // If value between 0.001 and 9999, do nothing
  if (_num_value >= 0.001 && _num_value < 10000)
  {
    _factorized_form.second = 0;
    _factorized_form.first = _num_value;
    return;
  }
  // 1) Put absoute mantissa between 1 and 10
  // 2) adjust so exposant is % 3
  else
  {
    int exposant = (_num_value == 0) ? 0 : (int)(log10(fabs(_num_value) ) );
    double mantissa = _num_value * pow(10 , -(exposant));

    // Put mantissa under 10
    while (abs(mantissa) >= 10)
    {
      mantissa /= 10;
      exposant++;
    }

    // Put mantissa above 1
    if (mantissa != 0)
    {
      while (abs(mantissa) < 1)
      {
        mantissa *= 10;
        exposant--;
      }
    }

    while (exposant %3 != 0)
    {
      mantissa *= 10;
      exposant--;
    }
    _factorized_form = std::make_pair(mantissa,exposant);

  }
}


//std::string arr[] = {"atto", "femto", "pico", "nano", "micro", "milli", "", "k", "mega", "giga", "tera", "peta", "exa"};

//const std::vector<std::string> BigNum::_scales(arr, arr + sizeof(arr)/sizeof(std::string));

std::string BigNum::to_string() const
{
  std::string final_string = "";
  std::stringstream stream;
  double mantissa;
  int exposant;


  // If value is between 0.001 and 9999,
  if (_num_value > 0.001 && _num_value < 9999) {
    mantissa = _num_value;
    exposant = 0;
  }
  else{
    mantissa = get_significand();
    exposant = get_exponant();
  }




  // Build output
  stream << std::fixed << std::setprecision(3) << mantissa;
  final_string = stream.str();

  // Remove trailing 0
  bool trailing = true;
  while (trailing) {
    if (final_string.back() == '0') {
      final_string = final_string.substr(0, final_string.size()-1);
    }
    else
      trailing = false;
  }
  if (final_string.back() == '.') {
    final_string = final_string.substr(0, final_string.size()-1);
  }

  if (this->get_exponant() == 3) {
    final_string += "K";
  }
  else if (this->get_exponant() == 6) {
    final_string += "M";
  }
  else if (this->get_exponant() > 6 || this->get_exponant() < 0)
  {

    final_string += " * 10^";
    //final_string += "e";
    final_string += std::to_string(get_exponant());
  }


  return final_string;
}

std::string BigNum::to_string_human() const
{
  /**
   * Form a displayable string properly formatted
   */

  assert (this->_factorized_form.second % 3 == 0);


  // Initialize variables
  std::string final_string = "";
  std::string significand = "";
  std::stringstream stream;
  std::string scale = "";

  int numeric_exponant = this->_factorized_form.second;
  int exponant_scale_level = numeric_exponant/3;
  //int exponant_limit = static_cast<int>(_scales.size());
  //int exponant_limit = _scales.size();

  // Check if beyond scales

  //if (exponant_scale_level > exponant_limit - 1)
  // {
  //   return "infinity";
  // }

  // Set significand
  if (numeric_exponant > 3)
  {
    stream << std::fixed << std::setprecision(3) << this->_factorized_form.first;
  }
  else
  {
    stream << this->_factorized_form.first;
  }


  // Set scale from stored labels
  //scale = this->_scales[exponant_scale_level];



  // Concatenate string
  significand = stream.str();
  final_string += significand;
  final_string += " ";
  final_string += scale;

  return final_string;
}
void BigNum::set_value(double new_value)
{
  _num_value = new_value;
  factorize();
}
