#include "Game.hpp"
int main(int argc, char* argv[]) {
    Game game;
    if (!game.init()) {
        SDL_Log("Failed to initialize the game!");
        return -1;
    }
    game.run();
    return 0;
}