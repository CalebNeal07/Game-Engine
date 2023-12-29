//
// Created by Caleb on 12/28/2023.
//

#include "PhantomEngine.hpp"

#include <SDL.h>
#include <SDL_vulkan.h>

#include "graphics/renderer/vulkan/Vulkan2DRenderer.hpp"
#include "graphics/renderer/vulkan/VulkanMeshShaderRenderer.hpp"
#include "graphics/renderer/vulkan/VulkanPathTracedRenderer.hpp"
#include "graphics/renderer/vulkan/VulkanRasterizedRenderer.hpp"

PhantomEngine::PhantomEngine(const PhantomRenderer renderer, const WindowConfig &window_config) {
    SDL_Init(SDL_INIT_EVERYTHING);

    Uint32 sdl_renderer_flag;
    switch (renderer) {
        case VULKAN_2D:
        case VULKAN_MESH_SHADER:
        case VULKAN_PATH_TRACER:
        case VULKAN_RASTERIZER:
            sdl_renderer_flag = SDL_WINDOW_VULKAN;
            break;
        default:
            sdl_renderer_flag = 0;
    }

    this->window = SDL_CreateWindow(
        window_config.title,
        window_config.x, window_config.y,
        window_config.width, window_config.height,
        sdl_renderer_flag
        | window_config.fullscreen ? SDL_WINDOW_FULLSCREEN : 0
        | window_config.maximized ? SDL_WINDOW_MAXIMIZED : 0
        | window_config.minimized ? SDL_WINDOW_MINIMIZED : 0
    );

    switch (renderer) {
        case VULKAN_2D:
            this->renderer = new Vulkan2DRenderer(this->window, window_config.title);
            break;
        case VULKAN_RASTERIZER:
            this->renderer = new VulkanRasterizedRenderer(this->window, window_config.title);
            break;
        case VULKAN_MESH_SHADER:
            this->renderer = new VulkanMeshShaderRenderer(this->window, window_config.title);
            break;
        case VULKAN_PATH_TRACER:
            this->renderer = new VulkanPathTracedRenderer(this->window, window_config.title);
    }
}

PhantomEngine::~PhantomEngine() {
    this->renderer.~Renderer();
    SDL_DestroyWindow(this->window);
}

