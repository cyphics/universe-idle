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

ResourcesManager::ResourcesManager(UpgradesList* list_of_upgrades, ResourcesList* stock_of_resources)
    : _list_of_upgrades(list_of_upgrades), _stock_of_resources(stock_of_resources)
{}

ResourcesManager::~ResourcesManager(){}

void ResourcesManager::gather_resources(Time elapsed_time){
  // Gather resources one by one
  BigNum new_amount(0);

  for (auto resource : _stock_of_resources->get_list_of_resources()){
    switch (resource.get_ID()) {
      case Resource_ID::cinetic_energy: {
        BigNum new_amount = compute_cinetic_energy(elapsed_time, _list_of_upgrades);
        break;
      }
      case Resource_ID::dark_matter: {
        BigNum new_amount = compute_dark_matter(elapsed_time, _list_of_upgrades);
        break;
      }
      default:
        break;
    }
    resource.add_resource_amount(new_amount);
  }
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
