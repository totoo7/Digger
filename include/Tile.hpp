#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

struct Tile {
    SDL_Point position;
    SDL_Color color;
    bool is_dug = false;
    bool has_entity = false;
    bool has_collectible = false;
    Tile()=default;
    Tile(int x, int y, SDL_Color color);
};

#endif