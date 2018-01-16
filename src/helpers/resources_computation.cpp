// resources_computation.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/helpers/resources_computation.h"
#include "../../include/class/Time.h"
#include "../../include/class/UpgradesManager.h"

BigNum computation::get_resource_per_second(Resource_ID resource_id, const UpgradesManager* upgrades_manager){
  int small_boost_level = upgrades_manager->get_upgrade_level(Upgrade_ID::small_boost);
  switch (resource_id) {
    case Resource_ID::cinetic_energy: {
      return BigNum(small_boost_level);
      break;
    }
    case Resource_ID::dark_matter: {
      return BigNum(1);
      break;
    }
default:
      break;
  }
}



//////////////////////////////////////////////////////////////////////
// $Log:$
//
