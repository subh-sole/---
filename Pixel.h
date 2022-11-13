#pragma once
#pragma once
#include <ostream>
#include <iomanip>


class Pixel {
protected:
	unsigned int blue;
	unsigned int green;
	unsigned int red;
public:
	~Pixel();
	const unsigned int operator[](const char* P);
	Pixel();
	Pixel(const Pixel&);

	Pixel(unsigned int, unsigned int, unsigned int);

	
	friend Pixel convertToPixel(int color);
	
	friend std::ostream& operator<<(std::ostream& os, Pixel& p);
	
};