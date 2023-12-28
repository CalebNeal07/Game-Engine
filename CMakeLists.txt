cmake_minimum_required(VERSION 3.27)
project(Game_Engine)

set(CMAKE_CXX_STANDARD 17)

find_package (Vulkan REQUIRED)

add_library(Game_Lib STATIC
        core/graphics/renderer/Renderer.hpp
        core/graphics/camera/Camera.cpp
        core/graphics/camera/Camera.hpp
        core/graphics/renderer/vulkan/VulkanMeshShaderRenderer.cpp
        core/graphics/renderer/vulkan/VulkanMeshShaderRenderer.hpp
        core/graphics/renderer/vulkan/VulkanPathTracedRenderer.cpp
        core/graphics/renderer/vulkan/VulkanPathTracedRenderer.hpp
        core/graphics/renderer/vulkan/Vulkan2DRenderer.cpp
        core/graphics/renderer/vulkan/Vulkan2DRenderer.hpp
        core/graphics/renderer/vulkan/VulkanClassicalRenderer.cpp
        core/graphics/renderer/vulkan/VulkanClassicalRenderer.hpp
)

add_executable(Game_Editor
        editor/main.cpp
)

target_include_directories(Game_Lib
    PUBLIC ${VULKAN_INCLUDE_DIRS}
)

target_include_directories (Game_Editor
    PUBLIC ${VULKAN_INCLUDE_DIRS}
)

target_link_libraries(Game_Lib Vulkan::Vulkan SDL2)
target_link_libraries(Game_Editor Vulkan::Vulkan SDL2 Game_Lib)

add_library()