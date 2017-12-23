// Acceleration.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <math.h>
#include "../../include/class/PhysicalUnit.h"
#include "../../include/class/Acceleration.h"

Acceleration::Acceleration(BigNum num_value)
    : PhysicalUnit(num_value)
{}

// Acceleration::Acceleration(const Speed& speed_beginning, const Speed& speed_end, const Time& time)
//     : PhysicalUnit((speed_end - speed_beginning).get_numerical_value() / (time * time).get_numerical_value())
// {}

Acceleration::~Acceleration(){}

Acceleration& Acceleration::operator=(const Acceleration& rhs){}
Acceleration& Acceleration::operator+=(const Acceleration& rhs){}
Acceleration& Acceleration::operator-=(const Acceleration& rhs){}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
