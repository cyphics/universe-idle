// resources_computation.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "ship/computations.h"
#include "ship/UpgradesManager.h"
#include "main/game_configuration.h"

using Physics::Acceleration;

BigNum computation::get_resource_per_second(Resource_ID resource_id, const UpgradesManager* upgrades_manager)
{
  // 1 = quantum coils
  // 2 = Level A Cells
  // 3 = ?
  int up_1_level = upgrades_manager->get_upgrade_level(Upgrade_ID::i_quant_coil);
  int up_2_level = upgrades_manager->get_upgrade_level(Upgrade_ID::i_level_a_cell);

  BigNum new_amount;
  switch (resource_id)
  {
    case Resource_ID::cinetic_energy:
      {
        new_amount = up_1_level * GameConfig::Upgrade::i_quant_coil_cinetic_gain;
        new_amount += up_2_level * GameConfig::Upgrade::i_level_a_cell_cinetic_gain;
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

  int i_quant_coil_level = upgrades_manager->get_upgrade_level(Upgrade_ID::i_quant_coil);
  int i_level_a_cell_level = upgrades_manager->get_upgrade_level(Upgrade_ID::i_level_a_cell);

  BigNum accel_num = BigNum(i_level_a_cell_level) * GameConfig::Upgrade::i_level_a_cell_acceleration_gain;

  return Acceleration(accel_num);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
