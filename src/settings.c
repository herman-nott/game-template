#include "./settings.h"

void settings(void)
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

void settings_properties(SDL_Renderer* renderer, SDL_Event event, enum GameStates *interface, int *mouse_x, int *mouse_y, UIELEMENT *home_element, UIELEMENT *home_hover_element)
{
    if (*mouse_x > 40 && *mouse_x < 76) 
    {
        if (*mouse_y > 420 && *mouse_y < 456)
        {
            set_cursor(SDL_SYSTEM_CURSOR_HAND);

            home_hover_element->posX = home_element->posX;
            home_hover_element->posY = home_element->posY;
            home_hover_element->image = load_texture(renderer, homeHoverBTN);

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) 
            {
                *interface = MENU;
            }
        }
        else
        {
            set_cursor(SDL_SYSTEM_CURSOR_ARROW);
            home_hover_element->image = NULL;
        } 
    }
    else
    {
        set_cursor(SDL_SYSTEM_CURSOR_ARROW);
        home_hover_element->image = NULL;
    }
}

void draw_settings_interface(SDL_Renderer* renderer)
{
    draw_element(renderer, &home_element, 36, 36);
    draw_element(renderer, &home_hover_element, 36, 36);
}
