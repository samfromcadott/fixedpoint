#pragma once

#include <iostream>

class real {
private:
	long value;
	static const long shift = 24; // The number of bits of the fractional part
	static const long ONE = 1 << shift; // 1.0 represented by this class

public:
	// Operators
	real operator+(real other) {
		real result;
		result.value = value + other.value;
		return result;
	}

	real operator-(real other) {
		real result;
		result.value = value - other.value;
		return result;
	}

	real operator*(real other) {
		real result;
		result.value = (value * other.value) >> shift;
		return result;
	}

	real operator/(real other) {
		real result;
		result.value = (value << shift) / other.value;
		return result;
	}

	real& operator=(const real& other) {
		value = other.value;
		return *this;
	}

	// Type conversions
	operator long() const {
		long n = value;
		n >>= shift;
		n |= (unsigned long)(value<0) << 63; // Apply the sign
		return n;
	}

	operator float() const {
		return float(value) / float(ONE);
	}

	operator double() const {
		return double(value) / double(ONE);
	}

	// Constructors
	real() {
		value = 0;
	}

	real(const long value) {
		long n = value;
		this->value = n << shift;
		this->value |= (unsigned long)(value<0) << 63; // Apply the original sign
	}

	real(const int value) {
		long n = value;
		this->value = n << shift;
		this->value |= (unsigned long)(value<0) << 63; // Apply the original sign
	}

	real(const double value) {
		this->value = long(value * ONE);
	}

	real(const float value) {
		this->value = long(value * ONE);
	}

	virtual ~real(){}
};
