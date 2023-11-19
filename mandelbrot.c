#include "MagickWand/MagickWand.h"
#include "mandelbrot.h"

#define WIDTH 10000
#define HEIGHT 8000

int mandelbrot(double x, double y, int iter) {
    int z = 0;
    double x1 = x;
    double y1 = y;

    while (z < iter) {
        double x2 = x * x;
        double y2 = y * y;

        if (x2 + y2 > 4.0) {
            break;
        }

        y = 2 * x * y + y;
        x = x2 - y2 + x;

        z++;
    }

    return z;
}

void draw(MagickWand *wand) {
    int max_iter = 1000;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            double x = (j - WIDTH / 2.0) * 4.0 / WIDTH;
            double y = (i - HEIGHT / 2.0) * 4.0 / HEIGHT;

            int color = mandelbrot(x, y, 256);

            PixelWand *pixel_wand = NewPixelWand();
            PixelSetRed(pixel_wand, color % 256 / 255.0);
            PixelSetGreen(pixel_wand, color % 256 / 255.0);
            PixelSetBlue(pixel_wand, color % 256 / 255.0);

            MagickSetImagePixelColor(wand, x, y, pixel_wand);
            DestroyPixelWand(pixel_wand);
        }
    }
}

int start() {
    MagickWandGenesis();
    MagickWand *wand = NewMagickWand();
    MagickNewImage(wand, WIDTH, HEIGHT, NewPixelWand());
    draw(wand);
    MagickWriteImage(wand, "mandelbrot.png");
    DestroyMagickWand(wand);
    MagickWandTerminus();
    return 0;
}


/*
 *
 * double mandelbrot(double x, double y, double iter){
    double x1, x2, y1, y2;
    x1 = x;
    y1 = y;
    for(int i = 0; i < iter; i++){
        x2 = x1 * x1 - y1 * y1 + x;
        y2 = 2 * x1 * y1 + y;
        if(x2 * x2 + y1 * y1 < 4){
            return 1 - i / iter;
        }
        x1 = x2;
        y1 = y2;
    }
    return 0;
}

void draw(MagickWand *wand){
    double x1, x2, y1, y2;
    x1 = -2; x2 = 1;
    y1 = -1, y2 = 1;
    double size_x = 800;
    double size_y = size_x * (y2 - y1) / (x2 - x1);
    MagickNewImage(wand, size_x, size_y, NewPixelWand());
    for(int i = 0; i < size_y; i++){
        for(int j = 0; j < size_x; j++){
            double x = (x2 - x1) * i / size_x + x1;
            double y = (y2 - y1) * i / size_y + y1;
            int color = mandelbrot(x, y, 256);
            //image.pixelColor(i, j, Magick::ColorGray(gray));

            PixelWand *pixel_wand = NewPixelWand();
            PixelSetRed(pixel_wand, color % 256 / 255.0);
            PixelSetGreen(pixel_wand, color % 256 / 255.0);
            PixelSetBlue(pixel_wand, color % 256 / 255.0);

            MagickSetImagePixelColor(wand, x, y, pixel_wand);
            DestroyPixelWand(pixel_wand);
        }
    }
}
 *
 * */