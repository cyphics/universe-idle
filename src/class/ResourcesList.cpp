// -*- compile-command: "./../../compile.sh"; -*-
// ResourcesList.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/ResourcesList.h"

ResourcesList::ResourcesList(){}
ResourcesList::~ResourcesList(){}

BigNum ResourcesList::get_resource_amount(Resource_ID resource_id) const{
  for (auto &resource : _list_of_resources) {
    if (resource.has_id(resource_id)) {
      return resource.get_current_amount();
    }
  }
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
