add_library(HollowEngine
    Core/Application.cpp
)


target_include_directories(HollowEngine
    PUBLIC
        ${CMAKE_SOURCE_DIR}/src
)

target_compile_features(HollowEngine PUBLIC cxx_std_23)
