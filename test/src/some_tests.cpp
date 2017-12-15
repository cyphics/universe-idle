// -*- compile-command: "make -sk"; -*-
// some_func.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// $Log:$
//

#include "catch.hpp"
#include <class/a_class.h>

TEST_CASE( "Some tests" ) {
    AnObject a_num = AnObject(3);
    //REQUIRE( a_num.get_value() == 3 );
    REQUIRE (1 == 1);
    REQUIRE (a_num.get_value() == 3);

}
