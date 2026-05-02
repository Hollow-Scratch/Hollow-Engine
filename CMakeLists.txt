cmake_minimum_required(VERSION 3.20)
project(HollowEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_compile_options(
    -fcolor-diagnostics
    -fdiagnostics-color=always
    -fdiagnostics-show-option
)

add_subdirectory(src/Engine)
add_subdirectory(Sandbox)