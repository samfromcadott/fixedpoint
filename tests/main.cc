#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <real.hh>

TEST_CASE("Test conversion to long") {
	real x(100);
	real y(0);
	real z(-20);

	CHECK( long(x) == 100);
	CHECK( long(y) == 0);
	CHECK( long(z) == -20);
}

TEST_CASE("Test conversion to double") {
	real a(100);
	real b(6.5);
	real c(0);
	real d(-2);
	real e(-2.5);

	CHECK( double(a) == 100);
	CHECK( double(b) == 6.5);
	CHECK( double(c) == 0);
	CHECK( double(d) == -2);
	CHECK( double(e) == -2.5);
}

TEST_CASE("Equality") {
	real a(2);
	real b(2);

	CHECK(a == b);
}
