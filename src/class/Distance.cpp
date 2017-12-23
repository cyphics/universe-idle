// Distance.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/Distance.h"
#include "../../include/class/Speed.h"

Distance::Distance(BigNum num_distance)
    :PhysicalUnit(num_distance)
{}

// Distance::Distance(const Time& elapsed_time, const Speed& speed)
//     :PhysicalUnit(elapsed_time.get_numerical_value() * speed)
// {
//   /**
//    * Build a Distance object based on given speed and time spent
//    */
// }

Distance::~Distance(){}



//////////////////////////////////////////////////////////////////////
// $Log:$
//
