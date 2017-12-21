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
#include "../helpers/resources_helper.h"

class Resource{
 private:
  Resource_ID resource_id;
  BigNum _amount;
  BigNum _max_amount;

 public:
  Resource(Resource_ID resource_id);
  ~Resource();

  // Getters
  BigNum get_current_amount() const;

  void set_current_amount(BigNum new_amount);
  void add(BigNum new_amount);
};

#endif // RESOURCE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//