#include "core.h"

#include "global.h"
#include "hud.h"
#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    TTF_Init();
    SDL_DisplayMode dm;
    if(SDL_GetCurrentDisplayMode(0, &dm)<0){
        return;
    }
    MWINDOW_WIDTH = dm.w;
    MWINDOW_HEIGHT = dm.h;
    gFont = TTF_OpenFont("font.ttf", MWINDOW_HEIGHT/36);
    SDL_StartTextInput();
    window = SDL_CreateWindow("GamaGraph", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MWINDOW_WIDTH, MWINDOW_HEIGHT, SDL_WINDOW_FULLSCREEN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    functionTexture = loadTexture("function.bmp");
}

void input(SDL_Event* e){
    if(e->type == SDL_KEYDOWN){
        if(e->key.keysym.sym == SDLK_BACKSPACE && strlen(mainExpression) > 0){
            mainExpression[strlen(mainExpression)-1] = '\0';
        }
        if(e->key.keysym.sym == SDLK_RETURN){
            generateFunctionImage(mainExpression);
            SDL_DestroyTexture(functionTexture);
            functionTexture = NULL;
            SDL_Surface* loadSurface = SDL_LoadBMP("function.bmp");
            functionTexture = SDL_CreateTextureFromSurface(render, loadSurface);
            SDL_FreeSurface(loadSurface);
        }
    }
    if(e->type == SDL_TEXTINPUT){
        strncat(mainExpression, e->text.text, 1);
    }
}

void renderScene(){
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
    drawHud();
    SDL_RenderPresent(render);
}

void gameLoop(){
    int quit = 0;
    SDL_Event e;
    while(!quit){
        Uint32 firstTime = SDL_GetTicks();
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT) quit = 1;
            else input(&e);
        }
        renderScene();
        deltaTime = (double)(SDL_GetTicks()-firstTime)/1000;
    }
}

void game(){
    init();
    gameLoop();
}
