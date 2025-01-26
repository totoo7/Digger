#ifndef GOLD_HPP
#define GOLD_HPP

#include "Collectible.hpp"
#include <chrono>

/**
 * @brief Represents a gold collectible in the game.
 * 
 * The Gold class is a specialized type of Collectible that implements specific 
 * behavior for falling and breaking mechanics. Gold blocks can fall through dug 
 * tiles and may break upon falling from a certain height. Also kills an Entity if 
 * it collides with one while falling. In the original game the Player can pick up
 * broken gold and shoot it, however in this project this logic is not implemented yet.
 */
class Gold : public Collectible {
    public:
        /**
         * @brief Constructs a Gold object.
         * 
         * @param x The x-coordinate of the gold.
         * @param y The y-coordinate of the gold.
         * @param color The color of the gold represented as an SDL_Color.
         */
        Gold(int x, int y, SDL_Color color);
        /**
         * @brief Updates the state of the gold.
         * 
         * Handles the falling and breaking mechanics of the gold based on 
         * the state of the tiles below it and the time since the last update.
         * 
         * @param board The Board object used to check tile states.
         */
        void update(Board& board) override;
        /**
         * @brief Renders the gold on the screen.
         * 
         * Draws the gold using the SDL_Renderer, taking into account
         * the tile dimensions and its position on the board.
         * 
         * @param renderer The SDL_Renderer used for rendering.
         * @param tile_width The width of a single tile in pixels.
         * @param tile_height The height of a single tile in pixels.
         */
        void render(SDL_Renderer* renderer, int tile_width, int tile_height) const override;
        /**
         * @brief Checks if the gold is broken.
         * 
         * @return True if the gold is broken, otherwise false.
         */
        bool get_is_broken() const { return is_broken; };
    private:
        int fall_distance = 0; /**< Tracks the distance the gold has fallen. */
        chrono::time_point<chrono::high_resolution_clock> last_update_time = chrono::high_resolution_clock::now(); /**< Tracks the last time the gold was updated. */
        bool is_falling = false; /**< Indicates whether the gold is currently falling. */
        bool is_broken = false; /**< Indicates whether the gold has broken. */
};

#endif