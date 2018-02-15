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
Time remaining_time(Distance distance_to_travel, Speed current_speed, Acceleration acceleration);
Distance traveled_distance(Speed init_speed, Time duration, Acceleration acceleration);
}
#endif // COMPUTE_PHYSICS_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
