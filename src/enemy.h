#ifndef __Enemy__
#define __Enemy__

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "./resources.h"

enum EnemyStates
{
    ENEMY_IDLE = 0,
    ENEMY_WALK = 1,
    ENEMY_RUN = 2,
    ENEMY_ATTACK_1 = 3,
    ENEMY_ATTACK_2 = 4,
    ENEMY_ATTACK_3 = 5,
    ENEMY_HURT = 6,
    ENEMY_DEAD = 7,
    ENEMY_DEAD_PIC = 8
};

typedef struct _ENEMY
{
    int pos_x;
    int pos_y;
    int speed;

    int health;

    enum EnemyStates state;

    SDL_Texture* texture;
} ENEMY;

ENEMY create_enemy(int pos_x, int pos_y, int speed, int health, enum EnemyStates state, SDL_Texture* texture);

void enemy_draw(SDL_Renderer* renderer, ENEMY *enemy, enum EnemyStates state, int imageW, int imageH);

void enemy_draw_frame(SDL_Renderer* renderer, ENEMY *enemy, enum EnemyStates state, int imageW, int imageH, int current_frame, int current_row);

void check_enemy_state(SDL_Renderer *renderer, ENEMY *enemy);

void enemy_move(ENEMY *enemy);

void enemy_set_frames_number(ENEMY *enemy, int *current_frame);

#endif