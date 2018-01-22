// -*- compile-command: "./../../compile.sh"; -*-
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
#include "util/BigNum.h"

TEST_CASE( "Initialization" ) {
  REQUIRE( BigNum(0).get_significand() == 0 );
  REQUIRE( BigNum(0).get_exponant() == 0 );
  REQUIRE( BigNum(0.1).get_significand() == 0.1 );
  REQUIRE( BigNum(0.001).get_significand() == 0.001 );
  REQUIRE( BigNum(0.0001).get_significand() == 100 );
  REQUIRE( BigNum(0.00001).get_significand() == 10 );
  REQUIRE( BigNum(0.000001).get_significand() == 1 );
  REQUIRE( BigNum(1).get_significand() == 1 );
  REQUIRE( BigNum(10).get_significand() == 10 );
  REQUIRE( BigNum(100).get_significand() == 100 );
  REQUIRE( BigNum(1000).get_significand() == 1000 );
  REQUIRE( BigNum(10000).get_significand() == 10 );
  REQUIRE( BigNum(100000).get_significand() == 100 );
  REQUIRE( BigNum(1000000).get_significand() == 1 );

  REQUIRE( BigNum(0.1).get_exponant() == 0 );
  REQUIRE( BigNum(0.01).get_exponant() == 0 );
  REQUIRE( BigNum(0.001).get_exponant() == 0 );
  REQUIRE( BigNum(0.0001).get_exponant() == -6 );
  REQUIRE( BigNum(0.00001).get_exponant() == -6 );
  REQUIRE( BigNum(0.000001).get_exponant() == -6 );
  REQUIRE( BigNum(1).get_exponant() == 0 );
  REQUIRE( BigNum(10).get_exponant() == 0 );
  REQUIRE( BigNum(100).get_exponant() == 0 );
  REQUIRE( BigNum(1000).get_exponant() == 0 );
  REQUIRE( BigNum(10000).get_exponant() == 3 );
  REQUIRE( BigNum(100000).get_exponant() == 3 );
  REQUIRE( BigNum(1000000).get_exponant() == 6 );

  REQUIRE( BigNum(1, -9).get_exponant() == -9 );
  REQUIRE( BigNum(1, -8).get_exponant() == -9 );
  REQUIRE( BigNum(1, -7).get_exponant() == -9 );
  REQUIRE( BigNum(1, -6).get_exponant() == -6 );
  REQUIRE( BigNum(1, -5).get_exponant() == -6 );
  REQUIRE( BigNum(1, -4).get_exponant() == -6 );
  REQUIRE( BigNum(1, -3).get_exponant() == 0 );
  REQUIRE( BigNum(1, -2).get_exponant() == 0 );
  REQUIRE( BigNum(1, -1).get_exponant() == 0 );
  REQUIRE( BigNum(1, 0).get_exponant() == 0 );
  REQUIRE( BigNum(1, 1).get_exponant() == 0 );
  REQUIRE( BigNum(1, 2).get_exponant() == 0 );
  REQUIRE( BigNum(1, 3).get_exponant() == 0 );
  REQUIRE( BigNum(1, 4).get_exponant() == 3 );
  REQUIRE( BigNum(1, 5).get_exponant() == 3 );
  REQUIRE( BigNum(1, 6).get_exponant() == 6 );
  REQUIRE( BigNum(1, 7).get_exponant() == 6 );
  REQUIRE( BigNum(1, 8).get_exponant() == 6 );
  REQUIRE( BigNum(1, 9).get_exponant() == 9 );

  REQUIRE( BigNum(1, -9).get_significand() == 1 );
  REQUIRE( BigNum(1, -8).get_significand() == 10 );
  REQUIRE( BigNum(1, -7).get_significand() == 100 );
  REQUIRE( BigNum(1, -6).get_significand() == 1 );
  REQUIRE( BigNum(1, -5).get_significand() == 10 );
  REQUIRE( BigNum(1, -4).get_significand() == 100 );
  REQUIRE( BigNum(1, -3).get_significand() == 0.001 );
  REQUIRE( BigNum(1, -2).get_significand() == 0.01 );
  REQUIRE( BigNum(1, -1).get_significand() == 0.1 );
  REQUIRE( BigNum(1, 0).get_significand() == 1 );
  REQUIRE( BigNum(1, 1).get_significand() == 10 );
  REQUIRE( BigNum(1, 2).get_significand() == 100 );
  REQUIRE( BigNum(1, 3).get_significand() == 1000 );
  REQUIRE( BigNum(1, 4).get_significand() == 10 );
  REQUIRE( BigNum(1, 5).get_significand() == 100 );
  REQUIRE( BigNum(1, 6).get_significand() == 1 );
  REQUIRE( BigNum(1, 7).get_significand() == 10 );
  REQUIRE( BigNum(1, 8).get_significand() == 100 );
  REQUIRE( BigNum(1, 9).get_significand() == 1 );

  REQUIRE( BigNum(2.39, 2) == BigNum(239, 0) );
  REQUIRE( CompareBignums(BigNum(2.3923, 2), BigNum(239.23, 0)));
  REQUIRE( CompareBignums( BigNum(2.3923123456789, 2), BigNum(239.23123456789, 0)));
  REQUIRE( CompareBignums( BigNum(2.392312345678912345, 2),  BigNum(239.2312345678912, 0) ));
  REQUIRE( BigNum(1.234567891234567891, 2) == BigNum(123.45678912345678, 0) );
  REQUIRE( BigNum(0.000000000000000321, 16) == BigNum(3.21, 0) );
  REQUIRE( BigNum(1234567890, 0) == BigNum(1.234567890, 9) );


  //REQUIRE( BigNum(1234567890, 0) == BigNum(1.234567890, 9) );
  //0.0000001
  // REQUIRE( !CompareBignums( BigNum(2.3923121),  BigNum(2.3923122) ));
  // REQUIRE( CompareBignums( BigNum(2.39231211),  BigNum(2.39231212) ));

}


