#ifndef __Resources__
#define __Resources__

#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>

extern char* menuBG;
extern char* playBG;
extern char* settingsBG;

extern char* arrowBG;

extern char* homeBTN;
extern char* homeHoverBTN;
extern char* returnBTN;
extern char* returnHoverBTN;


extern char* samurai_Idle_path;
extern char* samurai_Walk_path;
extern char* samurai_Run_path;
extern char* samurai_Attack_1_path;
extern char* samurai_Attack_2_path;
extern char* samurai_Attack_3_path;
extern char* samurai_Hurt_path;
extern char* samurai_Protection_path;
extern char* samurai_Dead_path;


extern char* werewolf_Idle_path;
extern char* werewolf_Walk_path;
extern char* werewolf_Run_path;
extern char* werewolf_Attack_1_path;
extern char* werewolf_Attack_2_path;
extern char* werewolf_Attack_3_path;
extern char* werewolf_Hurt_path;
extern char* werewolf_Dead_path;
extern char* werewolf_Dead_Pic_path;


SDL_Texture* load(SDL_Renderer *renderer, char *path);

void resource_init(SDL_Renderer *renderer);

SDL_Texture* request_texture(char* path);

SDL_Texture* load_texture(SDL_Renderer *renderer, char* path);

#endif