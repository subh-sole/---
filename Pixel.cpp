#include "Pixel.h"
#include <cstdlib>
#include <ostream>
#include <iostream>
#include <string>


Pixel::~Pixel()
{
	//cout << "> Pixel destructor called..." << endl;
	blue = NULL;
	green = NULL;
	red = NULL;


}

const unsigned int Pixel::operator[](const char* color)
{
	
	const char* b_ = "blue";

	
	const char* g_ = "green";

	
	const char* r_ = "red";

	if (strcmp(color, b_) == 0)
	{
		return blue;
	}

	if (strcmp(color, g_) == 0)
	{
		return green;
	}

	if (strcmp(color, r_) == 0)
	{
		return red;
	}

	else
	{
		std::cout << "> " << color << "is invalid" << std::endl;
		std::cout << "> Closing application..." << std::endl;
		exit(1);
	}
}

Pixel::Pixel() : red(0), green(0), blue(0)
{

}



Pixel::Pixel(const Pixel& C)
{
	std::cout << "> Pixel copy constructor called..." << std::endl;


	blue = C.blue;
	green = C.green;
	red = C.red;

}

Pixel::Pixel(unsigned int NewRed, unsigned int NewGreen, unsigned int NewBlue)
{
	//cout << "> Pixel 3-arg constructor called..." << endl;

	red = NewRed;
	green = NewGreen;
	blue = NewBlue;


}



std::ostream& operator<<(std::ostream& os, Pixel& p)
{
	os << p["red"] << " " << p["green"] << " " << p["blue"] << " ";

	return os;
}


 