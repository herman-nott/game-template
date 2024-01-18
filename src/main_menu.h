#ifndef __MainMenu__
#define __MainMenu__

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./uielement.h"
#include "./game_states.h"
#include "./game.h"


void main_menu(void);

void menu_properties(SDL_Renderer* renderer, SDL_Event event, enum GameStates *interface, int *mouse_x, int *mouse_y, UIELEMENT *mouse_hover_element);

void draw_menu_interface(SDL_Renderer* renderer);

#endif