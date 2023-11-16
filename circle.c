#include <stdio.h>
#include <math.h>
#include "circle.h"

double umfangKreis(double radius){
    double u = 2 * radius * M_PI;
    printf("Umfang des Kreises: %.2f\n", u);
    return(u);
}

double flaecheKreis(double r){
    double f = M_PI * r*r;
    printf("Fläche des Kreises: %.2f\n", f);
    return(f);
}