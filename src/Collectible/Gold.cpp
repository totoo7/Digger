#include "Gold.hpp"

Gold::Gold(int x, int y, SDL_Color color) :
    Collectible(x, y, color) {}

void Gold::update(Board& board) {
    auto current_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_since_last_update(current_time - last_update_time);

    if (time_since_last_update.count() >= 0.7) {
        Tile& below_tile = board.get_tile(position.x, position.y + 1);
        if (below_tile.is_dug) {
            position.y += 1;
            is_falling = true;
            fall_distance++;
        } else {
            is_falling = false;
            if (fall_distance > 1) {
                is_broken = true;
            }
            fall_distance = 0;
        }
        last_update_time = current_time;
    }
}

void Gold::render(SDL_Renderer* renderer, int tile_width, int tile_height) const {
    SDL_Rect rect = { position.x * tile_width, position.y * tile_height, tile_width, tile_height };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

