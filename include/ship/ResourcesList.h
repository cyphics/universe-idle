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

#include "ship/Resource.h"
#include "ship//resources_helper.h"

class ResourcesList{
 private:
  std::vector<Resource> _list_of_resources;

 public:
  ResourcesList();
  ResourcesList(std::vector<Resource>);
  ~ResourcesList();

  BigNum get_resource_amount(Resource_ID resource) const;
  std::vector<Resource>& get_list_of_resources();
  const std::vector<Resource>& get_list_of_resources() const;
  Resource& get_resource(Resource_ID);
  const Resource& get_resource(Resource_ID) const;

};


#endif // RESOURCESLIST_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
