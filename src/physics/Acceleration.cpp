// Acceleration.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <math.h>
#include "physics/PhysicalUnit.h"
#include "physics/Acceleration.h"

using namespace Physics;

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
