// -*- compile-command: "./../../compile.sh"; -*-
// Resource.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef RESOURCE_H
#define RESOURCE_H 1

#include "BigNum.h"

class Resource{
 private:
  BigNum _amount;
  std::string _name;

 public:
  Resource();
  ~Resource();

  BigNum get_current_amount();
};

#endif // RESOURCE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
