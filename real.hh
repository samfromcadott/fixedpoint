#pragma once

#include <iostream>

class real {
private:
	long value;
	static const long shift = 24; // The number of bits of the fractional part
	static const long ONE = 1 << shift; // 1.0 represented by this class

public:
	// Operators
	inline real operator+(real other) {
		real result;
		result.value = value + other.value;
		return result;
	}

	inline real operator-(real other) {
		real result;
		result.value = value - other.value;
		return result;
	}

	inline real operator*(real other) {
		real result;
		result.value = (value * other.value) >> shift;
		return result;
	}

	inline real operator/(real other) {
		real result;
		result.value = (value << shift) / other.value;
		return result;
	}

	inline real& operator=(const real& other) {
		value = other.value;
		return *this;
	}

	inline bool operator==(const real& other) {
		return value == other.value;
	}

	// Type conversions
	inline operator long() const {
		long n = value;
		n >>= shift;
		n |= (unsigned long)(value<0) << 63; // Apply the sign
		return n;
	}

	inline operator float() const {
		return float(value) / float(ONE);
	}

	inline operator double() const {
		return double(value) / double(ONE);
	}

	// Constructors
	inline real() {
		value = 0;
	}

	inline real(const long value) {
		long n = value;
		this->value = n << shift;
		this->value |= (unsigned long)(value<0) << 63; // Apply the original sign
	}

	inline real(const int value) {
		long n = value;
		this->value = n << shift;
		this->value |= (unsigned long)(value<0) << 63; // Apply the original sign
	}

	inline real(const double value) {
		this->value = long(value * ONE);
	}

	inline real(const float value) {
		this->value = long(value * ONE);
	}

	virtual ~real(){}
};
