 #include"Complex.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

Complex::Complex() : real(0.0), imag(0.0)
{
	//cout << "> Complex default constructor called..." << endl;
}

Complex::Complex(const Complex& C)
{ 
	//cout << "> Complex copy constructor called..." << endl;
	imag = C.imag;
	real = C.real;
}

Complex::Complex(double imagNum, double realNum)
{
	//cout << "> Complex 2-arg constructor called..." << endl;
	imag = imagNum;
	real = realNum;
}

Complex::~Complex()
{
	//cout << "> Complex destructor called..." << endl;

	real = NULL;
	imag = NULL;
}

double& Complex:: operator[](const char* type)
{
	if (strcmp(type, "Real") == 0)
	{
		return real;
	}
	else if (strcmp(type, "Imaginary") == 0)
	{
		return imag;
	}
	else
	{
		std::cout << "> " << type << " is an unvalid to the context of the Complex class..." << std::endl;
		std::cout << "> Closing application..." << std::endl;
		exit(1);

	}
}

const Complex operator*(const Complex& c1, const Complex& c2)
{
	// (2+4i)*(4+3i)
	// = 8+8i+6i+(12)(-1)
	// = 8+14i-12
	// = -4+14i

	//cout << "> Friend operator* is called..." << endl;

	Complex output;

	output.real = ((c1.real) * (c2.real)) - ((c1.imag) * (c2.imag));
	output.imag = (((c1.imag) * (c2.real)) + ((c1.real) * (c2.imag)));

	return output;


}

const Complex operator+(const Complex& c1, const Complex& c2)
{
	// (2+4i)+(4+3i)
	// = 6+7i

	//cout << "> Friend operator+ is called..." << endl;

	Complex output;

	output.real = c1.real + c2.real;
	output.imag = c1.imag + c2.imag;

	return output;
}

double getMagnitudeSquared(const Complex& c)
{
	// (2+4i)
	// sqrt((2)^2 + (4)^2)
	// sqrt(4+16)
	// sqrt(20)

	//cout << "> Friend operator* is called..." << endl;

	double output;

	/*output = pow((((c.real) * (c.real)) + ((c.imag) * (c.imag))), 2);*/


	output = ((c.real) * (c.real)) + ((c.imag) * (c.imag));

	return output;

}

