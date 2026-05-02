file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(HollowEngine SHARED
    ${ENGINE_SOURCES}
    ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c
)

target_include_directories(HollowEngine
    PUBLIC
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/external/glad/include
)

target_compile_features(HollowEngine PUBLIC cxx_std_23)

find_package(glfw3 REQUIRED)

target_link_libraries(HollowEngine PRIVATE glfw)

find_program(CLANG_TIDY_EXE NAMES clang-tidy)

if(CLANG_TIDY_EXE)
    message(STATUS "clang-tidy (Engine): ${CLANG_TIDY_EXE}")

    set_target_properties(HollowEngine PROPERTIES
        CXX_CLANG_TIDY
        "${CLANG_TIDY_EXE};-header-filter=src/.*;-extra-arg=-std=c++23"
    )
endif()

target_compile_definitions(HollowEngine PRIVATE HOLLOW_BUILD_DLL)

message(STATUS "HollowEngine sources: ${ENGINE_SOURCES}")