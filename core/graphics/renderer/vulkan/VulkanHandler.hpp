//
// Created by Caleb on 12/29/2023.
//

#ifndef VULKANHANDLER_HPP
#define VULKANHANDLER_HPP

#include <stdexcept>
#include <vulkan/vulkan.h>
#include <SDL2/SDL_vulkan.h>
#include <vector>


class VulkanHandler {
public:
    VkInstance vk_instance;
    VkSurfaceKHR vk_surface;
    VkPhysicalDevice vk_physical_device;

    VulkanHandler(SDL_Window *window, const char* title) {
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
        application_info.pApplicationName = title;
        application_info.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
        application_info.pEngineName = "Phantom Engine";
        application_info.engineVersion = VK_MAKE_VERSION(0, 0, 1);
        application_info.apiVersion = VK_API_VERSION_1_3;

        VkInstanceCreateInfo create_info{};

        create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        create_info.pApplicationInfo = &application_info;
        create_info.enabledLayerCount = validation_layers.size();
        create_info.ppEnabledLayerNames = validation_layers.data();
        create_info.enabledExtensionCount = extensionNames.size();
        create_info.ppEnabledExtensionNames = extensionNames.data();

        if (vkCreateInstance(&create_info, nullptr, &this->vk_instance) != VK_SUCCESS) {
            throw std::runtime_error("Failed to instantiate Vulkan");
        }

        SDL_Vulkan_CreateSurface(
           window, this->vk_instance, &this->vk_surface
        );

        //TODO: Add physical device selection
    }
};



#endif //VULKANHANDLER_HPP
