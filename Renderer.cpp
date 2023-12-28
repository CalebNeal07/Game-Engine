//
// Created by Caleb on 12/27/2023.
//

#include "Renderer.hpp"

Renderer::Renderer() {
    window = SDL_CreateWindow(
        "Vulkan Game Engine",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1520, 855,
        SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS
    );

    // Vulkan Initialization
    VkInstanceCreateInfo instance_create_info{};

    instance_create_info.enabledExtensionCount =

    if (vkCreateInstance(&instance_create_info, nullptr, &this->vulkan) != VK_SUCCESS) {

    }

    SDL_Vulkan_CreateSurface(this->window, this->vulkan, &this->vkSurface);
}

Renderer::~Renderer() {
    vkDestroyInstance(this->vulkan, nullptr);
}
