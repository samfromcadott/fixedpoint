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
	CHECK( ( real(2) == real(2) ) == true );
	CHECK( ( real(2) == real(3) ) == false );
	CHECK( ( real(0) == real(0) ) == true );
	CHECK( ( real(0.5) == real(0.5) ) == true );
	CHECK( ( real(-1) == real(1) ) == false );
	CHECK( ( real(-1) == real(-1) ) == true );
}
