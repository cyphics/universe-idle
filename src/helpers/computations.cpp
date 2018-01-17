// resources_computation.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/helpers/computations.h"
#include "../../include/class/Time.h"
#include "../../include/class/UpgradesManager.h"

BigNum computation::get_resource_per_second(Resource_ID resource_id, const UpgradesManager* upgrades_manager)
{
  int small_boost_level = upgrades_manager->get_upgrade_level(Upgrade_ID::small_boost);
  int big_boost_level = upgrades_manager->get_upgrade_level(Upgrade_ID::big_boost);
  switch (resource_id)
  {
    case Resource_ID::cinetic_energy:
      {
        return BigNum(small_boost_level + big_boost_level * 100);
        break;
      }
    case Resource_ID::dark_matter:
      {
        return BigNum(1);
        break;
    }
    default:
      break;
  }
}

Acceleration computation::get_current_acceleration(const UpgradesManager *upgrades_manager)
{
  /**
     Compute acceleration according to bought upgrades.
   */

  int small_boost_level = upgrades_manager->get_upgrade_level(Upgrade_ID::small_boost);
  int big_boost_level = upgrades_manager->get_upgrade_level(Upgrade_ID::big_boost);

  BigNum accel_num = BigNum(small_boost_level) + BigNum(big_boost_level) * 10;
  Acceleration current_acceleration(accel_num);

  return current_acceleration;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
