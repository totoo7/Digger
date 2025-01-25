#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "Board.hpp"
using namespace std;

class Entity {
    public:
        Entity() = default;
        Entity(int x, int y, int w, int h, SDL_Color c);
        virtual void move(Board& board);
        virtual void render(SDL_Renderer* renderer, int tile_width, int tile_height) const;
        void set_velocity(int dx, int dy);
        SDL_Point get_velocity() const { return velocity; };
        void set_position(int x, int y);    
        SDL_Point get_position() const;
        SDL_Color get_color() const;
        virtual ~Entity() = default;
    protected:
        SDL_Point position;
        SDL_Point velocity;
        SDL_Color color;
        int width, height;
};

#endif