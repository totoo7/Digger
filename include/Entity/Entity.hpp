#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "Board.hpp"
using namespace std;

/**
 * @brief Represents a general entity in the game.
 * 
 * The Entity class serves as a base class for all movable and renderable 
 * game objects. It provides functionality for position, velocity, and rendering.
 */
class Entity {
    public:
        /**
         * @brief Default constructor for Entity.
         * 
         * Initializes an empty Entity object with default values.
         */
        Entity() = default;
        /**
         * @brief Constructs an Entity with specified parameters.
         * 
         * @param x The x-coordinate of the entity.
         * @param y The y-coordinate of the entity.
         * @param w The width of the entity.
         * @param h The height of the entity.
         * @param c The color of the entity represented as an SDL_Color.
         */
        Entity(int x, int y, int w, int h, SDL_Color c);
        /**
         * @brief Moves the entity on the game board.
         * 
         * Updates the entity's position based on its velocity. The movement logic 
         * can be overridden by derived classes for custom behavior.
         * 
         * @param board The game board used to check movement constraints.
         */
        virtual void move(Board& board);
        /**
         * @brief Renders the entity on the screen.
         * 
         * Draws the entity using the SDL_Renderer, considering its position 
         * and dimensions.
         * 
         * @param renderer The SDL_Renderer used for rendering.
         * @param tile_width The width of a single tile in pixels.
         * @param tile_height The height of a single tile in pixels.
         */
        virtual void render(SDL_Renderer* renderer, int tile_width, int tile_height) const;
        /**
         * @brief Sets the velocity of the entity.
         * 
         * @param dx The velocity in the x direction.
         * @param dy The velocity in the y direction.
         */
        void set_velocity(int dx, int dy);
        /**
         * @brief Gets the current velocity of the entity.
         * 
         * @return The velocity of the entity as an SDL_Point.
         */
        SDL_Point get_velocity() const { return velocity; };
        /**
         * @brief Sets the position of the entity.
         * 
         * @param x The new x-coordinate of the entity.
         * @param y The new y-coordinate of the entity.
         */
        void set_position(int x, int y);    
        /**
         * @brief Gets the current position of the entity.
         * 
         * @return The position of the entity as an SDL_Point.
         */
        SDL_Point get_position() const;
        /**
         * @brief Gets the color of the entity.
         * 
         * @return The SDL_Color of the entity.
         */
        SDL_Color get_color() const;
        /**
         * @brief Virtual destructor for Entity.
         */
        virtual ~Entity() = default;
    protected:
        SDL_Color color;  /**< The color of the entity. */
        SDL_Point position; /**< The position of the entity on the game board. */
        SDL_Point velocity; /**< The velocity of the entity in x and y directions. */
        int width, height; /**< The width and height of the entity in pixels. */
};

#endif