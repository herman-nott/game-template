#include "./play.h"

void play(void)
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

void play_properties(SDL_Renderer* renderer, SDL_Event event, enum GameStates *interface, int *mouse_x, int *mouse_y, UIELEMENT *return_element, UIELEMENT *return_hover_element)
{
    if (*mouse_x > 40 && *mouse_x < 76) 
    {
        if (*mouse_y > 420 && *mouse_y < 456)
        {
            set_cursor(SDL_SYSTEM_CURSOR_HAND);

            return_hover_element->posX = return_element->posX;
            return_hover_element->posY = return_element->posY;
            return_hover_element->image = load_texture(renderer, returnHoverBTN);

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) 
            {
                *interface = MENU;
            }
        }
        else
        {
            set_cursor(SDL_SYSTEM_CURSOR_ARROW);
            return_hover_element->image = NULL;
        } 
    }
    else
    {
        set_cursor(SDL_SYSTEM_CURSOR_ARROW);
        return_hover_element->image = NULL;
    }
}

