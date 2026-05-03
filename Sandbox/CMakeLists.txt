add_executable(Sandbox Sandbox.cpp)

target_link_libraries(Sandbox
    PRIVATE HollowEngine
    glfw #for now, 
)
