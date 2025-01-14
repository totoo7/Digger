#include "Emerald.hpp"

Emerald::Emerald(int x, int y, SDL_Color color) :
    Collectible(x, y, color) {}

void Emerald::update() {
    //TODO
}

void Emerald::render(SDL_Renderer* renderer, int tile_width, int tile_height) const {
    SDL_Rect rect = { position.x * tile_width, position.y * tile_height, tile_width, tile_height };
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Render the Emerald as a filled rectangle
    SDL_RenderFillRect(renderer, &rect);
}

