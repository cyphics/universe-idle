// -*- compile-command: "./compile.sh"; -*-
// Price.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////
#include "../../include/class/Price.h"

bool Price::has_resource_already(Resource_ID resource_id) const{
  /**
   * Check if a given resource is already stored in the Price object
   */
  for (auto existing_resource : _resources_to_pay) {
    if (existing_resource._resource_ID != resource_id) return false;
  }
  return true;
}

void Price::add_resource(Resource_ID resource_id, BigNum amount){
  /**
   * Add a resource to the price object
   */

  // If Price object already contains the given resource, just add the amount
  if (has_resource_already(resource_id)) {
    get_existing_resource(resource_id)._amount += amount;
  }
  // Else, push_back the resource in the Price object
  else{
    _resources_to_pay.push_back(ResourceAmount(resource_id, amount));
  }
}


bool Price::can_be_payed(const ResourcesList& stock_of_resources) const{
  /**
   * Take a list of required resources (contained in a Price object)
     and check availability in a ResourceList for each resource.
   */

  // Check each resource contained in Price object
  for (auto required_resource : _resources_to_pay) {
    Resource_ID resource_ID = required_resource._resource_ID;
    BigNum required_amount = required_resource._amount;
    BigNum current_amount = stock_of_resources.get_resource_amount(resource_ID);

    if (current_amount < required_amount) return false;
  }

  return true;

}

ResourceAmount& Price::get_existing_resource(Resource_ID resource_id){

}

BigNum Price::get_resource_amount(Resource_ID resource_id) const{

}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
