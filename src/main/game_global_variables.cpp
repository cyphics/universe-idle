// game_global_variables.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "main/game_global_variables.h"

std::map<Upgrade_ID, std::string> global::upgrades_name_list()
{
  /**
   * Return a static (unique) const dictionary linking Upgrades_ID to the name of the upgrade
   */
  // upgrade_names
  static const std::map<Upgrade_ID, std::string> output({
      {Upgrade_ID::u_terminal, "Terminal"},
      {Upgrade_ID::u_quantum_magnet, "Quantum magnetism"},
      {Upgrade_ID::u_level_a_boost, "Quantum throttle"},
      {Upgrade_ID::u_radar, "Radar"},
      {Upgrade_ID::u_compass, "Stellar compass"},
      {Upgrade_ID::u_cinetic_impulsor, "Cinetic Impulsor"},
      {Upgrade_ID::u_dynamo, "Dynamo"},
      {Upgrade_ID::i_quant_coil, "Quantum coil"},
      {Upgrade_ID::i_level_a_cell, "Quantum Energy cell"} ,
 });

  return output;
}

std::map<Resource_ID, std::string> global::resources_name_list()
{
  /**
   * Return a static (unique) const dictionary linking Resource_ID to the name of the resource
   */

  static const std::map<Resource_ID, std::string> output({ {Resource_ID::cinetic_energy, "Cinetic energy"}, {Resource_ID::dark_matter, "Dark matter"} });

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
