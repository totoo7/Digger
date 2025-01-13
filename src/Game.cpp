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
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Renderer could not be created! SDL_Error: %s", SDL_GetError());
        return false;
    }

    board = new Board(TILE_WIDTH, TILE_HEIGHT);
    board_renderer = new Renderer(renderer, TILE_WIDTH, TILE_HEIGHT);

    is_running = true;
    return true;
}

void Game::run() {
    while(is_running) {
        handle_events();
        update();
        render();
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    board_renderer->render_board(*board);

    SDL_RenderPresent(renderer);
}

void Game::handle_events() {
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        is_running = false;
    } else if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                cout << "up";
                break;
            case SDLK_DOWN:
                cout << "down";
                break;
            case SDLK_LEFT:
                cout << "left";
                break;
            case SDLK_RIGHT:
                cout << "right";
                break;
        }
    }
}

void Game::update() {
}

Game::~Game() {
    deallocate();
}

void Game::deallocate() {
    delete board;
    delete board_renderer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}