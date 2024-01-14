#ifndef __Game__
#define __Game__

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./constants.h"
#include "./resources.h"
#include "./game_states.h"
#include "./background.h"
#include "./main_menu.h"
#include "./play.h"
#include "./settings.h"
#include "./uielement.h"

// Window Initialization Function
// Функция Инициализации Окна
bool init_window(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

// Window Destroy Function
// Функция уничтожения окна
void destroy_window(void);

// Render Function
// Функция Рендеринга
void render(void);

// Game Function
// Функция Игры
void game(void);

// On-screen Button Processing Function
// Функция Обработки Экранных Кнопок
void buttons(SDL_Event event);

// Function Sets The Cursor
// Функция Устанавливает Курсор
void set_cursor(SDL_SystemCursor cursorType);

// Initializes variables necessary for the program to operate and creates UI elements
// Инициализирует переменные, необходимые для работы программы, и создает UI элементы
bool prepare_game(void);

// game_is_running Variable
// Переменная game_is_running
extern bool game_is_running;

// Background Variable
// Переменная заднего фона
extern BACKGROUND bg;

#endif