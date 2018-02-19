// compute_physics.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef COMPUTE_PHYSICS_H
#define COMPUTE_PHYSICS_H 1

#include "Time.h"
#include "Distance.h"
#include "Speed.h"
#include "Acceleration.h"

using namespace Physics;

namespace Physics
{
Time remaining_time(const Distance& distance_to_travel,const Speed& current_speed, const Acceleration& acceleration);
Distance traveled_distance(const Speed& init_speed, const Time& duration, const Acceleration& acceleration);
}
#endif // COMPUTE_PHYSICS_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
