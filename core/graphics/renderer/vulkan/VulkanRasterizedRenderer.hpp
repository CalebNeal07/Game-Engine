//
// Created by Caleb on 12/28/2023.
//

#ifndef VULKANCLASSICALRENDERER_HPP
#define VULKANCLASSICALRENDERER_HPP
#include <SDL_video.h>

#include "graphics/renderer/Renderer.hpp"


class VulkanRasterizedRenderer final : public Renderer {
public:
    VulkanRasterizedRenderer(SDL_Window*, const char*);
    ~VulkanRasterizedRenderer() override;
    void render() override;
};



#endif //VULKANCLASSICALRENDERER_HPP
