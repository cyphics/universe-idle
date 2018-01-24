// compute_physics_test.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////
#include "../include/catch.hpp"
#include "physics/compute_physics.h"

TEST_CASE( "Compute Remaining Time" ) {

  REQUIRE(compute_remaining_time(Distance(1), Speed(1), Acceleration(0)).to_string() == Time(1).to_string());

}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
