cmake_minimum_required(VERSION 3.5.0)
project(Digger VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(libs/Data-Structures)

find_package(SDL2 REQUIRED)

set (sources
    main.cpp
    src/Tile.cpp
    src/Board.cpp
    src/Renderer.cpp
    src/Game.cpp
    src/Collectible/Collectible.cpp
    src/Collectible/Emerald.cpp
    src/Collectible/Gold.cpp
    src/Entity/Entity.cpp
    src/Entity/Enemy.cpp
    src/Entity/Player.cpp
)

add_executable(${PROJECT_NAME} ${sources})

list(APPEND includePath
    "include"
    "include/Collectible"
    "include/Entity"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${includePath})

target_link_libraries(${PROJECT_NAME} PRIVATE Data-Structures)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libs/Data-Structures/include)

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)