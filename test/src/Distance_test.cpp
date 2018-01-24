// Distance_test.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////


#include "../include/catch.hpp"
#include "physics/Distance.h"

using Physics::Distance;

TEST_CASE( "To_string" ) {
  REQUIRE( Distance(1).to_string() == "1e-18 meters" );
  REQUIRE( Distance(BigNum(1, 18)).to_string() == "1e0 meters" );
  REQUIRE( Distance(BigNum(100, 18)).to_string() == "100e0 meters" );
  REQUIRE( Distance(BigNum(1000, 18)).to_string() == "1e0 kilometer" );
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
