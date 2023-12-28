//
// Created by Caleb on 12/27/2023.
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vulkan/vulkan.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

class Renderer {
public:
    VkInstance vulkan{};
    VkSurfaceKHR vkSurface{};
    SDL_Window *window;

    Renderer();
    ~Renderer();


};



#endif //RENDERER_HPP
