// resources_computation.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "ship/computations.h"
#include "ship/UpgradesManager.h"
#include "ship/upgrades_configuration.h"

using Physics::Acceleration;

BigNum computation::get_resource_per_second(Resource_ID resource_id, const UpgradesManager* upgrades_manager)
{

  int boost_1_level = upgrades_manager->get_upgrade_level(Upgrade_ID::boost_1);
  int boost_2_level = upgrades_manager->get_upgrade_level(Upgrade_ID::boost_2);
  int boost_3_level = upgrades_manager->get_upgrade_level(Upgrade_ID::boost_3);

  switch (resource_id)
  {
    case Resource_ID::cinetic_energy:
      {
        return BigNum(boost_1_level * GameConfig::Upgrade::boost_1_base_gain \
                      + boost_2_level * GameConfig::Upgrade::boost_2_base_gain \
                      + boost_3_level * GameConfig::Upgrade::boost_3_base_gain);
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

Acceleration computation::compute_current_acceleration(const UpgradesManager *upgrades_manager)
{
  /**
     Compute acceleration according to bought upgrades.
   */

  int boost_1_level = upgrades_manager->get_upgrade_level(Upgrade_ID::boost_1);
  int boost_2_level = upgrades_manager->get_upgrade_level(Upgrade_ID::boost_2);
  int boost_3_level = upgrades_manager->get_upgrade_level(Upgrade_ID::boost_3);

  BigNum accel_num = BigNum(boost_1_level) * GameConfig::Upgrade::boost_1_base_gain + \
                     BigNum(boost_2_level) * GameConfig::Upgrade::boost_2_base_gain + \
                     BigNum(boost_3_level) * GameConfig::Upgrade::boost_3_base_gain;

  Acceleration current_acceleration(accel_num);

  return current_acceleration;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
