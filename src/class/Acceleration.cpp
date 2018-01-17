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

Acceleration::~Acceleration(){}

Acceleration& Acceleration::operator=(const Acceleration& rhs){}
Acceleration& Acceleration::operator+=(const Acceleration& rhs){}
Acceleration& Acceleration::operator-=(const Acceleration& rhs){}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
