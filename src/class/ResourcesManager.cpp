// ResourcesManager.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/ResourcesManager.h"
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

const ResourcesList* ResourcesManager::get_resources_list() const{
  return _stock_of_resources;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
