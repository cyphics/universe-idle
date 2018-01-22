// ResourcesList.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "ship/ResourcesList.h"
ResourcesList::ResourcesList(){}

ResourcesList::ResourcesList(std::vector<Resource> list_resources)
    : _list_of_resources(list_resources)
{}
ResourcesList::~ResourcesList(){}

BigNum ResourcesList::get_resource_amount(Resource_ID resource_id) const
{
  for (auto &resource : _list_of_resources) {
    if (resource.has_id(resource_id)) {
      return resource.get_current_amount();
    }
  }
  std::cout << "Error, resource not present"  << "\n";
  return BigNum(0);
}

std::vector<Resource>& ResourcesList::get_list_of_resources()
{
  return _list_of_resources;
}

const std::vector<Resource>& ResourcesList::get_list_of_resources() const
{
  /**
   * Return a constant reference to the vector containing  all resources
   */
  return _list_of_resources;
}

Resource& ResourcesList::get_resource(Resource_ID resource_id)
{
  /**
   * Takes resource_id, and return a reference to the resource.
   */
  for (auto &resource : get_list_of_resources())
  {
    if (resource.has_id(resource_id))
    {
      return resource;
    }
  }
  std::cout << "Error, resource not present"  << "\n";
}

const Resource& ResourcesList::get_resource(Resource_ID resource_id) const
{
  /**
   * Takes resource_id, and return a constant reference to the resource.
   */
  for (auto &resource : get_list_of_resources())
  {
    if (resource.has_id(resource_id))
      return resource;
  }
  std::cout << "Error, resource not present"  << "\n";
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//