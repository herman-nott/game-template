#include "./play.h"

bool player_first_start = true;
bool enemy_first_start = true;

int player_current_frame;
int player_frames_number;

int enemy_current_frame;
int enemy_frames_number;

bool is_right_pressed = false;
bool is_left_pressed = false;

bool is_attacking_1 = false;
// int attack_start_1 = 0;
int attack_duration_1 = 100;

bool is_attacking_2 = false;
// int attack_start_2 = 0;
int attack_duration_2 = 100;

bool is_attacking_3 = false;
// int attack_start_3 = 0;
int attack_duration_3 = 100;


void play(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        buttons(event);
        play_handle_events(event);
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

void reset_play_state(void)
{
    player_first_start = true;
    enemy_first_start = true;

    is_right_pressed = false;
    is_left_pressed = false;

    is_attacking_1 = false;

    is_attacking_2 = false;

    is_attacking_3 = false;

    player.pos_x = -128;
    player.state = PLAYER_IDLE;

    enemy.health = 4;
    enemy.pos_x = 628;
    enemy.state = ENEMY_IDLE;
}

void play_properties(SDL_Renderer* renderer, SDL_Event event, enum GameStates *interface, int *mouse_x, int *mouse_y, UIELEMENT *return_element, UIELEMENT *return_hover_element)
{
    if (*mouse_x > 40 && *mouse_x < 76) 
    {
        if (*mouse_y > 430 && *mouse_y < 466)
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

// рисует игровой интерфейс 
void draw_play_interface(SDL_Renderer* renderer)
{
    draw_element(renderer, &return_element, 36, 36);
    draw_element(renderer, &return_hover_element, 36, 36);
}

void play_logic(SDL_Renderer* renderer) 
{
    player.state = PLAYER_IDLE;
    enemy.state = ENEMY_IDLE;

    // ---------------------------------------------------
    if (player.pos_x != 200 && player_first_start)
    {
        player.state = PLAYER_RUN;
        player_move(&player);
    }
    else
    {
        player.state == PLAYER_IDLE;
        player_first_start = false;
    }


    if (enemy.pos_x != 250 && enemy_first_start)
    {
        enemy.state = ENEMY_RUN;
        enemy_move(&enemy);
    }
    else
    {
        enemy.state == ENEMY_IDLE;
        enemy_first_start = false;
    }
    // ---------------------------------------------------

    if (is_right_pressed || is_left_pressed)     player.state = PLAYER_RUN;
    if (is_attacking_1)                          player.state = PLAYER_ATTACK_1;
    if (is_attacking_2)                          player.state = PLAYER_ATTACK_2;
    if (is_attacking_3)                          player.state = PLAYER_ATTACK_3;

    if (is_attacking_1 || is_attacking_2 || is_attacking_3)
    {
        enemy.state = ENEMY_HURT;
    }
    
    if (enemy.health <= 0)
    {
        SDL_Delay(10);
        enemy.state = ENEMY_DEAD;
        enemy.state = ENEMY_DEAD_PIC;

        player.state = PLAYER_WALK;
        player_move(&player);
    }
    

    player_set_frames_number(&player, &player_frames_number);
    player_current_frame = (int)((SDL_GetTicks() / 100) % player_frames_number);
    player_draw_frame(renderer, &player, player.state, 128, 128, player_current_frame, 1);

    enemy_set_frames_number(&enemy, &enemy_frames_number);
    enemy_current_frame = (int)((SDL_GetTicks() / 100) % enemy_frames_number);
    if (enemy.state == ENEMY_DEAD_PIC)
    {
        enemy_draw(renderer, &enemy, enemy.state, 128, 128);
    }
    else
    {
        enemy_draw_frame(renderer, &enemy, enemy.state, 128, 128, enemy_current_frame, 1);
    }
}

void play_handle_events(SDL_Event event)
{
    static int attack_start_1 = 0;
    static int attack_start_2 = 0;
    static int attack_start_3 = 0;
    
    switch (event.type)
    {
    case SDL_KEYDOWN:
        switch (event.key.keysym.scancode)
        {
        case SDL_SCANCODE_RIGHT:
        case SDL_SCANCODE_D:
            is_right_pressed = true;
            break;

        case SDL_SCANCODE_LEFT:
        case SDL_SCANCODE_A:
            is_left_pressed = true;
            break;
        }
        break;

    case SDL_KEYUP:
        switch (event.key.keysym.scancode)
        {
        case SDL_SCANCODE_RIGHT:
        case SDL_SCANCODE_D:
            is_right_pressed = false;
            break;

        case SDL_SCANCODE_LEFT:
        case SDL_SCANCODE_A:
            is_left_pressed = false;
            break;
        }
        break;
    
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT) 
        {
            enemy.health--;
            attack_start_1 = SDL_GetTicks();
            is_attacking_1 = true;
        }
        if (event.button.button == SDL_BUTTON_RIGHT) 
        {
            enemy.health--;
            attack_start_2 = SDL_GetTicks();
            is_attacking_2 = true;
        }
        if (event.button.button == SDL_BUTTON_MIDDLE) 
        {
            enemy.health--;
            attack_start_3 = SDL_GetTicks();
            is_attacking_3 = true;
        }

        break;
    }


    int now = SDL_GetTicks();
    if (is_attacking_1 && (now - attack_start_1 > attack_duration_1)) 
    {
        is_attacking_1 = false;
        attack_start_1 = 0;
    }
    
    if (is_attacking_2 && (now - attack_start_2 > attack_duration_2)) 
    {
        is_attacking_2 = false;
        attack_start_2 = 0;
    }

    if (is_attacking_3 && (now - attack_start_3 > attack_duration_3)) 
    {
        is_attacking_3 = false;
        attack_start_3 = 0;
    }
}

