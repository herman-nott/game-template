#ifndef __Settings__
#define __Settings__

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./game.h"


void settings(void);

void settings_properties(SDL_Renderer* renderer, SDL_Event event, enum GameStates *interface, int *mouse_x, int *mouse_y, UIELEMENT *home_element, UIELEMENT *home_hover_element);

void draw_settings_interface(SDL_Renderer* renderer);

#endif