#ifndef __Play__
#define __Play__

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./game.h"


void play(void); 

void play_properties(SDL_Renderer* renderer, SDL_Event event, enum GameStates *interface, int *mouse_x, int *mouse_y, UIELEMENT *return_element, UIELEMENT *return_hover_element);


#endif