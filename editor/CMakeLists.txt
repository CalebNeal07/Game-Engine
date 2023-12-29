cmake_minimum_required(VERSION 3.27)
project(PhantomEditor)

add_executable(PhantomEditor)

target_include_directories(PhantomEditor
        PUBLIC ${VULKAN_INCLUDE_DIRS}
)

target_sources(PhantomEditor
        PUBLIC main.cpp
)

target_link_libraries(PhantomEditor
        PRIVATE Vulkan::Vulkan
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        PRIVATE PhantomLib
)
