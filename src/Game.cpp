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
                break;
            case '3': // Enemy tile
                enemies.push_back(Enemy(x, y, TILE_WIDTH, TILE_HEIGHT, {255, 0, 0, 1}));
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

void Game::update() {
    player.update(*board);
    for (auto& enemy : enemies) {
        enemy.update(*board, get_player_position());
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