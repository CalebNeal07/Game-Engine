cmake_minimum_required(VERSION 3.27)
project(Game_Engine)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

add_subdirectory("core")
add_subdirectory("editor")
