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
  // for (auto &resource : _list_of_resources) {
  //   if (resource.has_id(resource_id)) {
  //     return resource.get_current_amount();
  //   }
  // }
}

std::vector<Resource>& ResourcesList::get_list_of_resources(){
  return _list_of_resources;
}

const std::vector<Resource>& ResourcesList::get_list_of_resources() const{
  /**
   * Return a constant reference to the vector containing  all resources
   */
  return _list_of_resources;
}

Resource& ResourcesList::get_resource(Resource_ID resource_id){
  /**
   * Takes resource_id, and return a reference to the resource.
   */
  for (auto &resource : get_list_of_resources()){
    if (resource.has_id(resource_id)) {
      return resource;
    }
  }
}

const Resource& ResourcesList::get_resource(Resource_ID resource_id) const{
  /**
   * Takes resource_id, and return a constant reference to the resource.
   */
  for (auto &resource : get_list_of_resources()){
    if (resource.has_id(resource_id)) {
      return resource;
    }
  }
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
