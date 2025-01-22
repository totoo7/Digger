#include "Player.hpp"
#include "Board.hpp"

Player::Player(int x, int y, int w, int h, SDL_Color c)
    : Entity(x, y, w, h, c) {}

void Player::handle_input(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:    set_velocity(0, -1); break; // Move up
            case SDLK_DOWN:  set_velocity(0, 1); break;  // Move down
            case SDLK_LEFT:  set_velocity(-1, 0); break; // Move left
            case SDLK_RIGHT: set_velocity(1, 0); break;  // Move right
            default: set_velocity(0, 0); break;
        }
    }
    else if (event.type == SDL_KEYUP) {
        set_velocity(0, 0);
    }
}

void Player::move(Board& board) {
    Entity::move(board);

    Tile& target_tile = board.get_tile(position.x, position.y);
    if (!target_tile.is_dug) {
        target_tile.set_dug();
    }
}

void Player::update(Board& board) {
    move(board);
}
