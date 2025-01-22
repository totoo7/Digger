#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"

class Enemy : public Entity {
    public:
        Enemy() = default;
        Enemy(int x, int y, int w, int h, SDL_Color c);
        void update() override;
        void move(int board_width, int board_height);
    private:
};

#endif