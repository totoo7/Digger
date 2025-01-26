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

/**
 * @class Game
 * @brief The main class for managing game state, rendering, and user input.
 * 
 * The Game class encapsulates the entire game logic, including initialization, event
 * handling, updating game entities (like the player, enemies, and collectibles), 
 * and rendering the game world. It manages the game loop, controls the player
 * and enemies, and handles the spawning and destruction of game elements.
 * 
 * The Game class is responsible for running the main game loop, handling input,
 * updating the game state, rendering, and managing entities such as the player,
 * enemies, and collectibles.
 */
class Game {
    public:
        /**
         * @brief Default constructor for the Game class.
         * Initializes necessary members for the game state.
         */
        Game() = default;
        /**
         * @brief Initializes the game, including setting up the board, renderer, and window.
         * 
         * The method creates a board from Level.txt file.
         * 
         * @return Returns true if initialization is successful, false otherwise.
         */
        bool init();
        /**
         * @brief Runs the main game loop.
         * Continuously processes events, updates game state, and renders the game.
         * @return Returns true if the game loop is running, false when the game ends.
         */
        bool run();
        /**
         * @brief Updates the game state, including player, enemies, and collectibles.
         * Handles logic for movement, interactions, and conditions like death and respawn.
         */
        void update();
        /**
         * @brief Handles all user input events (e.g., keyboard presses, mouse movements).
         * Processes input to control the player and trigger game actions like firing gold.
         */
        void handle_events();
        /**
         * @brief Renders the game world, including the player, enemies, and collectibles.
         * Draws the board and all the game entities onto the screen.
         */
        void render();
        /**
         * @brief Returns the current position of the player.
         * @return SDL_Point representing the player's position on the board.
         */
        SDL_Point get_player_position();
        /**
         * @brief Returns the initial spawn position of the player.
         * @return SDL_Point representing the player's spawn position on the board.
         */
        SDL_Point get_player_spawn_position() { return player_spawn_position; };
        /**
         * @brief Respawns the player after death, resetting their position and lives.
         * Respawns the enemies to their spawn points.
         */
        void respawn();
        /**
         * @brief Kills the enemy at the specified index in the enemies array.
         * The enemy is removed from the game, and the player's score is updated.
         * @param index The index of the enemy to be killed in the enemies vector.
         */
        void kill_enemy(size_t index);
        /**
         * @brief Removes the collectible at the specified index in the collectibles list.
         * The collectible is deleted, and it is no longer part of the game world.
         * @param index The index of the collectible to be removed.
         */
        void remove_collectible(size_t index);
        /**
         * @brief Destructor for the Game class.
         * Frees any dynamically allocated memory and cleans up the game state.
         */
        ~Game();
    private:
        /**
         * @brief Deallocates dynamically allocated resources.
         * This method is used to release any memory or resources when the game ends.
         */
        void deallocate();
    private:
        const int SCREEN_WIDTH = 800; ///< The width of the game window in pixels.
        const int SCREEN_HEIGHT = 600; ///< The height of the game window in pixels.
        const int TILE_WIDTH = 53; ///< The width of each tile in pixels.
        const int TILE_HEIGHT = 40; ///< The height of each tile in pixels.
    private:
        SDL_Window* window = nullptr; ///< Pointer to the SDL window.
        SDL_Renderer* renderer = nullptr; ///< Pointer to the SDL renderer.
        Renderer* board_renderer = nullptr; ///< Pointer to the Renderer class responsible for rendering the board.
        Vector<Collectible*> collectibles; ///< Array of collectible items in the game.
        Vector<Enemy> enemies; ///< Array of enemy entities in the game.
        Vector<SDL_Point> enemy_spawns; ///< Array of enemy spawn positions.
        Board* board = nullptr; ///< Pointer to the game board that holds the tiles.
        Player player; ///< The player entity in the game.
        SDL_Point player_spawn_position; ///< The spawn position of the player.
        std::chrono::time_point<std::chrono::high_resolution_clock> last_death_time; ///< The timestamp of the player's last death.
        std::chrono::time_point<std::chrono::high_resolution_clock> last_spawn_time = std::chrono::high_resolution_clock::now(); ///< The timestamp of the last enemy spawn.
        const double respawn_time = 1000; ///< Time in milliseconds between player deaths and respawns.
        int enemy_count; ///< The total number of enemies in the game.
        bool is_running = false; ///< Flag indicating whether the game is running.
};

#endif