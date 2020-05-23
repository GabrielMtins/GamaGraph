#include "hud.h"

#include "global.h"

#include <string.h>

void drawText(){
    if(strlen(mainExpression) == 0) return;
    SDL_Color bg = {0, 0, 0};
    SDL_Color fg = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Shaded(gFont, mainExpression, fg, bg);
    SDL_Rect destRect = {0, 0, surface->w, surface->h};
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_RenderCopy(render, texture, NULL, &destRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    surface = NULL;
}

void drawHud(){
    SDL_RenderCopy(render, functionTexture, NULL, NULL);
    {
        SDL_Rect box = {0, 0, MWINDOW_WIDTH, MWINDOW_HEIGHT/28};
        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        SDL_RenderFillRect(render, &box);
    }
    drawText();
}
