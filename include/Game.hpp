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
        SDL_Point get_player_spawn_position() { return player_spawn_position; };
        void respawn();
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
        Vector<SDL_Point> enemy_spawns;
        Board* board = nullptr;
        Player player;
        SDL_Point player_spawn_position;
        std::chrono::time_point<std::chrono::high_resolution_clock> last_death_time;
        const double respawn_time = 5.0;
        bool is_running = false;
};

#endif