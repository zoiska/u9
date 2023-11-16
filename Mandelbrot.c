#include "Mandelbrot.h"

#include <math.h>

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