TEST_CASE( "Normalization" ) {

  BigNum a = BigNum(3, 0);

  // Equal

  REQUIRE( BigNum(3, 0) == BigNum(3, 0) );
  REQUIRE( BigNum(3, 0) == BigNum(3.0, 0) );
  REQUIRE( BigNum(3, 0) == BigNum(30, -1) );
  REQUIRE( BigNum(3, 0) == BigNum(300, -2) );
  REQUIRE( BigNum(3, 0) == BigNum(3000, -3) );
  REQUIRE( BigNum(3, 0) == BigNum(30000, -4) );
  REQUIRE( BigNum(3, 0) == BigNum(30000.0, -4) );
  REQUIRE( BigNum(3, 0) == BigNum(0.3, 1) );
  REQUIRE( BigNum(3, 0) == BigNum(0.03, 2) );
  REQUIRE( BigNum(3, 0) == BigNum(0.003, 3) );
  REQUIRE( BigNum(30, 3) == BigNum(300, 2 ));
  REQUIRE( BigNum(3.25, 5) == BigNum(325000 ));


  // Not equal

  REQUIRE( BigNum(3, 1) != BigNum(3, 0) );
  REQUIRE( BigNum(3, 1) != BigNum(3.0, 0) );
  REQUIRE( BigNum(3, 1) != BigNum(30, -1) );
  REQUIRE( BigNum(3, 1) != BigNum(300, -2) );
  REQUIRE( BigNum(3, 1) != BigNum(3000, -3) );
  REQUIRE( BigNum(3, 1) != BigNum(30000, -4) );
  REQUIRE( BigNum(3, 1) != BigNum(0.3, 1) );
  REQUIRE( BigNum(3, 1) != BigNum(0.03, 2) );
  REQUIRE( BigNum(3, 1) != BigNum(0.003, 3) );
  REQUIRE( BigNum(3, 1) != BigNum(0.0003, 4) );
  REQUIRE( BigNum(3, 1) != BigNum(0.00003, 5) );
  REQUIRE( BigNum(3, 1) != BigNum(0.00030, 4) );
  REQUIRE( BigNum(3, 1) != BigNum(3.0000000001, 0));
  REQUIRE( BigNum(3, 1) != BigNum(2.9999999999, 0));
  REQUIRE( BigNum(9.999999, 0) != BigNum(10, 0));
  REQUIRE( BigNum(99.999999, 0) != BigNum(100, 0));
  REQUIRE( BigNum(999.999999, 0) != BigNum(1000, 0));
}




TEST_CASE( "ADDITION" ) {

  REQUIRE( BigNum(1, 0) + BigNum(2, 0) == BigNum(3, 0));
  REQUIRE( BigNum(130, 0) + BigNum(239, 0) == BigNum(369, 0));
  REQUIRE( BigNum(130, 0) + BigNum(239, 2) == BigNum(24030, 0));

  REQUIRE( BigNum(100, 0) + BigNum(2, 0) == BigNum(102, 0));
  REQUIRE( BigNum(100, 0) + BigNum(2, 0) == BigNum(1.02, 2));
  REQUIRE( BigNum(100, 18) + BigNum(1, 0) == BigNum(100, 18));
  REQUIRE( BigNum(100, 15) + BigNum(1, 0) == BigNum(100, 15));
  REQUIRE( BigNum(100, 14) + BigNum(1, 0) == BigNum(100, 14));
  REQUIRE( BigNum(100, 13) + BigNum(1, 0) != BigNum(100, 13));
  REQUIRE( BigNum(999, 36) + BigNum(1, 0) == BigNum(999, 36));

}

