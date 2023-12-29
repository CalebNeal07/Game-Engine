//
// Created by Caleb on 12/28/2023.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>

#include "graphics/renderer/Renderer.hpp"


enum PhantomRenderer {
    VULKAN_2D,
    VULKAN_MESH_SHADER,
    VULKAN_PATH_TRACER,
    VULKAN_RASTERIZER,
};

struct WindowConfig {
    const char* title;
    int x, y, height, width;
    bool fullscreen, minimized, maximized;
};

class PhantomEngine {
    SDL_Window *window;
    Renderer *renderer;
public:
    PhantomEngine(
        PhantomRenderer,
        const WindowConfig&
    );

    ~PhantomEngine();
};



#endif //ENGINE_HPP
