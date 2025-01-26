#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

/**
 * @brief Represents the player character in the game.
 * 
 * The Player class extends the Entity class and provides additional functionality
 * specific to the player, such as handling input, scoring, and tracking lives.
 */
class Player : public Entity {
    public:
        /**
         * @brief Default constructor for Player.
         * 
         * Initializes the player with default values.
         */
        Player() = default;
        /**
         * @brief Constructs a Player with specified parameters.
         * 
         * @param x The x-coordinate of the player.
         * @param y The y-coordinate of the player.
         * @param w The width of the player.
         * @param h The height of the player.
         * @param color The color of the player represented as an SDL_Color.
         */
        Player(int x, int y, int w, int, SDL_Color color);
        /**
         * @brief Moves the player on the game board.
         * 
         * Overrides the base class move method to implement player-specific
         * movement logic, such as digging tiles.
         * 
         * @param board The game board used to check movement constraints.
         */
        void move(Board& board) override;
        /**
         * @brief Handles input events for the player.
         * 
         * Processes SDL input events (e.g., keyboard presses) to control the
         * player's movement and actions.
         * 
         * @param event The SDL_Event containing input data.
         */
        void handle_input(const SDL_Event& event);
        /**
         * @brief Updates the player's state.
         * 
         * Currently this method's only responisbility is updating the movement.
         * 
         * @param board The game board used for interactions.
         */
        void update(Board& board);
        /**
         * @brief Gets the player's current score.
         * 
         * @return The current score of the player.
         */
        int get_score() const { return score; };
        /**
         * @brief Increases the player's score.
         * 
         * Adds 50 points to the player's score.
         */
        void add_score() { score += 50; };
        /**
         * @brief Decreases the player's lives upon death.
         * 
         * Reduces the number of lives the player has left by one.
         */
        void death() { lives--; };
        /**
         * @brief Gets the player's remaining lives.
         * 
         * @return The number of lives the player has left.
         */
        int get_lives() const { return lives; };
    private:
        int lives = 3; /**< The number of lives the player has. */
        int score = 0; /**< The player's current score. */
};

#endif