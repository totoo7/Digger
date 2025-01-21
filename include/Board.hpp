#ifndef BOARD_HPP
#define BOARD_HPP
#include "Tile.hpp"
const int BOARD_WIDTH = 15;
const int BOARD_HEIGHT = 15;


class Board {
    public:
        Board(size_t width, size_t height); 
        const Tile& get_tile(int x, int y) const;
    public:
        const int tile_width, tile_height;
        Tile board[BOARD_WIDTH][BOARD_HEIGHT];
};

#endif