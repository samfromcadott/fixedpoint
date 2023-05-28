#include <iostream>
#include <cassert>

#include "real.hh"

void test_integer_conversion() {
	real x(100);
	real y(2.5f);
	real z;

	std::cout << "Conversion to long..." << '\n';
	assert( long(x) == 100 && "Convert real to long" );
	std::cout << "Test passed.\n";
}

void test_double_conversion() {
	real x(100);
	real y(2.5f);
	real z;

	std::cout << "Conversion to double..." << '\n';
	assert( double(y) == 2.5 && "Convert real to double" );
	std::cout << "Test passed.\n";
}

void test_addition() {
	real x(100);
	real y(-3);
}

int main() {
	std::cout << "Fixed point number test" << '\n';

	test_integer_conversion();
	test_double_conversion();
	test_addition();

	return 0;
}
