#include <SDL2/SDL.h>

#include <graphics/renderer/vulkan/Vulkan2DRenderer.hpp>

int main(int argv, char** args) {
    SDL_Init(SDL_INIT_EVERYTHING);

    auto renderer = Vulkan2DRenderer(
        RendererConfig{
            "Vulkan Test",
            855, 1520,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            false, true
        }
    );

    return EXIT_SUCCESS;
}
