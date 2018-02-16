// game_global_variables.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "main/game_global_variables.h"




std::map<Resource_ID, std::string> global::resources_name_list()
{
  /**
   * Return a static (unique) const dictionary linking Resource_ID to the name of the resource
   */

  static const std::map<Resource_ID, std::string> output({
      {Resource_ID::kinetic_energy, "Kinetic energy"},
      {Resource_ID::dark_matter, "Dark matter"}
    });

  return output;
}


std::map<Upgrade_ID, std::string> global::upgrades_name_list()
{
  /**
   * Return a static (unique) const dictionary linking Upgrades_ID to the name of the upgrade
   */

  // up_names
  static const std::map<Upgrade_ID, std::string> output({
      // Science
      {Upgrade_ID::u_quantum_magnet, "Quantum magnetism"},
      {Upgrade_ID::u_kinetic_power, "Kinetic power"},
      {Upgrade_ID::u_kinetic_storage, "Kinetic storage"},
      {Upgrade_ID::u_quanta_expuls, "Quanta expulsor"},
          // Structures
      {Upgrade_ID::u_terminal, "Terminal"},
      {Upgrade_ID::u_quantum_generator, "Quantum generator"},
      {Upgrade_ID::u_compass, "Stellar compass"},
      {Upgrade_ID::u_radar, "Radar"},
      {Upgrade_ID::u_quantum_throttle, "Quantum throttle"},
      {Upgrade_ID::u_porthole, "Porthole"},
          // Upgrades
      {Upgrade_ID::u_kinetic_impulsor, "Kinetic impulsor"},
      {Upgrade_ID::u_quantum_conductor, "Quantum conductor"},
      {Upgrade_ID::u_dynamo, "Dynamo"},
      {Upgrade_ID::u_superconductor, "Superconductors"},
          // Incremental
      {Upgrade_ID::i_quant_coil, "Quantum coil"},
      {Upgrade_ID::i_level_a_cell, "Quantum Energy cell"},
      {Upgrade_ID::i_flywheel, "Flywheel"},
      {Upgrade_ID::i_hydrogen_burner, "Hydrogen burner"}
    });

  return output;
}


std::string global::upgrade_name(Upgrade_ID upgrade_id)
{
  /**
   * Helper that receives an ugprade ID and returns the name
   */
  return upgrades_name_list().find(upgrade_id)->second;
}

std::string global::resource_name(Resource_ID resource_id)
{
  /**
   * Helper that receives a resource ID and returns the name
   */
  return resources_name_list().find(resource_id)->second;
}

//}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
