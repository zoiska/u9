#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "rect.h"
#include "circle.h"
#include "mandelbrot.h"

void aufg1u2(){
    double a, b, c, r;
    scanf("%lf %lf %lf %lf\n", &a, &b, &c ,&r);
    umfangRechteck(a, b);
    flaecheRechteck(a, b);
    istQuadrat(a, b);
    umfangKreis(r);
    flaecheKreis(r);
    berechneFlaeche3D(a, b, c);
}

void aufg3a(double x){
    // Ganzzahl kleiner oder gleich gegebener Zahl
    int erg1 = floor(x);
    // Ganzzahl größer oder gleich gegebener Zahl
    int erg2 = ceil(x);
    // Ganzzahl gerundet um 0.5, kleiner, größer oder gleich gegebener Zahl
    int erg3 = round(x);
    printf("%d %d %d\n", erg1, erg2, erg3);
}
/*
 * INFINITY(float) - Macro constant that expands to an expression of type float. If the implementation supports infinity
 *      values, this is defined as the value that represents a positive or unsigned infinity. Otherwise, it is a
 *      positive constant that overflows at translation time.
 *
 * NAN(float) - Not-A-Number. Macro constant that expands to an expression of type float that represents a NaN if the
 *      implementation supports quiet NaNs (otherwise, it is not defined).
 *
 * HUGE_VAL(double) - Macro constant that expands to a positive expression of type double, functions may either return
 *      a positive or a negative HUGE_VAL (HUGE_VAL or -HUGE_VAL) to indicate the sign of the result.
 *
 * HUGE_VALF(float) - Macro constant that expands to a positive expression of type float., functions may either return a
 *      positive or a negative HUGE_VALF (HUGE_VALF or -HUGE_VALF) to indicate the sign of the result.
 *
 * HUGE_VALL(long double) - Macro constant that expands to a positive expression of type long double, functions may
 *      either return a positive or a negative HUGE_VALL (HUGE_VALL or -HUGE_VALL) to indicate the sign of the result.
 * */

void aufg3b(int x){
    //sqrt() - (double)
    double erg1 = sqrt(x);
    //sqrtf() - (float)
    float erg2 = sqrtf(x);
    //sqrtl() - (long double)
    long double erg3 = sqrtl(x);
    printf("%lf %f %Lf\n", erg1, erg2, erg3);
}

void aufg3c(int x){
    //sin() - (double)
    double erg1 = sin(x);
    //sinf() - (float)
    float erg2 = sinf(x);
    //sinl() - (long double)
    long double erg3 = sin(x);
    printf("%lf % f% Lf\n", erg1, erg2, erg3);

    //cos() - (double)
    double erg4 = cos(x);
    //cosf() - (float)
    float erg5 = cosf(x);
    //cos() - (long double)
    long double erg6 = cosl(x);
    printf("%lf % f% Lf\n", erg4, erg5, erg6);
}

void aufg4(char *str, char *control){
    char *hold = strpbrk(str, control);
    while(hold != NULL){
        printf("%c ", *hold);
        hold = strpbrk(hold + 1, control);
    }
}

char *childrenSong = {"Drei Chinesen mit dem Kontrabass\nsassen auf der Strasse und erzaehlten sich was.\nDa kam die "
                      "Polizei, fragt: Was ist denn das?\nDrei Chinesen mit dem Kontrabass."};

struct Book{
    char title[50];
    char author[50];
    char subject[50];
    int book_id;
};

void aufg5(){
    struct Book buch = {"Programmieren in C", "Heimo Gaicher", "Einstieg in C Programmierung",
            6495407};
    printf("Titel: %s\nAutor: %s\nThema des Buches: %s\nBuch Code: %d\n", buch.title, buch.author, buch.subject, buch.book_id);

    struct Book *buuuch = (struct Buch *)malloc(sizeof(struct Book));
    strcpy(buuuch->title, "How to follow me and why you should.");
    strcpy(buuuch->author, "Zeeskes Kalingkaling");
    strcpy(buuuch->subject, "Cultism");
    buuuch->book_id = 1111111;
    printf("Titel: %s\nAutor: %s\nThema des Buches: %s\nBuch Code: %d\n", buuuch->title, buuuch->author, buuuch->subject, buuuch->book_id);
}

int main() {
    //aufg1u2
    //aufg3a(2.5);
    //aufg3b(12);
    //aufg3c(32);
    //aufg4(childrenSong, "aeiou");
    aufg5();

    //start();  <-- UNIX System only
    return 0;
}