// Time_test.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../include/catch.hpp"
#include "physics/Time.h"
#include "physics/constants_physics.h"

using Time;

TEST_CASE( "Time To_string" ) {
  REQUIRE( Time(0).to_string() == "0 seconds");
  REQUIRE( Time(1).to_string() == "1 seconds");
  REQUIRE( Time(18).to_string() == "18 seconds");
  REQUIRE( Time(60).to_string() == "1 minutes 0 seconds");
  REQUIRE( Time(120).to_string() == "2 minutes 0 seconds");
  REQUIRE( Time(122).to_string() == "2 minutes 2 seconds");
  REQUIRE( Time(3600).to_string() == "1 hours 0 seconds");
  REQUIRE( Time(3540).to_string() == "59 minutes 0 seconds");
  REQUIRE( Time(3661).to_string() == "1 hours 1 minutes 1 seconds");
  REQUIRE( Time(Units::day).to_string() == "1 days 0 seconds");
  REQUIRE( Time(Units::year).to_string() == "1 years 0 seconds");

}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
