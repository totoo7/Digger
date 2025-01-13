#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Renderer.hpp"

class Game {
    public:
        Game() = default;
        bool init();
        void run();
        void update();
        void handle_events();
        void render();
        ~Game();
    private:
        void deallocate();
    private:
        const int SCREEN_WIDTH = 1024;
        const int SCREEN_HEIGHT = 768;
        const int TILE_WIDTH = 25;
        const int TILE_HEIGHT = 25;
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        Board* board = nullptr;
        Renderer* board_renderer = nullptr;
        SDL_Event event;
        int player_x, player_y;
        bool is_running = false;
};

#endif