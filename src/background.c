#include "./background.h"

void make_background(SDL_Renderer *renderer, BACKGROUND *background, enum GameStates interface)
{
    switch (interface)
    {
    case MENU:
        // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        // SDL_RenderClear(renderer);
        background->texture = load_texture(renderer, menuBG);
        SDL_RenderCopy(renderer, background->texture, 0, 0);
        
        break;

    case PLAY:
        // SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        // SDL_RenderClear(renderer);
        background->texture = load_texture(renderer, playBG);
        SDL_RenderCopy(renderer, background->texture, 0, 0);
        
        break;

    case SETTINGS:
        // SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        // SDL_RenderClear(renderer);
        background->texture = load_texture(renderer, settingsBG);
        SDL_RenderCopy(renderer, background->texture, 0, 0);

        break;
    }
}