#include <stdio.h>
#include <Magick.h>

#include "rect.h"
#include "circle.h"
#include "Mandelbrot.h"

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

int main() {
    aufg1();
    double x1, x2, y1, y2;
    x1 = -2; x2 = 1;
    y1 = -1, y2 = 1;
    int size_x = 20000;
    int size_y = size_x * (y2 - y1) / (x2 - x1);
    Magick::Image
    return 0;
}
