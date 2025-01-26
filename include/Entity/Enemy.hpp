#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include "Vector/Vector.hpp"
#include "Queue/CircularQueue.hpp"
#include <chrono>

/**
 * @brief Represents an enemy in the game.
 * 
 * The Enemy class extends the Entity class and implements behavior such as pathfinding
 * to chase the player using Breadth-First Search (BFS) for shortest path calculation.
 */
class Enemy : public Entity {
    public:
        /**
         * @brief Default constructor for Enemy.
         * 
         * Initializes an Enemy instance with default values.
         */
        Enemy() = default;
        /**
         * @brief Constructs an Enemy with specified attributes.
         * 
         * @param x The x-coordinate of the enemy.
         * @param y The y-coordinate of the enemy.
         * @param w The width of the enemy.
         * @param h The height of the enemy.
         * @param c The color of the enemy, represented as an SDL_Color.
         */
        Enemy(int x, int y, int w, int h, SDL_Color c);
        /**
         * @brief Updates the enemy's position and state.
         * 
         * This method updates the enemy's position by calculating the shortest
         * path to the player and moving accordingly.
         * 
         * @param board The game board to interact with.
         * @param player_position The current position of the player.
         */
        void update(Board& board, SDL_Point player_position);
        /**
         * @brief Moves the enemy towards the player's position.
         * 
         * This method utilizes the precomputed path (if available) or recalculates
         * a new path using BFS if necessary. It ensures smooth movement and updates
         * the enemy's position at fixed intervals.
         * 
         * @param board The game board to interact with.
         * @param player The current position of the player.
         */
        void move(Board& board, SDL_Point player);
        /**
         * @brief Clears the current path of the enemy.
         * 
         * Removes all saved steps in the enemy's path, typically used after respawning
         * or when the path is no longer valid.
         */
        void clear_path();
    private:
        /**
         * @brief Implements Breadth-First Search (BFS) to find the shortest path.
         * 
         * BFS is used to calculate the shortest path from the enemy's current position
         * to a target position (e.g., the player) on a grid-based board. It is well-suited
         * for unweighted grids where all moves (up, down, left, right) have the same cost.
         * 
         * Why BFS?
         * - **Optimal for Unweighted Grids**: BFS guarantees the shortest path in scenarios
         *   where all moves have equal cost. This makes it an excellent choice for grid-based
         *   games like this one, where the movement cost from one tile to another is uniform.
         * - **Simplicity**: BFS is straightforward to implement, requiring only a queue and
         *   auxiliary data structures like `visited` and `parent` matrices.
         * - **Efficiency**: BFS processes each tile at most once, making it efficient for
         *   relatively small grids (like the 15x15 game board used here). It ensures
         *   predictable behavior and performance.
         * 
         * Why not other algorithms?
         * - **Dijkstra's Algorithm**: While it can also find the shortest path, it is more
         *   computationally intensive due to the use of a priority queue. This added complexity
         *   is unnecessary for unweighted grids where BFS is sufficient.
         * - **Depth-First Search (DFS)**: DFS is not suitable for shortest path problems as
         *   it explores paths in depth-first order, often leading to suboptimal solutions.
         * 
         * How it works:
         * - The method uses a queue to traverse tiles level by level (breadth-first).
         * - It tracks visited tiles to avoid redundant processing and loops.
         * - For each tile, it records its parent, enabling backtracking to reconstruct
         *   the path once the target is reached.
         * 
         * @param board The game board used for pathfinding.
         * @param position The starting position for the BFS algorithm.
         * @param target The target position to reach.
         * @return A Vector of SDL_Point representing the shortest path, starting
         *         from the current position to the target.
         */
        Vector<SDL_Point> BFS(Board& board, SDL_Point position, SDL_Point target);
    private:
        Vector<SDL_Point> path; /**< Stores the path from the enemy's position to the target. */
        chrono::time_point< chrono::high_resolution_clock > last_update_time = chrono::high_resolution_clock::now(); /**< Timestamp for the last movement update. */
        size_t current_path_index = 0; /**< The index of the current step in the path being followed. */
};

#endif