This will generate fractal pattern generation code using the Mandelbrot and Julia sets.

Images containing the created patterns will be written to disk in the Portable Pix Map (PPM) image format.

C++ solution for this project will generate Mandelbrot and Julia fractal patterns. Images containing the created patterns will be written to disk in the Portable Pix Map (PPM) image format. Mandelbrot fractals are generated using an iterative complex function of the following form: 𝒁𝒏+𝟏 = 𝒁𝒏 𝟐 + 𝑪 𝒁𝟎 = 𝟎,

where Z and C are complex numbers. These complex numbers can be thought of as points on a two-dimensional complex plane of size 2.0×2.0. The real and imaginary parts of these complex numbers represent the x and y coordinates of points on the complex plane, respectively.

When our intended output image is projected onto the 2.0×2.0complex plane, complex number C represents an individual Pixel on the image. As a result, for each individual Pixel on the image, we can calculate successive values for Z based on the above equations. We can also keep track of the length of Z as it gets updated in each iteration and stop the iterative process when the square of the length of Z exceeds 4. The number of iterations required to breach this condition will then determine the color value associated with the Pixel represented by the complex number C.

The purpose of this algorithm is to generate a distinct value in form of an unsigned int that represents the color of an individual Pixel on our Fractal image, then convert the color value to a red-green-blue color combination. Once the red-green-blue color combination for the Pixel is determined, it may be assigned to the Pixel represented by complex number C. The entire image is represented by a two-dimensional array of Pixel objects named grid.
