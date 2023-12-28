cmake_minimum_required(VERSION 3.27)
project(Game_Engine)

set(CMAKE_CXX_STANDARD 17)

find_package (Vulkan REQUIRED)

add_executable(Game_Engine
        main.cpp
        Renderer.cpp
        Renderer.hpp
)

target_include_directories (Game_Engine
    PUBLIC ${VULKAN_INCLUDE_DIRS}
)

target_link_libraries (Game_Engine Vulkan::Vulkan SDL2)