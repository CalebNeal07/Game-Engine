//
// Created by Caleb on 12/28/2023.
//

#ifndef VULKANPATHTRACEDRENDERER_HPP
#define VULKANPATHTRACEDRENDERER_HPP
#include <SDL_video.h>

#include "graphics/renderer/Renderer.hpp"


class VulkanPathTracedRenderer final : public Renderer {
public:
    VulkanPathTracedRenderer(SDL_Window*, const char*);
    ~VulkanPathTracedRenderer() override;
    void render() override;
};



#endif //VULKANPATHTRACEDRENDERER_HPP
