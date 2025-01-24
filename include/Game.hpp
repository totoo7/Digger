#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Renderer.hpp"
#include "Collectible.hpp"
#include "Gold.hpp"
#include "Emerald.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include <fstream>
class Game {
    public:
        Game() = default;
        bool init();
        bool run();
        void update();
        void handle_events();
        void render();
        SDL_Point get_player_position();
        ~Game();
    private:
        void deallocate();
    private:
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;
        const int TILE_WIDTH = 53;
        const int TILE_HEIGHT = 40;
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        Renderer* board_renderer = nullptr;
        Vector<Collectible*> collectibles;
        Vector<Enemy> enemies;
        Board* board = nullptr;
        Player player;
        bool is_running = false;
};

#endif