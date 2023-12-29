#include <PhantomEngine.hpp>

int main(int argc, char** argv) {
    PhantomEngine engine(
        VULKAN_2D,
        WindowConfig{
            "Vulkan 2D Test",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            1600, 900,
            false, false, false
        }
    );

    return EXIT_SUCCESS;
}
