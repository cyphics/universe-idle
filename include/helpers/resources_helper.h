// -*- compile-command: "./compile.sh"; -*-
// resources_helper.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef RESOURCES_HELPER_H
#define RESOURCES_HELPER_H 1

#include "../class/BigNum.h"

enum class Resource_ID { cinetic_energy, dark_matter };

struct ResourceAmount {
  Resource_ID _resource_ID;
  BigNum _amount;
  ResourceAmount(Resource_ID resource_id, BigNum amount)
      :_resource_ID(resource_id), _amount(amount)
  {}
};


#endif // RESOURCES_HELPER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
