//
// Created by Caleb on 12/28/2023.
//

#ifndef VULKANMESHSHADERRENDERER_HPP
#define VULKANMESHSHADERRENDERER_HPP
#include <SDL_video.h>

#include "graphics/renderer/Renderer.hpp"


class VulkanMeshShaderRenderer final : public Renderer {
public:
    VulkanMeshShaderRenderer(SDL_Window*, const char*);
    ~VulkanMeshShaderRenderer() override;
    void render() override;
};



#endif //VULKANMESHSHADERRENDERER_HPP
