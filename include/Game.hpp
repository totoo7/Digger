#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Renderer.hpp"
#include "Collectible.hpp"
#include "Gold.hpp"
#include "Emerald.hpp"

class Game {
    public:
        Game() = default;
        bool init();
        void init_collectibles();
        void run();
        void update();
        void handle_events();
        void render();
        ~Game();
    private:
        void deallocate();
    private:
        const int SCREEN_WIDTH = 960;
        const int SCREEN_HEIGHT = 540;
        const int TILE_WIDTH = 30;
        const int TILE_HEIGHT = 30;
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        Board* board = nullptr;
        Renderer* board_renderer = nullptr;
        SDL_Event event;
        Vector<Collectible*> collectibles;
        int player_x, player_y;
        bool is_running = false;
};

#endif