TEST_CASE( "SUBSTITUTION") {
  //REQUIRE(BigNum( 2 ) - BigNum( 1 ) == BigNum( 1 ));
  REQUIRE(BigNum( 100 ) - BigNum( 10 ) == BigNum( 90 ));
  REQUIRE(BigNum( 10 ) - BigNum( 100 ) == BigNum( -90 ));

}

TEST_CASE( "MULTIPLICATION" ){
  REQUIRE( BigNum( 2 ) * BigNum(4) == BigNum( 8 ) );
  REQUIRE( BigNum( 2 ) * 4 == BigNum( 8 ) );
  REQUIRE( 4 * BigNum( 2 ) == BigNum( 8 ) );
  REQUIRE( BigNum(2, 9) * BigNum(1, 9) == BigNum(2, 18) );
  BigNum a = BigNum(200);
  a *= 2;
  REQUIRE( a == BigNum(400));
  //REQUIRE( BigNum(2, 9) * 0 == BigNum(0, 0) );
}

TEST_CASE( "DIVISION" ){
  REQUIRE( BigNum(2) / BigNum(2) == BigNum(1));
  REQUIRE( BigNum(10) / BigNum(10) == BigNum(1));
}


// TEST_CASE( "To String" )
// {
//   REQUIRE(BigNum(1).to_string() == "1");
//   REQUIRE(BigNum(2).to_string() == "2");
//   REQUIRE(BigNum(10).to_string() == "10");
//   REQUIRE(BigNum(100).to_string() == "100");
//   REQUIRE(BigNum(9).to_string() == "9");
//   REQUIRE(BigNum(99).to_string() == "99");
//   REQUIRE(BigNum(1000).to_string() == "1000");
//   REQUIRE(BigNum(1001).to_string() == "1001");
//   REQUIRE(BigNum(9999).to_string() == "9999");
//   REQUIRE(BigNum(10000).to_string() == "10e3");
//   REQUIRE(BigNum(100000).to_string() == "100e3");
//   REQUIRE(BigNum(1000000).to_string() == "1e6");
//   REQUIRE(BigNum(9999999).to_string() == "9.999e6");
//   REQUIRE(BigNum(10000000).to_string() == "1e9");
//   REQUIRE(BigNum(1.2).to_string() == "1.2");
//   REQUIRE(BigNum(1.23).to_string() == "1.23");
//   REQUIRE(BigNum(1.234).to_string() == "1.234");
//   REQUIRE(BigNum(1.2345).to_string() == "1.234");
//   REQUIRE(BigNum(1.234524232).to_string() == "1.234");
//   REQUIRE(BigNum(0.234524232).to_string() == "0.234");
//   REQUIRE(BigNum(0.034524232).to_string() == "0.034");
//   REQUIRE(BigNum(0.004524232).to_string() == "0.004");
//   REQUIRE(BigNum(0.000524232).to_string() == "524.232e-6");
//   REQUIRE(BigNum(0.000024232).to_string() == "24.232e-9");
//   REQUIRE(BigNum(0.000004232).to_string() == "4.232e-9");

//   REQUIRE(BigNum(-1).to_string() == "-1");
//   REQUIRE(BigNum(-0.234524232).to_string() == "-0.234");

// }

// TEST_CASE( "To String Human" ) {
//   REQUIRE(BigNum(3, 20).to_string_human() == "300.000 ");
//   REQUIRE( BigNum(1).to_string_human() == "1 atto" );
//   REQUIRE( BigNum(10).to_string_human() == "10 atto" );
//   REQUIRE( BigNum(100).to_string_human() == "100 atto" );
//   REQUIRE( BigNum(1000).to_string_human() == "1 femto" );
//   REQUIRE( BigNum(1001).to_string_human() == "1.001 femto" );
//   REQUIRE( BigNum(1000000).to_string_human() == "1.000 pico" );
//   REQUIRE( BigNum(1, 6).to_string_human() == "1.000 pico" );
//   REQUIRE( BigNum(1, 12).to_string_human() == "1.000 micro" );
//   REQUIRE( BigNum(1, 18).to_string_human() == "1.000 " );
//   //  REQUIRE( BigNum(1, 24).to_string_human() == "1.000 mega" );
//   REQUIRE( BigNum(1, 30).to_string_human() == "1.000 tera" );
//   REQUIRE( BigNum(1, 36).to_string_human() == "1.000 exa" );
//   REQUIRE( BigNum(1, 38).to_string_human() == "100.000 exa" );
//   //REQUIRE( BigNum(1, 39).to_string_human() == "infinity" );
//   REQUIRE( BigNum(1, 40).to_string_human() == "infinity" );
//   REQUIRE( BigNum(1, 400).to_string_human() == "infinity" );

// }
