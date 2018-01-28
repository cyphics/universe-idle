// resources_computation.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef RESOURCES_COMPUTATION_H
#define RESOURCES_COMPUTATION_H 1

#include "ship/resources_helper.h"
#include "physics/Acceleration.h"

class BigNum;
class UpgradesManager;

namespace computation{

BigNum get_resource_per_second(Resource_ID resource_id, const UpgradesManager* upgrades_manager);

Physics::Acceleration compute_current_acceleration(const UpgradesManager* upgrades_manager);

}

#endif // RESOURCES_COMPUTATION_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
