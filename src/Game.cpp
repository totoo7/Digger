#include "Game.hpp"

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
            return false;
    }
    window = SDL_CreateWindow("Digger Game",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            SCREEN_WIDTH,
                            SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        SDL_Log("Renderer could not be created! SDL_Error: %s", SDL_GetError());
        return false;
    }

    board = new Board(TILE_WIDTH, TILE_HEIGHT);
    board_renderer = new Renderer(renderer, TILE_WIDTH, TILE_HEIGHT);
    //! loading level
    ifstream ifs("../Level.txt");
    if (!ifs) {
        cerr << "Can't load level." << endl;
        return false;
    }

    int x = 0, y = 0;
    char tile_value;
    
    while (ifs.get(tile_value)) {
        if (tile_value == '\n') {
            x = 0;
            ++y;
            continue;
        }
        Tile& tile = board->get_tile(x, y);
        switch (tile_value) {
            case '0':
                // Empty
                tile = Tile(x, y, {0, 0, 0, 0});
                tile.is_dug = true;
                break;  
            case '1': // Regular tile (block)
                tile = Tile(x, y, {104, 72, 35, 1});
                tile.is_dug = false;
                break;
            case '2': // Player tile
                player = Player(x, y, TILE_WIDTH, TILE_HEIGHT, {149, 20, 121, 1});
                tile.has_entity = true;
                player_spawn_position.x = x;
                player_spawn_position.y = y;
                break;
            case '3': // Enemy tile
                enemies.push_back(Enemy(x, y, TILE_WIDTH, TILE_HEIGHT, {255, 0, 0, 1}));
                enemy_spawns.push_back({x, y});
                tile.has_entity = true;
                break;
            case '4': // Emerald tile
                collectibles.push_back(new Emerald(x, y, {0, 255, 0, 255}));
                tile.has_collectible = true;
                break;
            case '5': // Gold tile
                collectibles.push_back(new Gold(x, y, {255, 215, 0, 255}));
                tile.has_collectible = true;
                break;
            default:
                tile = Tile(x, y, {0, 0, 0, 255});
                break;
        }

        ++x;
    }
    ifs.close();
    //!
    enemy_count = enemies.size();
    is_running = true;
    return true;
}

bool Game::run() {
    while(is_running) {
        handle_events();
        update();
        render();
    }
    return is_running;
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    board_renderer->render_board(*board);
    board_renderer->render_collectibles(collectibles);
    board_renderer->render_enemies(enemies);
    board_renderer->render_player(player);
    SDL_RenderPresent(renderer);
}

void Game::handle_events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            is_running = false;
        }
        player.handle_input(event);
    }
}

void Game::respawn() {
    auto current_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_since_death(current_time - last_death_time);
    if (time_since_death.count() >= respawn_time) {
        player.set_position(player_spawn_position.x, player_spawn_position.y);
        for (size_t i = 0; i < enemies.size(); i++) {
            enemies[i].set_position(enemy_spawns[i].x, enemy_spawns[i].y);
            enemies[i].clear_path();
        }
    }
}

void Game::kill_enemy(size_t index) {
    std::swap(enemies[index], enemies[enemies.size()-1]);
    enemies.pop_back();
}

void Game::remove_collectible(size_t index) {
    std::swap(collectibles[index], collectibles[collectibles.size()-1]);
    collectibles.pop_back();
}

void Game::update() {
    if (player.get_lives() == 0) is_running = false;
    if (collectibles.empty()) is_running = false;
    if (enemies.size() < enemy_count) {
        int range = enemies.size() + 1;
        int num = rand() % range;
        enemies.push_back(Enemy(enemy_spawns[num].x, enemy_spawns[num].y, TILE_WIDTH, TILE_HEIGHT, {255, 0, 0, 1}));
    }
    player.update(*board);
    for (size_t i = 0; i < collectibles.size(); ++i) {
        if (collectibles[i]->get_position().x == player.get_position().x &&
            collectibles[i]->get_position().y == player.get_position().y) {
            if (dynamic_cast<Emerald*>(collectibles[i])) {
                remove_collectible(i);
                player.add_score();
                cout << player.get_score() << endl;
                break;
            } else if (!dynamic_cast<Gold*>(collectibles[i])->get_is_broken()) {
                for (size_t j = 0; j < enemies.size(); j++) {
                    if (collectibles[i]->get_position().x == enemies[j].get_position().x &&
                        collectibles[i]->get_position().y == enemies[j].get_position().y) {
                            kill_enemy(j);
                            break;
                    } else if (collectibles[i]->get_position().x == player.get_position().x &&
                                collectibles[i]->get_position().y == player.get_position().y)  {
                        player.death();
                        respawn();
                    }
                }
            } else if (dynamic_cast<Gold*>(collectibles[i])->get_is_broken()) {

            }
        }
        collectibles[i]->update(*board);
    }
    for (auto& enemy : enemies) {
        enemy.update(*board, get_player_position());
        if (enemy.get_position().x == player.get_position().x &&
            enemy.get_position().y == player.get_position().y) {
            player.death();
            respawn();
        }
    }
}

SDL_Point Game::get_player_position() {
    return player.get_position();
}

Game::~Game() {
    deallocate();
}

void Game::deallocate() {
    delete board;
    delete board_renderer;
    for (size_t i = 0; i < collectibles.size(); i++) {
        delete collectibles[i];
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}