// Speed.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////
#include "../../include/class/Speed.h"

Speed::Speed(BigNum num_value)
    : PhysicalUnit(num_value)
{}

// Speed::Speed(const Distance& distance, const Time& time)
//     : PhysicalUnit(distance.get_numerical_value() * time.get_numerical_value())
// {}

Speed::Speed(const Speed& speed)
    : PhysicalUnit(speed.get_numerical_value())
{}

Speed::~Speed(){}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
