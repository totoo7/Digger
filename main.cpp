#include "Game.hpp"

const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;

int main(int argc, char* argv[]) {
    uint32_t frame_start;
    uint32_t frame_time;
    Game game;
    if (!game.init()) {
        SDL_Log("Failed to initialize the game!");
        return -1;
    }
    while (game.run()) {
        frame_start = SDL_GetTicks();
        game.run();
        frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < FRAME_DELAY) {
            int ms = FRAME_DELAY - frame_time;
            SDL_Delay(ms);
        }
    }
    return 0;
}