// -*- compile-command: "./compile.sh"; -*-
// upgrades_helper.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UPGRADES_HELPER_H
#define UPGRADES_HELPER_H 1

#include <map>
#include "ship/resources_helper.h"

// upgrades_list
enum class Upgrade_ID {
  // science
  u_quantum_magnet, // quantum magnetism tech
  u_kinetic_power,
  u_kinetic_storage,
  u_quanta_expuls,
  u_nuclear_transmut,
  u_hydrogen_economy,
  u_solar_energy,
  u_photovoltaics,
  u_gravitational_generator,
  u_cryogenics,
  // Structures
  u_terminal,  // access to main terminal
  u_quantum_generator,
  u_porthole,
  u_compass, // establish direction
  u_level_a_boost, // first throttle
  u_radar, // can see where we are !
  u_quantum_throttle,
  u_atomic_collector,
  u_hydrogen_collector,
  u_cryogenic_chamber,
  // Upgrades
  u_kinetic_impulsor, // the click gives speed
  u_quantum_conductor,
  u_dynamo, // Gives energy from speed
  u_superconductor,
  u_hyperconductor,
  u_overconductor,
  // Incremental
  i_quant_coil, // generate energy through coils
  i_flywheel, // store kinetic power
  i_level_a_cell, // gives energy to throttle -> speed
  i_hydrogen_burner,
  i_solar_cooker,
  i_solar_panel,
  i_solar_satellite
};

//std::map<Upgrade_ID, std::string> upgrades_name_list();

//std::string upgrade_name(Upgrade_ID upgrade_id);


#endif // UPGRADES_HELPER_H
  //////////////////////////////////////////////////////////////////////
  // $Log:$
  //
