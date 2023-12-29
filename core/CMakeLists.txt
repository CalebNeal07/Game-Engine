cmake_minimum_required(VERSION 3.27)
project(GameLib)

add_library(GameLib STATIC
        graphics/renderer/direct3d/Direct3DRasterizedRenderer.cpp
        graphics/renderer/direct3d/Direct3DRasterizedRenderer.hpp
        graphics/renderer/direct3d/Direct3DRasterizedRenderer.hpp
        graphics/renderer/direct3d/Direct3DPathTracedRenderer.cpp
        graphics/renderer/direct3d/Direct3DPathTracedRenderer.hpp
        graphics/renderer/direct3d/DirectX2DRenderer.cpp
        graphics/renderer/direct3d/DirectX2DRenderer.hpp
        Engine.cpp
        Engine.hpp)


target_include_directories(GameLib
        PUBLIC ${VULKAN_INCLUDE_DIRS}
)

target_sources(GameLib
        PUBLIC graphics/renderer/Renderer.hpp
        PUBLIC graphics/camera/Camera.cpp
        PUBLIC graphics/camera/Camera.hpp
        PUBLIC graphics/renderer/vulkan/VulkanMeshShaderRenderer.cpp
        PUBLIC graphics/renderer/vulkan/VulkanMeshShaderRenderer.hpp
        PUBLIC graphics/renderer/vulkan/VulkanPathTracedRenderer.cpp
        PUBLIC graphics/renderer/vulkan/VulkanPathTracedRenderer.hpp
        PUBLIC graphics/renderer/vulkan/Vulkan2DRenderer.cpp
        PUBLIC graphics/renderer/vulkan/Vulkan2DRenderer.hpp
        PUBLIC graphics/renderer/vulkan/VulkanRasterizedRenderer.cpp
        PUBLIC graphics/renderer/vulkan/VulkanRasterizedRenderer.hpp
)

target_link_libraries(GameLib
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        PRIVATE Vulkan::Vulkan
)

add_library(GameLib::GameLib ALIAS GameLib)