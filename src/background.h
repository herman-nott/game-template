#ifndef __Background__
#define __Background__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./game_states.h"
#include "./resources.h"

typedef struct _BACKGROUND
{
    SDL_Texture* texture;
} BACKGROUND;

void make_background(SDL_Renderer *renderer, BACKGROUND *background, enum GameStates interface);

#endif