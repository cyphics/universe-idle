// upgrades_configuration.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// $Log:$
//

#ifndef GAME_CONFIGURATION_H
#define GAME_CONFIGURATION_H 1


#include "ship/upgrades_helper.h"
#include "ship/Price.h"
#include "physics/constants_physics.h"



namespace GameConfig
{

//const BigNum initial_game_resources = BigNum(65);
const BigNum initial_game_resources = BigNum(100000);
const double global_multiplier = 1;
//const Physics::Distance final_destination = Physics::Units::diameter_universe;
const Physics::Distance final_destination = Physics::Units::radius_proton;

namespace Computations
{

const double kinetic_impulsor_speed_gain = 0.001;

}

namespace Upgrade
{

/////////////////
// Incremental //
/////////////////

// Quantom coil
const double i_quant_coil_increase_factor = 1.15;
const Price i_quant_coil_price = Price(Resource_ID::kinetic_energy, BigNum(20));
const std::vector<Upgrade_ID> i_quant_coil_depend = {Upgrade_ID::u_quantum_magnet};
const double i_quant_coil_kinetic_gain = 1;
const double i_quant_coil_acceleration_gain = 0.001;
const std::vector<Upgrade_ID> i_quant_coil_dep = {Upgrade_ID::u_terminal, Upgrade_ID::u_quantum_generator};
const std::string i_quant_coil_desc = "+ energy over time";

// Level A Energy cells
const double i_level_a_cell_increase_factor = 1.15;
const Price i_level_a_cell_price = Price(Resource_ID::kinetic_energy, BigNum(1000));
const std::vector<Upgrade_ID> i_level_a_cell_depend = {Upgrade_ID::u_level_a_boost};
const double i_level_a_cell_kinetic_gain = 1;
const double i_level_a_cell_acceleration_gain = 0.001;
const std::vector<Upgrade_ID> i_level_a_cell_dep = {Upgrade_ID::u_terminal, Upgrade_ID::u_quantum_throttle};
const std::string i_level_a_cell_desc = "+ speed";

// ?
const double increm_upgrade_3_increase_factor = 1.15;
const Price increm_upgrade_3_price = Price(Resource_ID::kinetic_energy, BigNum(11000));
const std::vector<Upgrade_ID> increm_upgrade_3_depend = {Upgrade_ID::u_level_a_boost};
const double increm_upgrade_3_acceleration_gain = 1000;

/////////////////////
//     Upgrades    //
/////////////////////

// Kinetic impulsor
const Price u_kinetic_impulsor_price = Price(Resource_ID::kinetic_energy, BigNum(1500));
const std::vector<Upgrade_ID> u_kinetic_impulsor_dep = {Upgrade_ID::u_kinetic_power};
const std::string u_kinetic_impulsor_desc = "Click now generates energy AND speed";

// Quantum conductor
const Price u_quantum_conductor_price = Price(Resource_ID::kinetic_energy, BigNum(150));
const std::vector<Upgrade_ID> u_quantum_conductor_dep = {Upgrade_ID::u_kinetic_impulsor};
const std::string u_quantum_conductor_desc = "Improve quantum coil effectiveness";
const double u_quantum_conductor_gain = 3;

// Dynamo
const Price u_dynamo_price = Price(Resource_ID::kinetic_energy, BigNum(1500));
const std::vector<Upgrade_ID> u_dynamo_dep = {Upgrade_ID::u_quanta_expuls};
const std::string u_dynamo_desc = "Energy is now generated from speed";

// Quantum synergy
const Price u_quantum_synergy_price = Price(Resource_ID::kinetic_energy, BigNum(15000));
const std::vector<Upgrade_ID> u_quantum_synergy_dep = {Upgrade_ID::u_dynamo};
const std::string u_quantum_synergy_desc = "Coils generate speed and Cells generate energy";

// Superconductor
const Price u_superconductor_price = Price(Resource_ID::kinetic_energy, BigNum(1500));
const std::vector<Upgrade_ID> u_superconductor_dep = {Upgrade_ID::u_superconductor};
const std::string u_superconductor_desc = "Improve energy generation";
const double u_superconductor_gain = 10;


/////////////
// Science //
/////////////

// Quantum magnetism
const Price u_quantum_magnet_price = Price(Resource_ID::kinetic_energy, BigNum(10));
const std::vector<Upgrade_ID> u_quantum_magnet_dep = {Upgrade_ID::u_terminal};
const std::string u_quantum_magnet_desc = "Unlocks energy generation";

// Kinetic power
const Price u_kinetic_power_price = Price(Resource_ID::kinetic_energy, BigNum(150));
const std::vector<Upgrade_ID> u_kinetic_power_dep = {Upgrade_ID::u_quantum_magnet};
const std::string u_kinetic_power_desc = "Unlocks kinetic technologies";

// Quanta expulsion
const Price u_quanta_expulsor_price = Price(Resource_ID::kinetic_energy, BigNum(15000));
const std::vector<Upgrade_ID> u_quanta_expulsor_dep = {Upgrade_ID::u_kinetic_power};
const std::string u_quanta_expulsor_desc = "Unlocks quantic propulsion structures";

////////////////
// Structures //
////////////////

// Terminal
const Price u_terminal_price = Price(Resource_ID::kinetic_energy, BigNum(5));
const std::string u_terminal_desc = "Reboot main terminal";

// Porthole
const Price u_porthole_price = Price(Resource_ID::kinetic_energy, BigNum(150));
const std::vector<Upgrade_ID> u_porthole_dep = {Upgrade_ID::u_terminal};
const std::string u_porthole_desc = "Unlocks... looking outside";

// quantum generator
const Price u_quantum_generator_price = Price(Resource_ID::kinetic_energy, BigNum(20));
const std::vector<Upgrade_ID> u_quantum_generator_dep = {Upgrade_ID::u_quantum_magnet};
const std::string u_quantum_generator_desc = "First energy generator";

// Compass
const Price u_compass_price = Price(Resource_ID::kinetic_energy, BigNum(200));
const std::vector<Upgrade_ID> u_compass_dep = {Upgrade_ID::u_quantum_magnet};
const std::string u_compass_desc = "Gives direction";

// Radar
const Price u_radar_price = Price(Resource_ID::kinetic_energy, BigNum(15000));
const std::vector<Upgrade_ID> u_radar_dep = {Upgrade_ID::u_porthole, Upgrade_ID::u_compass};
const std::string u_radar_desc = "Gives spacial informations";

// Quantum throttle
const Price u_quantum_throttle_price = Price(Resource_ID::kinetic_energy, BigNum(150));
const std::vector<Upgrade_ID> u_quantum_throttle_dep = {Upgrade_ID::u_quanta_expuls};
const std::string u_quantum_throttle_desc = "Your first throttle!";






}

namespace Message
{

const std::string greeting_message
("Hi! This is the emergency terminal."
 "We sort of... crashed.\n"
 "In space...\n"
 "and time...\n"
 "First, we need to restore the main terminal's power.\n"
 "The only energy source we have for now is kinetic energy generated by...\n"
"you...\n"
 "please, click the kinetic generator until we have enough energy to re-start the console"
 );


const std::string terminal_message
(
    "\n"
    "Brilliant! the main terminal is up and running!\n"
    "It will help us fix this mess.\n"
    "But to do that, we'll need an enormous amount of energy!\n"
    "We should then work on that at once!\n"
    "According to the main terminal, we"
 );

const std::string coil_message
(
    "\n"
    "Ok. We can now generate some energy over time. It won't be fast, but it's a start...\n"
    "Try builing some coils, and let's see how much energy it generates\n"
 );

const std::string first_coil_message
(
    "\n"
    "Oh, that's not much. But it will do for now...\n"
    "A good thing would be to move, don't you think?\n"
    "The main terminal gives us the plans for a new booster.\n"
 );

const std::string level_A_booster_message
(
    "\n"
    "Good! We have a brand new throttle!\n"
    "The more cells we add to the throttle, the faster we'll move!\n"
    ""
);


}
}


#endif
