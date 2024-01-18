#include <stdlib.h>
#include "./resources.h"

// фон меню
char* menuBG = "./img/menuBG.png";
SDL_Texture* mBG;

char* playBG = "./img/playBG_2.png";
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

// -----------------------------------------

char* samurai_Idle_path = "./img/Samurai/Idle.png";
SDL_Texture* samurai_Idle;

char* samurai_Walk_path = "./img/Samurai/Walk.png";
SDL_Texture* samurai_Walk;

char* samurai_Run_path = "./img/Samurai/Run.png";
SDL_Texture* samurai_Run;

char* samurai_Attack_1_path = "./img/Samurai/Attack_1.png";
SDL_Texture* samurai_Attack_1;

char* samurai_Attack_2_path = "./img/Samurai/Attack_2.png";
SDL_Texture* samurai_Attack_2;

char* samurai_Attack_3_path = "./img/Samurai/Attack_3.png";
SDL_Texture* samurai_Attack_3;

char* samurai_Hurt_path = "./img/Samurai/Hurt.png";
SDL_Texture* samurai_Hurt;

char* samurai_Protection_path = "./img/Samurai/Protect.png";
SDL_Texture* samurai_Protection;

char* samurai_Dead_path = "./img/Samurai/Dead.png";
SDL_Texture* samurai_Dead;

// -----------------------------------------

char* werewolf_Idle_path = "./img/Werewolf/Idle.png";
SDL_Texture* werewolf_Idle;

char* werewolf_Walk_path = "./img/Werewolf/Walk.png";
SDL_Texture* werewolf_Walk;

char* werewolf_Run_path = "./img/Werewolf/Run.png";
SDL_Texture* werewolf_Run;

char* werewolf_Attack_1_path = "./img/Werewolf/Attack_1.png";
SDL_Texture* werewolf_Attack_1;

char* werewolf_Attack_2_path = "./img/Werewolf/Attack_2.png";
SDL_Texture* werewolf_Attack_2;

char* werewolf_Attack_3_path = "./img/Werewolf/Attack_3.png";
SDL_Texture* werewolf_Attack_3;

char* werewolf_Hurt_path = "./img/Werewolf/Hurt.png";
SDL_Texture* werewolf_Hurt;

char* werewolf_Dead_path = "./img/Werewolf/Dead.png";
SDL_Texture* werewolf_Dead;

char* werewolf_Dead_Pic_path = "./img/Werewolf/Dead_Pic.png";
SDL_Texture* werewolf_Dead_Pic;


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

    // ----------------------------------------

    samurai_Idle = load(renderer, samurai_Idle_path);
    samurai_Walk = load(renderer, samurai_Walk_path);
    samurai_Run = load(renderer, samurai_Run_path);
    samurai_Attack_1 = load(renderer, samurai_Attack_1_path);
    samurai_Attack_2 = load(renderer, samurai_Attack_2_path);
    samurai_Attack_3 = load(renderer, samurai_Attack_3_path);
    samurai_Hurt = load(renderer, samurai_Hurt_path);
    samurai_Protection = load(renderer, samurai_Protection_path);
    samurai_Dead = load(renderer, samurai_Dead_path);


    werewolf_Idle = load(renderer, werewolf_Idle_path);
    werewolf_Walk = load(renderer, werewolf_Walk_path);
    werewolf_Run = load(renderer, werewolf_Run_path);
    werewolf_Attack_1 = load(renderer, werewolf_Attack_1_path);
    werewolf_Attack_2 = load(renderer, werewolf_Attack_2_path);
    werewolf_Attack_3 = load(renderer, werewolf_Attack_3_path);
    werewolf_Hurt = load(renderer, werewolf_Hurt_path);
    werewolf_Dead = load(renderer, werewolf_Dead_path);
    werewolf_Dead_Pic = load(renderer, werewolf_Dead_Pic_path);
}

SDL_Texture* request_texture(char* path) 
{
    if (strcmp(path, menuBG) == 0) return mBG;

    if (strcmp(path, playBG) == 0) return pBG;

    if (strcmp(path, settingsBG) == 0) return sBG;
    
    if (strcmp(path, arrowBG) == 0) return arrow;
    
    if (strcmp(path, homeBTN) == 0) return home;
    
    if (strcmp(path, homeHoverBTN) == 0) return homeHover;
    
    if (strcmp(path, returnBTN) == 0)  return returnBTN_t;
    
    if (strcmp(path, returnHoverBTN) == 0) return returnHover;

    // --------------------------------------------------

    if (strcmp(path, samurai_Idle_path) == 0) return samurai_Idle;
    if (strcmp(path, samurai_Walk_path) == 0) return samurai_Walk;
    if (strcmp(path, samurai_Run_path) == 0) return samurai_Run;
    if (strcmp(path, samurai_Attack_1_path) == 0) return samurai_Attack_1;
    if (strcmp(path, samurai_Attack_2_path) == 0) return samurai_Attack_2;
    if (strcmp(path, samurai_Attack_3_path) == 0) return samurai_Attack_3;
    if (strcmp(path, samurai_Hurt_path) == 0) return samurai_Hurt;
    if (strcmp(path, samurai_Protection_path) == 0) return samurai_Protection;
    if (strcmp(path, samurai_Dead_path) == 0) return samurai_Dead;


    if (strcmp(path, werewolf_Idle_path) == 0) return werewolf_Idle;
    if (strcmp(path, werewolf_Walk_path) == 0) return werewolf_Walk;
    if (strcmp(path, werewolf_Run_path) == 0) return werewolf_Run;
    if (strcmp(path, werewolf_Attack_1_path) == 0) return werewolf_Attack_1;
    if (strcmp(path, werewolf_Attack_2_path) == 0) return werewolf_Attack_2;
    if (strcmp(path, werewolf_Attack_3_path) == 0) return werewolf_Attack_3;
    if (strcmp(path, werewolf_Hurt_path) == 0) return werewolf_Hurt;
    if (strcmp(path, werewolf_Dead_path) == 0) return werewolf_Dead;
    if (strcmp(path, werewolf_Dead_Pic_path) == 0) return werewolf_Dead_Pic;
    
    
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