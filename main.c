#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MagickWand/MagickWand.h>

#include "rect.h"
#include "circle.h"

void aufg1(){
    double a, b, c, r;
    scanf("%lf %lf %lf %lf", &a, &b, &c ,&r);
    umfangRechteck(a, b);
    flaecheRechteck(a, b);
    istQuadrat(a, b);
    umfangKreis(r);
    flaecheKreis(r);
    berechneFlaeche3D(a, b, c);
}

double mandelbrot(double x, double y, double iter){
    double x1, x2, y1, y2;
    x1 = x;
    y1 = y;
    for(int i = 0; i < iter; i++){
        x2 = pow(x1, 2) - pow(y1, 2) + x;
        y2 = 2 * x1 * y1 + y;
        if(pow(x2, 2) + pow(y1, 2) > 4){
            return 1 - i / iter;
        }
        x1 = x2;
        y1 = y2;
    }
    return 0;
}

int main() {
    aufg1();

    double x1, x2, y1, y2;
    x1 = -2; x2 = 1;
    y1 = -1, y2 = 1;
    int size_x = 20000;
    int size_y = size_x * (y2 - y1) / (x2 - x1);

    //Magick::Image image(Magick::Geometry(size_x, size_y), "white");
    //image.type(Magick::GryscaleType);
    MagickWandGenesis();
    MagickWand *image = NewMagickWand();
    MagickNewImage(image, size_x, size_y, NewPixelWand());

    for(int i = 0; i < size_y; i++){
        for(int j = 0; j < size_x; j++){
            double x = (x2 - x1) * i / size_x + x1;
            double y = (y2 - y1) * i / size_y + y1;
            double gray = mandelbrot(x, y, 256);

            //image.pixelColor(i, j, Magick::ColorGray(gray));
            //Quantum q = 16;
            //PixelSetRed((PixelWand *) image, MagickGetImagePixelColor(image, j, i, (PixelWand *) 5));
            //PixelSetGreen(MagickGetImagePixelColor(image, j, i, QuantumRange * gray));
            //PixelSetBlue(MagickGetImagePixelColor(image, j, i, QuantumRange * gray));

        }
    }

    //image.write(m20k.png)
    MagickWriteImage(image, "m20k.png");
    DestroyMagickWand(image);
    MagickWandTerminus();

    return 0;
}


/*
 *
find_package(ImageMagick 6.7 COMPONENTS Magick++ MagickCore)
if(ImageMagick_FOUND)
    # Find Imagemagick Library directory
    get_filename_component(MAGICK_LIB_DIR ${ImageMagick_MagickCore_LIBRARY} DIRECTORY)
    # Find where Magick++-config lives
    file(GLOB_RECURSE MAGICK_CONFIG FOLLOW_SYMLINKS ${MAGICK_LIB_DIR}/Magick++-config)
    # Ask about CXX and lib flags/locations
    set(MAGICK_CONFIG ${MAGICK_CONFIG} CACHE string "Path to Magick++-config utility")
    execute_process(COMMAND "${MAGICK_CONFIG}" "--cxxflags" OUTPUT_VARIABLE MAGICK_CXX_FLAGS)
    execute_process(COMMAND "${MAGICK_CONFIG}" "--libs" OUTPUT_VARIABLE MAGICK_LD_FLAGS)
    # Add these to cache
    set(MAGICK_CXX_FLAGS "${MAGICK_CXX_FLAGS}" CACHE string "ImageMagick configuration specific compilation flags." )
    set(MAGICK_LD_FLAGS  "${MAGICK_LD_FLAGS}" CACHE string "ImageMagick configuration specific linking flags.")
    # Split into list:
    string(REGEX MATCHALL "([^\ ]+)" MAGICK_CXX_FLAGS "${MAGICK_CXX_FLAGS}")
    string(REGEX MATCHALL "([^\ ]+)" MAGICK_LD_FLAGS "${MAGICK_LD_FLAGS}")
    # Remove trailing whitespace (CMAKE warns about this)
    string(STRIP "${MAGICK_CXX_FLAGS}" MAGICK_CXX_FLAGS)
    string(STRIP "${MAGICK_LD_FLAGS}" MAGICK_LD_FLAGS)

    target_compile_options(<project> ${MAGICK_CXX_FLAGS})
    target_link_libraries(<project> ${MAGICK_LD_FLAGS})

endif(ImageMagick_FOUND)
 *
 * */