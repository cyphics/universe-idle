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
using Physics::Speed;

Acceleration computation::compute_current_acceleration(const UpgradesManager *upgrades_manager)
{
  /**
     Compute acceleration according to bought upgrades.
   */

  int i_quant_coil_level = upgrades_manager->get_upgrade_level(Upgrade_ID::i_quant_coil);
  int i_level_a_cell_level = upgrades_manager->get_upgrade_level(Upgrade_ID::i_level_a_cell);

  BigNum accel_num = ( BigNum(i_level_a_cell_level) * GameConfig::Upgrade::i_level_a_cell_acceleration_gain ) * GameConfig::global_multiplier;

  return Acceleration(accel_num) ;
}



//////////////////////////////////////////////////////////////////////
// $Log:$
//
