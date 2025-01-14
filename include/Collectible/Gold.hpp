#ifndef GOLD_HPP
#define GOLD_HPP

#include "Collectible.hpp"

class Gold : public Collectible {
    public:
        Gold(int x, int y, SDL_Color color);
        void update() override;
        void render(SDL_Renderer* renderer, int tile_width, int tile_height) const override;
};

#endif