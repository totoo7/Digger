#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

/**
 * @brief Represents a tile on the game board.
 * 
 * A tile can have properties such as being dug, having an entity, 
 * or having a collectible. It also holds positional and color data.
 */
struct Tile {
    /**
     * @brief Default constructor for a Tile.
     */
    Tile()=default;
    /**
     * @brief Constructs a Tile with a specified position and color.
     * 
     * @param x The x-coordinate of the tile's position.
     * @param y The y-coordinate of the tile's position.
     * @param color The color of the tile, represented as an SDL_Color.
     */
    Tile(int x, int y, SDL_Color color);
    /**
     * @brief Assignment operator for the Tile struct.
     * 
     * Copies the properties of another Tile to this Tile.
     * 
     * @param rhs The Tile to copy from.
     * @return Reference to this Tile after assignment.
     */
    Tile& operator=(const Tile& rhs) = default;
    /**
     * @brief Marks the tile as dug.
     * 
     * Changes the `is_dug` flag to true and the color to black.
     */
    void set_dug();
    SDL_Point position; /**< The position of the tile on the game board. */
    SDL_Color color; /**< The color of the tile. */
    bool is_dug = false; /**< Indicates if the tile has been dug. */
    bool has_entity = false; /**< Indicates if the tile contains an entity. */
    bool has_collectible = false; /**< Indicates if the tile contains a collectible. */
};

#endif