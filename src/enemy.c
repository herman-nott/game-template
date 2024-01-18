#include "./enemy.h"

ENEMY create_enemy(int pos_x, int pos_y, int speed, int health, enum EnemyStates state, SDL_Texture* texture)
{
    ENEMY enemy;

    enemy.pos_x = pos_x;
    enemy.pos_y = pos_y;
    enemy.speed = speed;

    enemy.state = state;

    enemy.texture = texture;

    enemy.health = health;

    return enemy;
}

void check_enemy_state(SDL_Renderer *renderer, ENEMY *enemy)
{
    if (enemy->state == ENEMY_IDLE)           enemy->texture = load_texture(renderer, werewolf_Idle_path);
    if (enemy->state == ENEMY_WALK)           enemy->texture = load_texture(renderer, werewolf_Walk_path);
    if (enemy->state == ENEMY_RUN)            enemy->texture = load_texture(renderer, werewolf_Run_path);
    if (enemy->state == ENEMY_ATTACK_1)       enemy->texture = load_texture(renderer, werewolf_Attack_1_path);
    if (enemy->state == ENEMY_ATTACK_2)       enemy->texture = load_texture(renderer, werewolf_Attack_2_path);
    if (enemy->state == ENEMY_ATTACK_3)       enemy->texture = load_texture(renderer, werewolf_Attack_3_path);
    if (enemy->state == ENEMY_HURT)           enemy->texture = load_texture(renderer, werewolf_Hurt_path);
    if (enemy->state == ENEMY_DEAD)           enemy->texture = load_texture(renderer, werewolf_Dead_path);
    if (enemy->state == ENEMY_DEAD_PIC)       enemy->texture = load_texture(renderer, werewolf_Dead_Pic_path);
}

void enemy_draw(SDL_Renderer* renderer, ENEMY *enemy, enum EnemyStates state, int imageW, int imageH)
{
    check_enemy_state(renderer, enemy);

    SDL_Rect src_rect; 
    SDL_Rect dest_rect;

    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = dest_rect.w = imageW;
    src_rect.h = dest_rect.h = imageH;
    dest_rect.x = enemy->pos_x;
    dest_rect.y = enemy->pos_y;

    SDL_RenderCopyEx(renderer, enemy->texture, &src_rect, &dest_rect, 0, 0, SDL_FLIP_HORIZONTAL);
}

void enemy_draw_frame(SDL_Renderer* renderer, ENEMY *enemy, enum EnemyStates state, int imageW, int imageH, int current_frame, int current_row)
{
    check_enemy_state(renderer, enemy);
    
    SDL_Rect src_rect; 
    SDL_Rect dest_rect;

    src_rect.x = imageW * current_frame;
    src_rect.y = imageH * (current_row - 1);
    src_rect.w = dest_rect.w = imageW;
    src_rect.h = dest_rect.h = imageH;
    dest_rect.x = enemy->pos_x;
    dest_rect.y = enemy->pos_y;

    SDL_RenderCopyEx(renderer, enemy->texture, &src_rect, &dest_rect, 0, 0, SDL_FLIP_HORIZONTAL);
}

void enemy_set_frames_number(ENEMY *enemy, int *current_frame)
{
    if (enemy->state == ENEMY_IDLE)          *current_frame = 8;
    if (enemy->state == ENEMY_WALK)          *current_frame = 11;
    if (enemy->state == ENEMY_RUN)           *current_frame = 9;
    if (enemy->state == ENEMY_ATTACK_1)      *current_frame = 6;
    if (enemy->state == ENEMY_ATTACK_2)      *current_frame = 4;
    if (enemy->state == ENEMY_ATTACK_3)      *current_frame = 5;
    if (enemy->state == ENEMY_HURT)          *current_frame = 2;
    if (enemy->state == ENEMY_DEAD)          *current_frame = 2;
}

void enemy_move(ENEMY *enemy)
{
    // SDL_Delay(5);
    enemy->pos_x -= enemy->speed;
}