#ifndef __Player__
#define __Player__

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "./resources.h"

enum PlayerStates
{
    PLAYER_IDLE = 0,
    PLAYER_WALK = 1,
    PLAYER_RUN = 2,
    PLAYER_ATTACK_1 = 3,
    PLAYER_ATTACK_2 = 4,
    PLAYER_ATTACK_3 = 5,
    PLAYER_HURT = 6,
    PLAYER_PROTECTION = 7,
    PLAYER_DEAD = 8
};

typedef struct _PLAYER
{
    int pos_x;
    int pos_y;
    int speed;

    enum PlayerStates state;

    SDL_Texture* texture;
} PLAYER;

PLAYER create_player(int pos_x, int pos_y, int speed, enum PlayerStates state, SDL_Texture* texture);

void player_draw_frame(SDL_Renderer* renderer, PLAYER *player, enum PlayerStates state, int imageW, int imageH, int current_frame, int current_row);

void check_player_state(SDL_Renderer *renderer, PLAYER *player);

void player_move(PLAYER *player);

void player_set_frames_number(PLAYER *player, int *current_frame);

#endif