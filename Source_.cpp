// Source_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Complex.h"
#include "Fractal.h"
#include "Pixel.h"

#include <iostream>
#include <string>

#include<direct.h>


int main()
{
	Fractal m1(768U, 924U, 'm'), j1(768U, 1024U, 'j'), m2, j2;
	saveToPPM(m1, "mandelbrot.ppm");
	saveToPPM(j1, "julia.ppm");
	m2 = Fractal(m1);
	j2 = testMoveConstructor(600U, 800U, 'j');
	
	saveToPPM(j2, "julia_2.ppm");

	//extra bit

	std::system("mkdir \MyGIFFolder");
	int count = 0;
	double cReal = 1;
	double cImaginary = 0;
	
	while (count < 20)
	{
		cReal = cReal - 0.1;
		cImaginary = cImaginary + 0.033;
		
		Fractal j3(768U, 1024U, 'j', cReal, cImaginary);
		std::string filename = "\MyGIFFolder\\julia(extraCredit)";
		filename = filename + "_" + std::to_string(count) + ".ppm";
		count++;
		const char* c = filename.c_str();
		saveToPPM(j3, c);


	}

	return 0;
}