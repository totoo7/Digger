#ifndef EMERALD_HPP
#define EMERALD_HPP

#include "Collectible.hpp"

/**
 * @brief Represents an emerald collectible in the game.
 * 
 * The Emerald class is a derived class of Collectible that represents 
 * collectible emeralds on the game board. It provides specific behavior
 * for updating and rendering emeralds.
 */
class Emerald : public Collectible {
    public:
        /**
         * @brief Constructs an Emerald object.
         * 
         * @param x The x-coordinate of the emerald.
         * @param y The y-coordinate of the emerald.
         * @param color The color of the emerald represented as an SDL_Color.
         */
        Emerald(int x, int y, SDL_Color color);
        /**
         * @brief Updates the state of the emerald.
         * 
         * Defines how the emerald interacts with the game board. This
         * method is called during each game update cycle.
         * 
         * Currently this method has no purpose, since the emeralds can be only collected.
         * 
         * @param board The Board object used to determine game state and rules.
         */
        void update(Board& board) override;
        /**
         * @brief Renders the emerald on the screen.
         * 
         * Draws the emerald using the SDL_Renderer, taking into account
         * the tile dimensions and its position on the board.
         * 
         * @param renderer The SDL_Renderer used for rendering.
         * @param tile_width The width of a single tile in pixels.
         * @param tile_height The height of a single tile in pixels.
         */
        void render(SDL_Renderer* renderer, int tile_width, int tile_height) const override;
};

#endif