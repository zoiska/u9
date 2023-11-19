#include <stdio.h>
#include <math.h>
#include "rect.h"
#include "circle.h"
#include "mandelbrot.h"

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

void aufg2(double x){
    // Ganzzahl kleiner oder gleich gegebener Zahl
    int erg1 = floor(x);
    // Ganzzahl größer oder gleich gegebener Zahl
    int erg2 = ceil(x);
    // Ganzzahl gerundet um 0.5, kleiner, größer oder gleich gegebener Zahl
    int erg3 = round(x);
    printf("%d %d %d", erg1, erg2, erg3);
}
/*
 *
 * */

int main() {
    //aufg1
    aufg2(2.5);

    //start();  <-- UNIX System only
    return 0;
}