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
#include "ship/Price.h"

namespace GameConfig
{

namespace Upgrade{


// Quantom coil
const double increm_upgrade_1_increase_factor = 1.15;
const Price increm_upgrade_1_price = Price(Resource_ID::cinetic_energy, BigNum(30));
const std::vector<Upgrade_ID> increm_upgrade_1_depend = {Upgrade_ID::unique_upgrade_2};
const double increm_upgrade_1_cinetic_gain = 1;
const std::vector<Upgrade_ID> increm_upgrade_1_dep = {Upgrade_ID::unique_upgrade_1, Upgrade_ID::unique_upgrade_2};

// Level A Energy cells
const double increm_upgrade_2_increase_factor = 1.15;
const Price increm_upgrade_2_price = Price(Resource_ID::cinetic_energy, BigNum(100));
const std::vector<Upgrade_ID> increm_upgrade_2_depend = {Upgrade_ID::unique_upgrade_3};
const double increm_upgrade_2_cinetic_gain = 100;
const double increm_upgrade_2_acceleration_gain = 100;

// ?
const bool increm_upgrade_3_availability = true;
const double increm_upgrade_3_increase_factor = 1.15;
const Price increm_upgrade_3_price = Price(Resource_ID::cinetic_energy, BigNum(11000));
const std::vector<Upgrade_ID> increm_upgrade_3_depend = {Upgrade_ID::unique_upgrade_3};
const double increm_upgrade_3_acceleration_gain = 1000;

/////////////////////
// Unique Upgrades //
/////////////////////

// Terminal
const Price unique_upgrade_1_price = Price(Resource_ID::cinetic_energy, BigNum(15));

// Quantum magnetism
const Price unique_upgrade_2_price = Price(Resource_ID::cinetic_energy, BigNum(20));
const std::vector<Upgrade_ID> unique_upgrade_2_dep = {Upgrade_ID::unique_upgrade_1};

// Level A Booster
const Price unique_upgrade_3_price = Price(Resource_ID::cinetic_energy, BigNum(1500));

}

}
