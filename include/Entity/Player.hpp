#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity {
    public:
        Player() = default;
        Player(int x, int y, int w, int, SDL_Color color);
        void handle_input(const SDL_Event& event);
        void update() override;
};

#endif