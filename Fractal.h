#pragma once
#include "Pixel.h"


class Fractal
{
protected:
    unsigned int cols;
    Pixel** grid;
    unsigned int maxlter;
    unsigned int rows;
    char type;

    //extra credit
    double CR;
    double CI;

public:
    ~Fractal();
    unsigned int determinePixelColor(Complex, Complex);
    Fractal();
    Fractal(const Fractal&);
    Fractal(Fractal&&);
    Fractal(unsigned int, unsigned int, char);
    Fractal(unsigned int, unsigned int, char, double, double);
    void makeJuliaFractal();
    void makeMandelbrotFractal();
    const Fractal& operator=(const Fractal&);
    Fractal& operator=(Fractal&&);

    friend Pixel convertToPixel(int color_);

    friend void saveToPPM(const Fractal& f, const char* fn);

};
Fractal testMoveConstructor(unsigned int rows, unsigned int cols, char c);

