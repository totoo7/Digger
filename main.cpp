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
    game.run();
    return 0;
}