#ifndef __UIElement__
#define __UIElement__

#include <SDL2/SDL.h>

typedef struct _UIELEMENT
{
    int posX;
    int posY;
    SDL_Texture* image;
} UIELEMENT;

UIELEMENT create_element(int pos_x, int pos_y, SDL_Texture* image);

void draw_element(SDL_Renderer* renderer, UIELEMENT *u, int imageW, int imageH);

#endif