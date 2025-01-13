#include "Renderer.hpp"

Renderer::Renderer(SDL_Renderer* sdl_renderer, int t_width, int t_height)
        : renderer(sdl_renderer), tile_width(t_width), tile_height(t_height) {}

void Renderer::render_board(const Board& board) const {
    for (size_t x = 0; x < BOARD_HEIGHT; ++x) {
        for (size_t y = 0; y < BOARD_WIDTH; ++y) {
            const Tile& tile = board.get_tile(x, y);
            SDL_Rect rect = {
                tile.position.x * tile_width,
                tile.position.y * tile_height,
                tile_width,
                tile_height
            };

            SDL_SetRenderDrawColor(renderer, tile.color.r, tile.color.g, tile.color.b, tile.color.a);
            SDL_RenderFillRect(renderer, &rect);

            //grid lines
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
}

