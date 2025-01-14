#ifndef COLLECTIBLE_HPP
#define COLLECTIBLE_HPP

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

class Collectible {
    public:
        Collectible(int x, int y, SDL_Color color);
        SDL_Point get_position() const;
        SDL_Color get_color() const;
        void set_position(int x, int y);
        virtual void update() = 0;
        virtual void render(SDL_Renderer* renderer, int tile_width, int tile_height) const = 0;
        virtual ~Collectible() = default;
    protected:
        SDL_Point position;
        SDL_Color color;
};

#endif