#include "./game.h"

int main(int argc, char* argv[])
{
    int frame_start;
    int frame_time;

    game_is_running = init_window(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        FULLSCREEN
    );

    frame_start = SDL_GetTicks();

    while (game_is_running)
    {
        game();
    }

    frame_time = SDL_GetTicks() - frame_start;

    if (frame_time < DELAY_TIME)
    {
        SDL_Delay((int)(DELAY_TIME - frame_time));
    }
    
    
    destroy_window();

    return 0;
}