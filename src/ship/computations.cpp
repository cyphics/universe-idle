// resources_computation.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "ship/computations.h"
#include "ship/UpgradesManager.h"

using Physics::Acceleration;

BigNum computation::get_resource_per_second(Resource_ID resource_id, const UpgradesManager* upgrades_manager)
{

  int boost_1_level = upgrades_manager->get_upgrade_level(Upgrade_ID::boost_1);
  int boost_2_level = upgrades_manager->get_upgrade_level(Upgrade_ID::boost_2);

  switch (resource_id)
  {
    case Resource_ID::cinetic_energy:
      {
        return BigNum(boost_1_level + boost_2_level * 100);
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

  int boost_1_level = upgrades_manager->get_upgrade_level(Upgrade_ID::boost_1);
  int boost_2_level = upgrades_manager->get_upgrade_level(Upgrade_ID::boost_2);

  BigNum accel_num = BigNum(boost_1_level) + BigNum(boost_2_level) * 10;
  Acceleration current_acceleration(accel_num);

  return current_acceleration;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
