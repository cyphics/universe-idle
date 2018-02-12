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

enum class Upgrade_ID { u_terminal,  // access to main terminal
                        u_quantum_magnet, // quantum magnetism tech
                        u_level_a_boost, // first throttle
                        u_radar, // can see where we are !
                        u_cinetic_push, // the click gives speed
                        u_dynamo, // Gives energy from speed
                        i_quant_coil, // generate energy through coils
                        i_level_a_cell, // gives energy to throttle -> speed
};



#endif // UPGRADES_HELPER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
