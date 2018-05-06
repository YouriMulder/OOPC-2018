#include "ostream"
#include "Vector.hpp"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE( "equality, equal" ){
   Vector v( 1, 2 );
   REQUIRE( v == Vector( 1, 2 ) );
}

TEST_CASE( "equality, unequal" ){
   Vector v( 1, 2 );
   REQUIRE( ! ( v == Vector( 1, 3 )) );
}

TEST_CASE( "constructor, two_parameters" ){
   Vector v( 3, 4 );
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "[3,4]" );
}

TEST_CASE("constructor, no_parameters"){
	Vector v;
	REQUIRE(v == Vector(0,0));
}

TEST_CASE( "multiply by integer" ){
   Vector v( 3, 4 );
   Vector x = v * 7;
   REQUIRE( v == Vector( 3, 4 ) );
   REQUIRE( x == Vector( 21, 28 ) );
}

TEST_CASE("integer multiplyed by Vector"){
	Vector v( 3, 4 );
   Vector x = v*7;
   REQUIRE( v == Vector( 3, 4 ) );
   REQUIRE( x == Vector( 21, 28 ) );
}

TEST_CASE ("add Vector to Vector"){
	Vector v(3,4);
	Vector x(4,4);
	Vector y = x+v;
	REQUIRE(y == Vector(7,8));
}

TEST_CASE( "add Vector into Vector" ){
   Vector v( 3, 10 );
   v += Vector( 6, 7 );
   REQUIRE( v == Vector( 9, 17 ) );
}

TEST_CASE( "multiply Vector into Vector" ){
   Vector v( 3, 10 );
   v *= 2;
   REQUIRE( v == Vector( 6, 20 ) );
}
