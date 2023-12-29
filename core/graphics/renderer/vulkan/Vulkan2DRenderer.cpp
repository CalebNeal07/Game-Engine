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
        | config.fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_VULKAN // Vulkan flag doesn't affect window state
        | config.resizable ? SDL_WINDOW_RESIZABLE : SDL_WINDOW_VULKAN   // because it is already active.
    );

    unsigned int extensionCount = 0;
    SDL_Vulkan_GetInstanceExtensions(window, &extensionCount, nullptr);
    std::vector<const char *> extensionNames(extensionCount);
    SDL_Vulkan_GetInstanceExtensions(window, &extensionCount, extensionNames.data());

    const std::vector<const char*> validation_layers = {
#ifdef _DEBUG
        //"VK_LAYER_LUNARG_standard_validation"
#endif // _DEBUG
    };

    VkApplicationInfo application_info{};

    application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.pApplicationName = "Vulkan Test";
    application_info.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
    application_info.pEngineName = "No Engine";
    application_info.engineVersion = VK_MAKE_VERSION(0, 0, 1);
    application_info.apiVersion = VK_API_VERSION_1_3;

    VkInstanceCreateInfo create_info{};

    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pApplicationInfo = &application_info;
    create_info.enabledLayerCount = validation_layers.size();
    create_info.ppEnabledLayerNames = validation_layers.data();
    create_info.enabledExtensionCount = extensionNames.size();
    create_info.ppEnabledExtensionNames = extensionNames.data();

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



