#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Board.hpp"
#include "Vector/Vector.hpp"
#include "Collectible.hpp"

class Renderer {
    public:
        Renderer(SDL_Renderer* sdl_renderer, int t_width, int t_height);
        void render_board(const Board& board) const;
        void render_collectibles(const Vector<Collectible*>& entities);
    private:
        SDL_Renderer* renderer;
        int tile_width, tile_height;
};

#endif