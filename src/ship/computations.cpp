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
  // 1 = quantum coils
  // 2 = Level A Cells
  // 3 = ?
  int up_1_level = upgrades_manager->get_upgrade_level(Upgrade_ID::increm_upgrade_1);
  int up_2_level = upgrades_manager->get_upgrade_level(Upgrade_ID::increm_upgrade_2);
  int up_3_level = upgrades_manager->get_upgrade_level(Upgrade_ID::increm_upgrade_3);

  BigNum new_amount;
  switch (resource_id)
  {
    case Resource_ID::cinetic_energy:
      {
        new_amount = up_1_level * GameConfig::Upgrade::increm_upgrade_1_cinetic_gain;
        new_amount += up_2_level * GameConfig::Upgrade::increm_upgrade_2_cinetic_gain;
        //+ up_3_level * GameConfig::Upgrade::increm_upgrade_3_base_gain;
        return new_amount;
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

  int increm_upgrade_1_level = upgrades_manager->get_upgrade_level(Upgrade_ID::increm_upgrade_1);
  int increm_upgrade_2_level = upgrades_manager->get_upgrade_level(Upgrade_ID::increm_upgrade_2);
  int increm_upgrade_3_level = upgrades_manager->get_upgrade_level(Upgrade_ID::increm_upgrade_3);

  BigNum accel_num = BigNum(increm_upgrade_2_level) * GameConfig::Upgrade::increm_upgrade_2_acceleration_gain + \
                     BigNum(increm_upgrade_3_level) * GameConfig::Upgrade::increm_upgrade_3_acceleration_gain;

  return Acceleration(accel_num);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
