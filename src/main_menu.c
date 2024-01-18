#include "./main_menu.h"

void main_menu(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        buttons(event);
        switch (event.type)
        {
        case SDL_QUIT:
            game_is_running = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_ESCAPE:
                game_is_running = false;
                break; 
            }
            break;
        }
    }
}

void menu_properties(SDL_Renderer* renderer, SDL_Event event, enum GameStates *interface, int *mouse_x, int *mouse_y, UIELEMENT *mouse_hover_element)
{
    if (*mouse_x > 90 && *mouse_x < 340) 
    {
        if (*mouse_y > 150 && *mouse_y < 230) 
        {
            set_cursor(SDL_SYSTEM_CURSOR_HAND);

            mouse_hover_element->posX = 90;
            mouse_hover_element->posY = 150;
            mouse_hover_element->image = load_texture(renderer, arrowBG);

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) 
            {
                *interface = PLAY;
            }
        }
        else if (*mouse_y > 280 && *mouse_y < 360) 
        {
            set_cursor(SDL_SYSTEM_CURSOR_HAND);

            mouse_hover_element->posX = 90;
            mouse_hover_element->posY = 280;
            mouse_hover_element->image = load_texture(renderer, arrowBG);

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) 
            {
                *interface = SETTINGS;
            }
        }
        else
        {
            set_cursor(SDL_SYSTEM_CURSOR_ARROW);
            mouse_hover_element->image = NULL;
        } 
    }
    else
    {
        set_cursor(SDL_SYSTEM_CURSOR_ARROW);
        mouse_hover_element->image = NULL;
    }
}

void draw_menu_interface(SDL_Renderer* renderer)
{
    draw_element(renderer, &menu_hover_element, 250, 80);
}