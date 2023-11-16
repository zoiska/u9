#include <stdio.h>

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

int main() {
    aufg1();
    return 0;
}
