#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Mag>

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
            Quantum q = 5;
            PixelSetRed((PixelWand *) image, MagickGetImagePixelColor(image, j, i, (PixelWand *) 5));
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
