// game_global_variables.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/helpers/game_global_variables.h"

std::map<Upgrade_ID, std::string> global::upgrades_name_list(){
  /**
   * Return a static (unique) const dictionary linking Upgrades_ID to the name of the upgrade
   */
  static const std::map<Upgrade_ID, std::string> output({ {Upgrade_ID::small_boost, "Small boost"}, {Upgrade_ID::big_boost, "Big boost"}, {Upgrade_ID::empty_upgrade, "Empty upgrade"} });

  return output;
}

std::map<Resource_ID, std::string> global::resources_name_list(){
  /**
   * Return a static (unique) const dictionary linking Resource_ID to the name of the resource
   */

  static const std::map<Resource_ID, std::string> output({ {Resource_ID::cinetic_energy, "Cinetic energy"}, {Resource_ID::dark_matter, "Dark matter"} });

  return output;
}

std::string global::upgrade_name(Upgrade_ID upgrade_id){
  /**
   * Helper that receives an ugprade ID and returns the name
   */
  return upgrades_name_list().find(upgrade_id)->second;
}

std::string global::resource_name(Resource_ID resource_id){
  /**
   * Helper that receives a resource ID and returns the name
   */
  return resources_name_list().find(resource_id)->second;
}

//}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
