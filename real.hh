#pragma once

#include <cstdint>

class real {
private:
	int64_t value;
	static const int64_t shift = 32; // The number of bits of the fractional part
	static const int64_t ONE = int64_t(1) << shift; // 1.0 represented by this class

public:
	// Arithmetic operators
	real operator+(real other);
	real operator-(real other);
	real operator*(real other);
	real operator/(real other);

	// Assignment operators
	real& operator=(const real& other);
	real& operator=(const int& other);
	real& operator=(const int64_t& other);
	real& operator=(const float& other);
	real& operator=(const double& other);

	// Comparison operators
	bool operator==(const real& other);

	// Type conversions
	operator long() const;
	operator float() const;
	operator double() const;

	// Constructors
	real();
	real(const int64_t value);
	real(const int32_t value);
	real(const double value);
	real(const float value);

	virtual ~real(){}
};

// Arithmetic operators
real real::operator+(real other) {
	real result;
	result.value = value + other.value;
	return result;
}

real real::operator-(real other) {
	real result;
	result.value = value - other.value;
	return result;
}

real real::operator*(real other) {
	real result;
	result.value = (value * other.value) >> shift;
	return result;
}

real real::operator/(real other) {
	real result;
	result.value = (value << shift) / other.value;
	return result;
}

// Assignment operators
real& real::operator=(const real& other) {
	value = other.value;
	return *this;
}

real& real::operator=(const int& other) {
	*this = real(other);
	return *this;
}

real& real::operator=(const int64_t& other) {
	*this = real(other);
	return *this;
}

real& real::operator=(const float& other) {
	*this = real(other);
	return *this;
}

real& real::operator=(const double& other) {
	*this = real(other);
	return *this;
}

// Comparison operators
bool real::operator==(const real& other) {
	return value == other.value;
}

// Type conversions
real::operator long() const {
	int64_t n = value;
	n >>= shift;
	n |= (unsigned long)(value<0) << 63; // Apply the sign
	return n;
}

real::operator float() const {
	return float(value) / float(ONE);
}

real::operator double() const {
	return double(value) / double(ONE);
}

// Constructors
real::real() {
	value = 0;
}

real::real(const int64_t value) {
	int64_t n = value;
	this->value = n << shift;
	this->value |= (int64_t)(value<0) << 63; // Apply the original sign
}

real::real(const int32_t value) {
	int64_t n = value;
	this->value = n << shift;
	this->value |= (int64_t)(value<0) << 63; // Apply the original sign
}

real::real(const double value) {
	this->value = int64_t(value * ONE);
}

real::real(const float value) {
	this->value = int64_t(value * ONE);
}
