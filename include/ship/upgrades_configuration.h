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

namespace Congif
{

namespace Upgrade{


// Small Boost
bool boost_1_availability = true;
double boost_1_increase_factor = 1.15;
Resource_ID boost_1_resource = Resource_ID::cinetic_energy;
BigNum boost_1_initial_cost = 10;


// Big Boost
bool boost_2_availability = true;
double boost_2_increase_factor = 1.15;
Resource_ID boost_2_resource = Resource_ID::cinetic_energy;
BigNum boost_2_initial_cost = 150;


// Click boost
bool click_boost_availability = true;
bool click_boost_uniqueness = true;
double click_boost_increase_factor = 1;
Resource_ID click_boost_resource = Resource_ID::cinetic_energy;
BigNum click_boost_initial_cost = 1500;

}

}
