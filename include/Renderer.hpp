#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Board.hpp"
#include "Vector/Vector.hpp"
#include "Collectible.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

/**
 * @brief Handles rendering all game elements to the screen.
 * 
 * The Renderer class provides functionality to render the board, player,
 * enemies, and collectibles using SDL.
 */
class Renderer {
    public:
        /**
         * @brief Constructs a Renderer instance.
         * 
         * @param sdl_renderer The SDL_Renderer used for rendering.
         * @param t_width The width of each tile in pixels.
         * @param t_height The height of each tile in pixels.
         */
        Renderer(SDL_Renderer* sdl_renderer, int t_width, int t_height);
        /**
         * @brief Renders the game board.
         * 
         * @param board The Board instance to render.
         */
        void render_board(Board& board);
        /**
         * @brief Renders all collectible items on the board.
         * 
         * @param entities A Vector containing pointers to Collectible objects.
         */
        void render_collectibles(const Vector<Collectible*>& entities);
        /**
         * @brief Renders all enemies on the board.
         * 
         * @param enemies A Vector containing Enemy objects.
         */
        void render_enemies(const Vector<Enemy>& enemies);
        /**
         * @brief Renders the player on the board.
         * 
         * @param player The Player instance to render.
         */
        void render_player(const Player& player);
    private:
        SDL_Renderer* renderer; /**< The SDL_Renderer used for rendering. */
        int tile_width, tile_height; /**< The width and height of each tile in pixels. */
};

#endif