// ResourcesManager.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/ResourcesManager.h"
#include "../../include/class/UpgradesManager.h"
#include "../../include/helpers/resources_helper.h"
#include "../../include/helpers/resources_computation.h"

ResourcesManager::ResourcesManager(ResourcesList* stock_of_resources, UpgradesManager* upgrades_manager)
    : _stock_of_resources(stock_of_resources), _upgrades_manager(upgrades_manager)
{}

ResourcesManager::~ResourcesManager(){}

void ResourcesManager::gather_resources(Time elapsed_time){
  // Gather resources one by one
  BigNum new_amount(0);

  for (auto resource : _stock_of_resources->get_list_of_resources()){
    switch (resource.get_ID()) {
      case Resource_ID::cinetic_energy: {
        //compute_cinetic_energy(Time elapsed_time, UpgradesList *list_of_upgrades)
        //BigNum compute_cinetic_energy(Time elapsed_time, const UpgradesList& list_of_upgrades){
        new_amount = compute_cinetic_energy(elapsed_time, _upgrades_manager->get_list_of_upgrades());
        break;
      }
      case Resource_ID::dark_matter: {
        new_amount = compute_dark_matter(elapsed_time, _upgrades_manager->get_list_of_upgrades());
        break;
      }
      default:
        break;
    }
    resource.add_resource_amount(new_amount);
  }
}

ResourcesList* ResourcesManager::get_resources_list() const{
  return _stock_of_resources;
}

ResourcesList* ResourcesManager::get_resources_list(){
  return _stock_of_resources;
}

Time ResourcesManager::get_time_until_in_stock(const Price& price) const{
  /**
   * Take a Price as input
   * Return time to wait to have enough resources to pay price
   */
  Time time(0);

  for (auto resource : price.get_resources_to_pay()) {
    // resource is of type ResourceAmount !
    if (get_time_until_in_stock(resource._resource_ID, resource._amount) > time)
      time = get_time_until_in_stock(resource._resource_ID, resource._amount);
  }

  return time;
}

Time ResourcesManager::get_time_until_in_stock(const Resource_ID& resource_id, BigNum required_amount) const{
/*
 * Take resource_ID and amount as input
 * Return time to wait to have indicated amount of resource
 */

  Time time(0);

  BigNum resource_per_second = get_real_resource(resource_id).get_amount_per_second();
  BigNum current_amount = get_real_resource(resource_id).get_current_amount();
  BigNum needed_amount = required_amount - current_amount;

  // Compute
  if (needed_amount > 0){
    time = Time(needed_amount/resource_per_second);
  }

  return time;
}

Resource& ResourcesManager::get_real_resource(Resource_ID resource){
  /**
   *
   */
  return get_resources_list()->get_resource(resource);
}

Resource& ResourcesManager::get_real_resource(Resource_ID resource) const{
  return get_resources_list()->get_resource(resource);
}

BigNum ResourcesManager::get_resource_amount(Resource_ID resource_id) const{
  return get_real_resource(resource_id).get_current_amount();
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
