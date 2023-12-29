cmake_minimum_required(VERSION 3.27)
project(GameLib)

add_library(PhantomLib STATIC)


target_include_directories(PhantomLib
        PUBLIC .
        PUBLIC ${VULKAN_INCLUDE_DIRS}
)

target_sources(PhantomLib
        PUBLIC graphics/renderer/direct3d/Direct3DRasterizedRenderer.cpp
        PUBLIC graphics/renderer/direct3d/Direct3DRasterizedRenderer.hpp
        PUBLIC graphics/renderer/direct3d/Direct3DRasterizedRenderer.hpp
        PUBLIC graphics/renderer/direct3d/Direct3DPathTracedRenderer.cpp
        PUBLIC graphics/renderer/direct3d/Direct3DPathTracedRenderer.hpp
        PUBLIC graphics/renderer/direct3d/DirectX2DRenderer.cpp
        PUBLIC graphics/renderer/direct3d/DirectX2DRenderer.hpp
        PUBLIC PhantomEngine.cpp
        PUBLIC PhantomEngine.hpp
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
        PUBLIC graphics/renderer/vulkan/VulkanHandler.hpp
)

target_link_libraries(PhantomLib
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        PRIVATE Vulkan::Vulkan
)

add_library(PhantomLib::PhantomLib ALIAS PhantomLib)