// ResourcesManager.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/ResourcesManager.h"
#include "../../include/helpers/resources_helper.h"

ResourcesManager::ResourcesManager(UpgradesList* list_of_upgrades, ResourcesList* stock_of_resources)
    : _list_of_upgrades(list_of_upgrades), _stock_of_resources(stock_of_resources)
{}

ResourcesManager::~ResourcesManager(){}

void ResourcesManager::gather_resources(Time elapsed_time){
  // Gather resources one by one

  for (auto resource : _stock_of_resources->get_list_of_resources()){
    switch (resource.get_ID()) {
      case Resource_ID::cinetic_energy: {

        break;
      }
      case Resource_ID::dark_matter: {
        break;
      }

      default:
        break;
    }
  }
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
