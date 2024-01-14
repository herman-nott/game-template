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


SDL_Texture* load(SDL_Renderer *renderer, char *path);

void resource_init(SDL_Renderer *renderer);

SDL_Texture* request_texture(char* path);

SDL_Texture* load_texture(SDL_Renderer *renderer, char* path);

#endif