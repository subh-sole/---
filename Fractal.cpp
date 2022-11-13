#include <fstream>

#include <string.>
#include <iostream>
#include <algorithm>

#include "Complex.h"
#include "Fractal.h"
//#include "Pixel.cpp"
#include "Pixel.h"

#define _CRT_SECURE_NO_WARNINGS

Pixel convertToPixel(int color)
{
    Pixel T;

    T.red = (color / 64) % 8;
    T.green = (color / 8) % 8;
    T.blue = color % 8;

    return Pixel(T.red, T.green, T.blue);
}

void Fractal::makeMandelbrotFractal()
{
    std::cout << "> Now creating the Mandelbrot patterns..." << std::endl;

    Complex Z, C;
    double step_height = 4.0 / (double)rows;
    double step_width = 4.0 / (double)cols;
    for (unsigned int j = 0; j < rows; j++)
    {
        for (unsigned int k = 0; k < cols; k++)
        {
            Z["Imaginary"] = 0.0; //Imaginary part of Z = 0.0
            Z["Real"] = 0.0; //Real part of Z = 0.0
            C["Real"] = ((double)j * step_height) - 2.0; //Real part of C = ((double)j * step_height) - 2.0
            C["Imaginary"] = ((double)k * step_width) - 2.0; //Imaginary part of C = ((double)k * step_width) - 2.0
            int Color;
            Color = determinePixelColor(Z, C);
            
            grid[j][k] = convertToPixel(Color);

        }
    }
}


const Fractal& Fractal::operator=(const Fractal& F)
{


    std::cout << "> Assignment operator called." << std::endl;



    if (this != &F)

    {

        if (grid != nullptr)
        {

            cols = F.cols;
            maxlter = F.maxlter;
            rows = F.rows;
            type = F.type;

            for (unsigned int r = 0; r < F.rows; r++)
            {
                for (unsigned int c = 0; c < F.cols; c++)
                {
                    grid[r][c] = F.grid[r][c];
                }
            }

        }
    }






    return *this;

}

Fractal& Fractal::operator=(Fractal&& p) 
{
    std::cout << "> Move assignment operator called..." << std::endl;

    if (this != &p)
    {
        std::swap(grid, p.grid);

        std::swap(rows, p.rows);

        std::swap(cols, p.cols);

        std::swap(maxlter, p.maxlter);

        std::swap(type, p.type);
    }

    p.cols = NULL;
    p.grid = nullptr;
    p.rows = NULL;
    p.maxlter = NULL;
    p.type = NULL;


    return *this;
}


Fractal::~Fractal()
{
    std::cout << "> Destructor Called ..." << std::endl;

    delete[] grid;
    grid = nullptr;

    cols = NULL;
    maxlter = NULL;
    rows = NULL;
    type = NULL;


}

unsigned int Fractal::determinePixelColor(Complex Z, Complex C)
{
    double lengthSquared;
    unsigned int iter = 0;

    maxlter = 512;


    while (iter < maxlter)
    {
        iter = iter + 1;


        Z = Z * Z;
        Z = Z + C;
        lengthSquared = getMagnitudeSquared(Z);
       
        if (lengthSquared > 4.0)
            return iter;
    }
    return maxlter;
}

Fractal::Fractal() : rows(0), cols(0), type(0), maxlter(0), grid(nullptr)
{
    std::cout << "> Default Constructor Called..." << std::endl;
}

Fractal::Fractal(const Fractal& F)
{
    std::cout << "> Copy Constructor Called..." << std::endl;


    cols = F.cols;
    maxlter = F.maxlter;
    rows = F.rows;
    type = F.type;

    grid = new Pixel * [rows];

    for (unsigned int i = 0; i < rows; i++)
    {

        grid[i] = new Pixel[cols];

    }

    if (type == 'm')
    {
        makeMandelbrotFractal();
    }
    if (type == 'j')
    {
        makeJuliaFractal();
    }
}

