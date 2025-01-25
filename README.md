# Digger Game

A classic Digger-style game built with SDL. The player navigates a 2D grid, collecting emeralds and gold while avoiding enemies and digging paths through tiles. The game features a respawn system, collectibles, and enemy AI with pathfinding.


**Note**: This game is currently a work in progress and not yet fully finished. Some features are still under development, and there may be bugs or incomplete mechanics.


## Installation

#### Prerequisites

C++ Compiler: Ensure you have a C++11 (or later) compatible compiler.

SDL2: The game uses SDL2 for rendering and input handling.

CMake: The game uses CMake for building.

### Build Instructions

#### Clone the repository
git clone --recurse-submodules https://github.com/totoo7/Digger.git

cd Digger

#### Create a build directory
mkdir build

cd build

#### Run CMake to configure the project
cmake -S .. -B .

#### Build the project

cmake --build .

#### Run 

./Digger
