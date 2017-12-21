// -*- compile-command: "./../../compile.sh"; -*-
// ResourcesList.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef RESOURCESLIST_H
#define RESOURCESLIST_H 1

#include "Resource.h"
#include "../helpers/resources_helper.h"

class ResourcesList{
 private:
  std::vector<Resource> list_of_resources;

 public:
  ResourcesList();
  ~ResourcesList();

  //BigNum get_resource_amount(Resource resource);

};


#endif // RESOURCESLIST_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
