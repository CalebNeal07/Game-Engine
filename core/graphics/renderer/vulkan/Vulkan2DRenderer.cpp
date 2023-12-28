//
// Created by Caleb on 12/28/2023.
//

#include "Vulkan2DRenderer.hpp"

#include <SDL2/SDL_vulkan.h>

Vulkan2DRenderer::Vulkan2DRenderer(const RendererConfig &config) {
    this->window = SDL_CreateWindow(
        config.window_title,
        config.window_x, config.window_y,
        config.window_width, config.window_height,
        SDL_WINDOW_VULKAN
        | config.fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_VULKAN
        | config.resizable ? SDL_WINDOW_RESIZABLE : SDL_WINDOW_VULKAN
    );

    VkInstanceCreateInfo create_info{};

    if (vkCreateInstance(&create_info, nullptr, &this->vulkan) != VK_SUCCESS) {
        throw std::runtime_error("Failed to instantiate Vulkan");
    }

    SDL_Vulkan_CreateSurface(
       this->window, this->vulkan, &this->vk_surface
    );
}

Vulkan2DRenderer::~Vulkan2DRenderer() {
    vkDestroyInstance(this->vulkan, nullptr);
    SDL_DestroyWindow(this->window);
}

void Vulkan2DRenderer::render() {}



