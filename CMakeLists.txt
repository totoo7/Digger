cmake_minimum_required(VERSION 3.5.0)
project(Digger VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(libs/Data-Structures)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Data-Structures)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libs/Data-Structures/include)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)