#ifndef COLLECTIBLE_HPP
#define COLLECTIBLE_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "Board.hpp"
using namespace std;

/**
 * @brief Base class for collectible items in the game.
 * 
 * The Collectible class provides a common interface for all collectible items,
 * such as Gold and Emerald, and handles their basic properties like position
 * and color.
 */
class Collectible {
    public:
        /**
         * @brief Constructs a Collectible object.
         * 
         * @param x The x-coordinate of the collectible.
         * @param y The y-coordinate of the collectible.
         * @param color The color of the collectible represented as an SDL_Color.
         */
        Collectible(int x, int y, SDL_Color color);
        /**
         * @brief Gets the position of the collectible.
         * 
         * @return SDL_Point The position of the collectible.
         */
        SDL_Point get_position() const;
        /**
         * @brief Gets the color of the collectible.
         * 
         * @return SDL_Color The color of the collectible.
         */
        SDL_Color get_color() const;
        /**
         * @brief Sets the position of the collectible.
         * 
         * @param x The new x-coordinate of the collectible.
         * @param y The new y-coordinate of the collectible.
         */
        void set_position(int x, int y);
        /**
         * @brief Updates the state of the collectible.
         * 
         * This is a pure virtual function that must be implemented
         * by derived classes to define specific update behavior.
         * 
         * @param board The Board object used to determine game state and rules.
         */
        virtual void update(Board& board) = 0;
        /**
         * @brief Renders the collectible on the screen.
         * 
         * This is a pure virtual function that must be implemented
         * by derived classes to define specific rendering behavior.
         * 
         * @param renderer The SDL_Renderer used for rendering.
         * @param tile_width The width of a single tile in pixels.
         * @param tile_height The height of a single tile in pixels.
         */
        virtual void render(SDL_Renderer* renderer, int tile_width, int tile_height) const = 0;
        /**
         * @brief Virtual destructor for the Collectible class.
         */
        virtual ~Collectible() = default;
    protected:
        SDL_Point position; /**< The position of the collectible on the board. */
        SDL_Color color; /**< The color of the collectible. */
};

#endif