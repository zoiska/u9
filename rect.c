#include <stdio.h>
#include "rect.h"

double umfangRechteck(double a, double b){
    double u = 2 * a + 2 * b;
    printf("Umfang: %.2fcm\n", u);
    return(u);
}

double flaecheRechteck(double a, double b){
    double f = a * b;
    printf("Fläche: %.2fm²\n", f);
    return(f);
}

void istQuadrat(double a, double b){
    if(a == b){
        printf("Die Kantenlängen ergeben ein Quadrat.\n");
    }
    else{
        printf("Die Kantenlängen ergeben ein Rechteck.\n");
    }
}

double berechneFlaeche3D(double a, double b, double c){
    double f = a * b * c;
    printf("Fläche: %.2lfcm³", f);
    return(f);
}