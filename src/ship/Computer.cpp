// Computer.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <limits>
#include "ship/Computer.h"
#include "ship/resources_helper.h"
#include "main/game_configuration.h"
#include "physics/compute_physics.h"


Computer::Computer(UpgradesManager* upgrades, GameState* state)
    :_upgrades(upgrades), _state(state)
{}

BigNum Computer::resource_per_second(Resource_ID resource) const
{
  int u_quant_coil_level = _upgrades->get_upgrade_level(Upgrade_ID::i_quant_coil);
  int u_level_a_cell_level = _upgrades->get_upgrade_level(Upgrade_ID::i_level_a_cell);

  BigNum new_amount = 0;
  switch (resource)
  {
    case Resource_ID::kinetic_energy:
      {

        new_amount = u_quant_coil_level * GameConfig::Upgrade::i_quant_coil_kinetic_gain;

        // quantum conductor effect
        if (_upgrades->is_bought(Upgrade_ID::u_quantum_conductor)) {
          new_amount *= GameConfig::Upgrade::u_quantum_conductor_gain;
        }

        // Add quantum cells
        if (_upgrades->is_bought(Upgrade_ID::u_quantum_synergy)) {
          new_amount += u_level_a_cell_level * GameConfig::Upgrade::i_level_a_cell_kinetic_gain;
        }

        if (_upgrades->is_bought(Upgrade_ID::u_dynamo)) {
          new_amount += _state->get_speed().num();
        }
        //+ up_3_level * GameConfig::Upgrade::increm_upgrade_3_base_gain;
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

  return new_amount * GameConfig::global_multiplier;

}

Acceleration Computer::current_acceleration() const
{
  /**
     Compute acceleration according to upgrades.
  */

  int i_quant_coil_level = _upgrades->get_upgrade_level(Upgrade_ID::i_quant_coil);
  int i_level_a_cell_level = _upgrades->get_upgrade_level(Upgrade_ID::i_level_a_cell);

  BigNum accel_num = ( BigNum(i_level_a_cell_level)
                       * GameConfig::Upgrade::i_level_a_cell_acceleration_gain );

  if (_upgrades->is_bought(Upgrade_ID::u_quantum_synergy)) {
    accel_num += i_quant_coil_level * GameConfig::Upgrade::i_quant_coil_acceleration_gain;
  }

  accel_num *= GameConfig::global_multiplier;
  return Acceleration(accel_num) ;
}

Time Computer::time_until_destination(Physics::Distance destination) const
{
  Distance remaining_distance = destination - _state->get_distance();

  if (remaining_distance.num() > 0)
    try{
      return Physics::remaining_time(remaining_distance,
                                     _state->get_speed(),
                                     _state->get_acceleration());
    } catch(std::string e)
    {
      std::cout << e << "Returning inifinite time"<< "\n";
      return Time(std::numeric_limits<double>::infinity());
    }
  else
    return Time(0);
}

Speed Computer::new_speed(Time elapsed_time) const
{
  return Speed( ( current_acceleration().num()
                  * elapsed_time.num() )
                + _state->get_speed().num() );
}




Distance Computer::traveled_distance(Time elapsed_time) const
{
  return Physics::traveled_distance(_state->get_speed(), elapsed_time, _state->get_acceleration());
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