Fractal::Fractal(Fractal&& F) //: rows(F.rows), cols(F.cols), type(F.type), maxlter(512), grid(F.grid)
{
    std::cout << "> Move constructor called." << std::endl;

    if (this != &F)
    {
        std::swap(grid, F.grid);

        std::swap(rows, F.rows);

        std::swap(cols, F.cols);

        std::swap(maxlter, F.maxlter);

        std::swap(type, F.type);
    }


    F.cols = NULL;
    F.grid = nullptr;
    F.rows = NULL;
    F.maxlter = NULL;
    F.type = NULL;


}

Fractal::Fractal(unsigned int rows_, unsigned int cols_, char c_) : rows(rows_), cols(cols_), type(c_), maxlter(512), grid(nullptr)
{
    std::cout << "> 3-arg constructor called..." << std::endl;

    grid = new Pixel * [rows_];

    for (unsigned int i = 0; i < rows_; i++)

    {

        grid[i] = new Pixel[cols_];

    }

    if (type == 'm')
    {
        makeMandelbrotFractal();
    }
    if (type == 'j')
    {
        makeJuliaFractal();
    }

}


//extra credit
Fractal::Fractal(unsigned int rows_, unsigned int cols_, char c_, double CReal, double CImaginary) : rows(rows_), cols(cols_), type(c_), maxlter(512), grid(nullptr)
{
    std::cout << "> 3-arg constructor called...(Extra Credit)" << std::endl;

    CR = CReal;
    CI = CImaginary;


    grid = new Pixel * [rows_];

    for (unsigned int i = 0; i < rows_; i++)

    {

        grid[i] = new Pixel[cols_];

    }

    if (type == 'm')
    {
        makeMandelbrotFractal();
    }
    if (type == 'j')
    {
        makeJuliaFractal();
    }

}

void Fractal::makeJuliaFractal()
{
    std::cout << "> Now creating the Julia patterns..." << std::endl;

    Complex Z, C;
    double step_height = 4.0 / (double)rows;
    double step_width = 4.0 / (double)cols;
    for (unsigned int j = 0; j < rows; j++)
    {
        for (unsigned int k = 0; k < cols; k++)
        {
            Z["Imaginary"] = ((double)j * step_height) - 2.0;//Imaginary part of Z = 0.0
            Z["Real"] = ((double)k * step_width) - 2.0; //Real part of Z = 0.0

            //extra credit
            if (CR == NULL & CI == NULL) {
                CR = -0.8;
                CI = 0.156;
            }

            C["Real"] = CR; //Real part of C = ((double)j * step_height) - 2.0
            C["Imaginary"] = CI; //Imaginary part of C = ((double)k * step_width) - 2.0
            int Color;
            Color = determinePixelColor(Z, C);
           
            grid[j][k] = convertToPixel(Color);

        }
    }
}

void saveToPPM(const Fractal& f, const char* fn)
{
    std::cout << "> Saving Fractal object to ASCII file..." << std::endl;
    std::ofstream outfile(fn);

    if (f.grid != nullptr)
    {
        std::string magic = "P3";
        std::string comment = "# Created by GIMP version 2.10.28 PNM plug-in";


        outfile << magic << std::endl;
        outfile << comment << std::endl;
        outfile << f.cols << " " << f.rows << std::endl;
        outfile << "7" << std::endl;

        Pixel P;


        for (unsigned int r = 0; r < f.rows; r++)
        {
            for (unsigned int c = 0; c < f.cols; c++)
            {
                P = f.grid[r][c];

                outfile << P;
            }
            outfile << std::endl;
        }

        outfile.close();

    }

    else
    {
        std::cout << "> Error: Fractal object is uninitialized." << std::endl;
    }
}

Fractal testMoveConstructor(unsigned int rows, unsigned int cols, char c)
{
    Fractal F(rows, cols, c);
    return F;
}
