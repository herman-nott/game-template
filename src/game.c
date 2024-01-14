#include "./game.h"

#pragma region GLOBAL VARIABLES

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    bool game_is_running = false;

    // состояние игры
    enum GameStates interface;

    // задний фон
    BACKGROUND bg;

    // ховер для кнопок главного меню
    UIELEMENT menu_hover_element;

    // кнопка домой
    UIELEMENT return_element;

    // кнопка домой (ховер)
    UIELEMENT return_hover_element;

    // кнопка домой
    UIELEMENT home_element;

    // кнопка домой (ховер)
    UIELEMENT home_hover_element;

#pragma endregion

bool prepare_game(void) 
{
    interface = MENU;

    bg.texture = load_texture(renderer, menuBG);

    menu_hover_element = create_element(0, 0, NULL);

    return_element = create_element(40, 420, load_texture(renderer, returnBTN));

    return_hover_element = create_element(0, 0, NULL);

    home_element = create_element(40, 420, load_texture(renderer, homeBTN));

    home_hover_element = create_element(0, 0, NULL);


    return true;
}

bool init_window(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        return false;
    }

    int flags = 0;
    if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (!window)
    {
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        return false;
    }

    resource_init(renderer);
    if (prepare_game() == false)
    {
        return false;
    }

    return true;
}

void destroy_window(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void render(void)
{
    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255);
    SDL_RenderClear(renderer);
    
    make_background(renderer, &bg, interface);
    
    if (interface == MENU)
    {
        draw_element(renderer, &menu_hover_element, 250, 80);
    }
    else if (interface == PLAY)
    {
        draw_element(renderer, &return_element, 36, 36);
        draw_element(renderer, &return_hover_element, 36, 36);
    }
    else if (interface == SETTINGS)
    {
        draw_element(renderer, &home_element, 36, 36);
        draw_element(renderer, &home_hover_element, 36, 36);
    }
    

    SDL_RenderPresent(renderer);
}

void set_cursor(SDL_SystemCursor cursorType)
{
    SDL_Cursor* cursor = SDL_CreateSystemCursor(cursorType);
    SDL_SetCursor(cursor);
}

void buttons(SDL_Event event)
{
    int mouse_x;
    int mouse_y;

    // -----------------------------

    menu_hover_element.image = NULL;
    return_hover_element.image = NULL;
    home_hover_element.image = NULL;

    switch (event.type)
    {
    case SDL_KEYDOWN:
        switch (event.key.keysym.scancode)
        {
        case SDL_SCANCODE_1:
            interface = MENU;
            break; 
        case SDL_SCANCODE_2:
            interface = PLAY;
            break; 
        case SDL_SCANCODE_3:
            interface = SETTINGS;
            break; 
        }
        break;
    }

    SDL_GetMouseState(&mouse_x, &mouse_y);
    
    if (interface == MENU)
    {
        menu_properties(renderer, event, &interface, &mouse_x, &mouse_y, &menu_hover_element);
    }
    else if (interface == PLAY)
    {
        play_properties(renderer, event, &interface, &mouse_x, &mouse_y, &return_element, &return_hover_element);
    }
    else if (interface == SETTINGS)
    {
        settings_properties(renderer, event, &interface, &mouse_x, &mouse_y, &home_element, &home_hover_element);
    }

    make_background(renderer, &bg, interface);

}


void game(void)
{
    switch (interface)
    {
    case MENU:
        main_menu();
        break;
    case PLAY:
        play();
        break;
    case SETTINGS:
        settings();
        break;
    }
    render();
}