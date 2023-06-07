#pragma once

#include <cstdint>

class real {
private:
	int64_t value;
	static const int64_t shift = 32; // The number of bits of the fractional part
	static const int64_t ONE = int64_t(1) << shift; // 1.0 represented by this class

public:
	// Arithmetic operators
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

	// Assignment operators
	inline real& operator=(const real& other) {
		value = other.value;
		return *this;
	}

	inline real& operator=(const int& other) {
		*this = real(other);
		return *this;
	}

	inline real& operator=(const int64_t& other) {
		*this = real(other);
		return *this;
	}

	inline real& operator=(const float& other) {
		*this = real(other);
		return *this;
	}

	inline real& operator=(const double& other) {
		*this = real(other);
		return *this;
	}

	// Comparison operators
	inline bool operator==(const real& other) {
		return value == other.value;
	}

	// Type conversions
	inline operator long() const {
		int64_t n = value;
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

	inline real(const int64_t value) {
		int64_t n = value;
		this->value = n << shift;
		this->value |= (int64_t)(value<0) << 63; // Apply the original sign
	}

	inline real(const int32_t value) {
		int64_t n = value;
		this->value = n << shift;
		this->value |= (int64_t)(value<0) << 63; // Apply the original sign
	}

	inline real(const double value) {
		this->value = int64_t(value * ONE);
	}

	inline real(const float value) {
		this->value = int64_t(value * ONE);
	}

	virtual ~real(){}
};
