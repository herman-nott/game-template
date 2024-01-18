#ifndef __Play__
#define __Play__

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./uielement.h"
#include "./player.h"
#include "./enemy.h"
#include "./game.h"


void play(void); 

void play_properties(SDL_Renderer* renderer, SDL_Event event, enum GameStates *interface, int *mouse_x, int *mouse_y, UIELEMENT *return_element, UIELEMENT *return_hover_element);

void draw_play_interface(SDL_Renderer* renderer);

void play_logic(SDL_Renderer* renderer);

void play_handle_events(SDL_Event event); 

// Reset Play State Function
// Функция Сброса Состояния Игры
void reset_play_state(void);

#endif