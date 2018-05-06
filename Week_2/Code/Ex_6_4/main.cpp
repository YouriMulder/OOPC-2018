#include "ostream"
#include "vector.hpp"

/*
	Test met gerrit's main ging goed,
	maar hij had een paar dingen anders gedaan dan ik
	met het printen gebruikt hij / en ik ,.

	Voorderest werkt de test goed!
*/


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Equality, equal") {
  Vector v(3, 4);
  REQUIRE(v == Vector(3, 4));
}

TEST_CASE("Equality, unequal") {
  Vector v(4, 4);
  REQUIRE(!(v == Vector(3, 4)));
}

TEST_CASE("Constructor, zero_parameters") {
  Vector v;
  std::stringstream s;
  s << v;
  REQUIRE(s.str() == "[0,0]");
}

TEST_CASE("Constructor, two_parameters") {
  Vector v(3, 4);
  std::stringstream s;
  s << v;
  REQUIRE(s.str() == "[3,4]");
}

TEST_CASE("Add two Vectors") {
  Vector v(4, 4);
  Vector x = v + Vector(5, 4);
  REQUIRE(x == Vector(9, 8));
}

TEST_CASE("Add one Vectors") {
  Vector v(4, 4);
  REQUIRE(v == +v);
}

TEST_CASE("Add Vector into Vector") {
  Vector v(4, 4);
  Vector x(5, 8);
  REQUIRE(Vector(9, 12) == (v += x));
}

TEST_CASE("Multiply Vector by int") {
  Vector v(4, 3);
  Vector x = v * 3;
  REQUIRE(x == Vector(12, 9));
}

TEST_CASE("Multiply int by Vector") {
  Vector v(4, 3);
  Vector x = 3 * v;
  REQUIRE(x == Vector(12, 9));
}

TEST_CASE("Multiply int into Vector") {
  Vector v(4, 11);
  REQUIRE(Vector(12, 33) == (v * 3));
}
