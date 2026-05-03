file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(HollowEngine SHARED
    ${ENGINE_SOURCES}
    ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c
)

target_include_directories(HollowEngine PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/external/glad/include
    ${CMAKE_SOURCE_DIR}/external/bgfx/include
    ${CMAKE_SOURCE_DIR}/external/bx/include
    ${CMAKE_SOURCE_DIR}/external/bimg/include
)

target_compile_features(HollowEngine PUBLIC cxx_std_23)

find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(HollowEngine PRIVATE
    glfw
    glm::glm
    ${CMAKE_SOURCE_DIR}/external/bgfx/.build/linux64_clang/bin/libbgfxRelease.a
    pthread
    dl
)

target_compile_definitions(HollowEngine
    PUBLIC
        GLM_FORCE_RADIANS
        GLM_FORCE_DEPTH_ZERO_TO_ONE
    PRIVATE
        HOLLOW_BUILD_DLL
)
