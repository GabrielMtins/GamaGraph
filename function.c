#include "function.h"

#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <bmp.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define NUM_OF_TILES 32
#define NUM_OF_TILESY 18

#define PROPORTIONX WINDOW_WIDTH/NUM_OF_TILES
#define PROPORTIONY WINDOW_HEIGHT/NUM_OF_TILESY

void generateFunctionImage(char* expression){
    BMP_Image* image = BMP_CreateImage(WINDOW_WIDTH, WINDOW_HEIGHT);
    BMP_SetImageColor(image, 255, 255, 255);
    BMP_DrawLineWithThickness(image, 2, 0, WINDOW_HEIGHT/2, WINDOW_WIDTH, WINDOW_HEIGHT/2);
    BMP_DrawLineWithThickness(image, 2, WINDOW_WIDTH/2, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT);
    BMP_SetImageColor(image, 50, 50, 50);
    for(int i = 0; i < NUM_OF_TILES; i++){
        BMP_DrawLineWithThickness(image, 1, 0, i*PROPORTIONY, WINDOW_WIDTH, i*PROPORTIONY);
        BMP_DrawLineWithThickness(image, 1, i*PROPORTIONX, 0, i*PROPORTIONX, WINDOW_HEIGHT);
    }
    #define OFFSET (double)NUM_OF_TILES/WINDOW_WIDTH
    BMP_SetImageColor(image, 0, 0, 255);
    for(double i = -NUM_OF_TILES/2; i < NUM_OF_TILES/2; i+=OFFSET){
        xGlobalValue = i;
        double x1 = i;
        double y1 = interpretExpression(expression);
        double x2 = i+OFFSET;
        xGlobalValue = x2;
        double y2 = interpretExpression(expression);
        if(y1 > NUM_OF_TILESY/2 || y1 < -1*NUM_OF_TILESY/2) continue;
        x1+=NUM_OF_TILES/2; x2+=NUM_OF_TILES/2;
        y1+=NUM_OF_TILESY/2; y2+=NUM_OF_TILESY/2;
        x1*=PROPORTIONX; x2*=PROPORTIONX;
        y1*=PROPORTIONY; y2*=PROPORTIONY;
        BMP_DrawLineWithThickness(image, 3, x1, y1, x2, y2);
    }
    BMP_SaveImage(image, "function.bmp");
    BMP_DestroyImage(image);
}
