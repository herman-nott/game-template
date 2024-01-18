#include "./player.h"

PLAYER create_player(int pos_x, int pos_y, int speed, enum PlayerStates state, SDL_Texture* texture)
{
    PLAYER player;

    player.pos_x = pos_x;
    player.pos_y = pos_y;
    player.speed = speed;

    player.state = state;

    player.texture = texture;

    return player;
}

void check_player_state(SDL_Renderer *renderer, PLAYER *player)
{
    if (player->state == PLAYER_IDLE)          player->texture = load_texture(renderer, samurai_Idle_path);
    if (player->state == PLAYER_WALK)          player->texture = load_texture(renderer, samurai_Walk_path);
    if (player->state == PLAYER_RUN)           player->texture = load_texture(renderer, samurai_Run_path);
    if (player->state == PLAYER_ATTACK_1)      player->texture = load_texture(renderer, samurai_Attack_1_path);
    if (player->state == PLAYER_ATTACK_2)      player->texture = load_texture(renderer, samurai_Attack_2_path);
    if (player->state == PLAYER_ATTACK_3)      player->texture = load_texture(renderer, samurai_Attack_3_path);
    if (player->state == PLAYER_HURT)          player->texture = load_texture(renderer, samurai_Hurt_path);
    if (player->state == PLAYER_PROTECTION)    player->texture = load_texture(renderer, samurai_Protection_path);
    if (player->state == PLAYER_DEAD)          player->texture = load_texture(renderer, samurai_Dead_path);
}

void player_draw_frame(SDL_Renderer* renderer, PLAYER *player, enum PlayerStates state, int imageW, int imageH, int current_frame, int current_row)
{
    check_player_state(renderer, player);
    SDL_Rect src_rect; 
    SDL_Rect dest_rect;

    src_rect.x = imageW * current_frame;
    src_rect.y = imageH * (current_row - 1);
    src_rect.w = dest_rect.w = imageW;
    src_rect.h = dest_rect.h = imageH;
    dest_rect.x = player->pos_x;
    dest_rect.y = player->pos_y;

    SDL_RenderCopy(renderer, player->texture, &src_rect, &dest_rect);
}

void player_set_frames_number(PLAYER *player, int *current_frame)
{
    if (player->state == PLAYER_IDLE)          *current_frame = 5;
    if (player->state == PLAYER_WALK)          *current_frame = 9;
    if (player->state == PLAYER_RUN)           *current_frame = 8;
    if (player->state == PLAYER_ATTACK_1)      *current_frame = 4;
    if (player->state == PLAYER_ATTACK_2)      *current_frame = 5;
    if (player->state == PLAYER_ATTACK_3)      *current_frame = 4;
    if (player->state == PLAYER_HURT)          *current_frame = 2;
    if (player->state == PLAYER_PROTECTION)    *current_frame = 2;
    if (player->state == PLAYER_DEAD)          *current_frame = 6;
}

void player_move(PLAYER *player)
{
    SDL_Delay(5);
    player->pos_x += player->speed;
}