#include <SDL2/SDL.h>

#include "Renderer.hpp"

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    const auto renderer = new Renderer(); // Initializes Vulkan and opens the window

    bool close = false;
    while (!close) {
        // Game Loop goes here
        close = true;
    }

    renderer->~Renderer(); // Explicitly close renderer
    return EXIT_SUCCESS;
}
