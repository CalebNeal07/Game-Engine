//
// Created by Caleb on 12/28/2023.
//

#include "Vulkan2DRenderer.hpp"
#include "VulkanHandler.hpp"


Vulkan2DRenderer::Vulkan2DRenderer(SDL_Window* window, const char* title) {
    const auto vulkan_handler = VulkanHandler(window, title);
    this->vulkan = vulkan_handler.vk_instance;
    this->vk_surface = vulkan_handler.vk_surface;
}

Vulkan2DRenderer::~Vulkan2DRenderer() {
    vkDestroyInstance(this->vulkan, nullptr);
}

void Vulkan2DRenderer::render() {}



