#ifndef BMP_H
#define BMP_H

typedef struct{
    int r, g, b;
} BMP_Color;

typedef struct{
    BMP_Color* buffer;
    int w, h;
    BMP_Color currentColor;
} BMP_Image;

BMP_Image* BMP_CreateImage(int w, int h);

void BMP_GenerateAA(BMP_Image* image);

void BMP_SetImageColor(BMP_Image* image, int r, int g, int b);

void BMP_DrawPixel(BMP_Image* image, int x, int y);

void BMP_DrawLine(BMP_Image* image, int x1, int y1, int x2, int y2);

void BMP_DrawRect(BMP_Image* image, int x, int y, int w, int h);

void BMP_DrawLineWithThickness(BMP_Image* image, int thickness, int x1, int y1, int x2, int y2);

void BMP_SaveImage(BMP_Image* i, char* image);

void BMP_DestroyImage(BMP_Image* image);

#endif
