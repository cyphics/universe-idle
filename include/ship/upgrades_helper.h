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

#include "ship/resources_helper.h"

// upgrades_list
enum class Upgrade_ID {
  // science
  u_quantum_magnet, // quantum magnetism tech
  u_kinetic_power,
  u_quanta_expuls,
  u_nuclear_transmut,
  u_hydrogen_economy,
  // Structures
  u_terminal,  // access to main terminal
  u_level_a_boost, // first throttle
  u_compass, // establish direction
  u_window,
  u_radar, // can see where we are !
  u_quantum_generator,
  u_atomic_collector,
  u_hydrogen_collector,
  // Upgrades
  u_cinetic_impulsor, // the click gives speed
  u_quantum_conductor,
  u_dynamo, // Gives energy from speed
  // Incremental
  i_quant_coil, // generate energy through coils
  i_flywheel, // store kinetic power
  i_level_a_cell, // gives energy to throttle -> speed
};



#endif // UPGRADES_HELPER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
