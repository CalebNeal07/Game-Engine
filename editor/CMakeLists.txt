cmake_minimum_required(VERSION 3.27)
project(GameEditor)

add_executable(GameEditor)

target_include_directories(GameEditor
        PUBLIC ${VULKAN_INCLUDE_DIRS}
        ../core
)

target_sources(GameEditor
        PUBLIC main.cpp
)

target_link_libraries(GameEditor
        PRIVATE Vulkan::Vulkan
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        PRIVATE GameLib
)
