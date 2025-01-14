#include "Gold.hpp"

Gold::Gold(int x, int y, SDL_Color color) :
    Collectible(x, y, color) {}

void Gold::update() {
    //TODO
}

void Gold::render(SDL_Renderer* renderer, int tile_width, int tile_height) const {
    SDL_Rect rect = { position.x * tile_width, position.y * tile_height, tile_width, tile_height };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

