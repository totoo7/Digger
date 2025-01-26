#ifndef BOARD_HPP
#define BOARD_HPP
#include "Tile.hpp"

const int BOARD_WIDTH = 15; /// The width of the game board.
const int BOARD_HEIGHT = 15; /// The height of the game board.

/**
 * @brief Represents the game board consisting of tiles.
 * 
 * The board manages the grid of tiles and provides access to individual tiles.
 * It also stores the dimensions of the board.
 */
class Board {
    public:
        /**
         * @brief Constructs a Board with specified tile dimensions.
         * 
         * @param width The width of a single tile.
         * @param height The height of a single tile.
         */
        Board(size_t width, size_t height); 
        /**
         * @brief Retrieves a reference to a tile at the specified position.
         * 
         * @param x The x-coordinate of the tile.
         * @param y The y-coordinate of the tile.
         * @return A reference to the tile at the specified position.
         */
        Tile& get_tile(int x, int y);
        /**
         * @brief Gets the width of the board in terms of the number of tiles.
         * 
         * @return The number of tiles in the horizontal direction.
         */
        const int get_width() const { return BOARD_WIDTH; }
        /**
         * @brief Gets the height of the board in terms of the number of tiles.
         * 
         * @return The number of tiles in the vertical direction.
         */
        const int get_height() const { return BOARD_HEIGHT; }
    public:
        const int tile_width, tile_height; /**< The width and height of a single tile in pixels. */
        Tile board[BOARD_WIDTH][BOARD_HEIGHT]; /**< A 2D array representing the tiles on the board. */
};

#endif