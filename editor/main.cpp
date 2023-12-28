#include <SDL2/SDL.h>

#include <>

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);

    auto renderer = Vulkan2DRenderer(
        RendererConfig{
            "Vulkan Test",
            855, 1520,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            true, true
        }
    );

    uint64_t i = 1;
    while (i != 0) {
        i++;
    }

    return EXIT_SUCCESS;
}
