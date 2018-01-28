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

#include "ship/upgrades_helper.h"

namespace GameConfig
{

namespace Upgrade{


// Small Boost
const bool boost_1_availability = true;
const double boost_1_increase_factor = 1.15;
const Resource_ID boost_1_resource = Resource_ID::cinetic_energy;
const BigNum boost_1_initial_cost = 15;
const BigNum boost_1_base_gain = 0.1;


// Big Boost
const bool boost_2_availability = true;
const double boost_2_increase_factor = 1.15;
const Resource_ID boost_2_resource = Resource_ID::cinetic_energy;
const BigNum boost_2_initial_cost = 100;
const BigNum boost_2_base_gain = 1;


// Mega Boost
const bool boost_3_availability = true;
const double boost_3_increase_factor = 1.15;
const Resource_ID boost_3_resource = Resource_ID::cinetic_energy;
const BigNum boost_3_initial_cost = 1100;
const BigNum boost_3_base_gain = 8;


// Click boost
const bool click_boost_availability = true;
const bool click_boost_uniqueness = true;
const double click_boost_increase_factor = 1;
const Resource_ID click_boost_resource = Resource_ID::cinetic_energy;
const BigNum click_boost_initial_cost = 1500;

}

}
