#include <stdlib.h>
#include "./resources.h"

// фон меню
char* menuBG = "./img/menuBG.png";
SDL_Texture* mBG;

char* playBG = "./img/playBG.png";
SDL_Texture* pBG;

char* settingsBG = "./img/settingsBG.png";
SDL_Texture* sBG;

char* arrowBG = "./img/menuButtonHover.png"; 
SDL_Texture* arrow;

char* homeBTN = "./img/home.png"; 
SDL_Texture* home;

char* homeHoverBTN = "./img/homeHover.png"; 
SDL_Texture* homeHover;

char* returnBTN = "./img/return.png"; 
SDL_Texture* returnBTN_t;

char* returnHoverBTN = "./img/returnHover.png"; 
SDL_Texture* returnHover;

SDL_Texture* load(SDL_Renderer *renderer, char *path)
{
    SDL_Surface* surface = IMG_Load(path);
    if (!surface) {
        exit(EXIT_FAILURE);
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    return texture;
}

void resource_init(SDL_Renderer *renderer)
{
    mBG = load(renderer, menuBG);
    pBG = load(renderer, playBG);
    sBG = load(renderer, settingsBG);

    arrow = load(renderer, arrowBG);

    home = load(renderer, homeBTN);
    homeHover = load(renderer, homeHoverBTN);
    returnBTN_t = load(renderer, returnBTN);
    returnHover = load(renderer, returnHoverBTN);
}

SDL_Texture* request_texture(char* path) 
{
    if (strcmp(path, menuBG) == 0)
    {
        return mBG;
    }
    if (strcmp(path, playBG) == 0)
    {
        return pBG;
    }
    if (strcmp(path, settingsBG) == 0)
    {
        return sBG;
    }
    if (strcmp(path, arrowBG) == 0)
    {
        return arrow;
    }
    if (strcmp(path, homeBTN) == 0)
    {
        return home;
    }
    if (strcmp(path, homeHoverBTN) == 0)
    {
        return homeHover;
    }
    if (strcmp(path, returnBTN) == 0)
    {
        return returnBTN_t;
    }
    if (strcmp(path, returnHoverBTN) == 0)
    {
        return returnHover;
    }
    
    return NULL; 
}

SDL_Texture* load_texture(SDL_Renderer *renderer, char* path)
{
    if (request_texture(path) == NULL) 
    {
        SDL_Texture* loaded_texture = load(renderer, path);
        if (loaded_texture == NULL)
        {
            exit(EXIT_FAILURE);
        }
        return loaded_texture;
    }
    else 
    {
        return request_texture(path);
    }
}