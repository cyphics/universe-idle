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
bool small_boost_availability = true;
double small_boost_increase_factor = 1.15;
Resource_ID small_boost_resource = Resource_ID::cinetic_energy;
BigNum small_boost_initial_cost = 10;


// Big Boost
bool big_boost_availability = true;
double big_boost_increase_factor = 1.15;
Resource_ID big_boost_resource = Resource_ID::cinetic_energy;
BigNum big_boost_initial_cost = 150;


// Click boost
bool click_boost_availability = true;
bool click_boost_uniqueness = true;
double click_boost_increase_factor = 1;
Resource_ID click_boost_resource = Resource_ID::cinetic_energy;
BigNum click_boost_initial_cost = 1500;

}

}
