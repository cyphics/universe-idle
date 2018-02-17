// Speed_test.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////
#include "../include/catch.hpp"
#include "physics/Speed.h"
#include "main/initiate.h"
#include "physics/constants_physics.h"

using Speed;

TEST_CASE( "Speed initialization" ) {
  REQUIRE( Speed(1).num() == 1 );
  REQUIRE( Speed(1).num() == Units::minimal_distance );
  REQUIRE( Speed(1000).num() == Speed(1, Units::zeptometer).num() );
  REQUIRE( Speed(BigNum(1, 6)).num() == Speed(1, Units::attometer).num() );
  REQUIRE( Speed(1, Units::meter).num() == Speed(1000, Units::millimeter).num() );
  REQUIRE( Speed(1, Units::meter).num() == Speed(BigNum(1, 24), Units::yoctometer).num() );


}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
