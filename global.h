#ifndef GLOBAL_H
#define GLOBAL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

SDL_Window* window;
SDL_Renderer* render;

int MWINDOW_WIDTH, MWINDOW_HEIGHT;

double deltaTime;

SDL_Texture* functionTexture;

int isMousePressed;

int oldMousePosX, oldMousePosY;

#define loadTexture(string) SDL_CreateTextureFromSurface(render, SDL_LoadBMP(string))

TTF_Font* gFont;

char mainExpression[256];

#endif
