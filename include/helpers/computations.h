// resources_computation.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef RESOURCES_COMPUTATION_H
#define RESOURCES_COMPUTATION_H 1

#include "../helpers/resources_helper.h"
#include "../class/Acceleration.h"
//#include "../class/Resource.h"
//#include "../class/UpgradesList.h"
//#include "../class/Time.h"

class BigNum;
class Time;
class UpgradesManager;

namespace computation{

BigNum get_resource_per_second(Resource_ID resource_id, const UpgradesManager* upgrades_manager);

Acceleration get_current_acceleration(const UpgradesManager* upgrades_manager);

}

#endif // RESOURCES_COMPUTATION_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
