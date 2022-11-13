#pragma once
#include <iostream>


class Complex
{
private:
	double imag;
	double real;

public:
	Complex();
	Complex(const Complex&);
	Complex(double, double);
	~Complex();
	

	// The purpose of overloaded operator[]() in the Complex class is mutate the values of the real and imaginary parts of a Complex object.
	// For example, Z["real"] = 0.0, then should change the real part of Complex object z to 0.0.

	double& operator[](const char*);

	friend const Complex operator*(const Complex&, const Complex&);

	friend const Complex operator+(const Complex&, const Complex&);

	friend double getMagnitudeSquared(const Complex&);

};