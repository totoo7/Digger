#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Board.hpp"

class Renderer {
    public:
        Renderer(SDL_Renderer* sdl_renderer, int t_width, int t_height);
        void render_board(const Board& board) const;
    private:
        SDL_Renderer* renderer;
        int tile_width, tile_height;
};

#endif