add_library(imgui STATIC 
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
)
target_include_directories(imgui PUBLIC imgui)

add_subdirectory(glfw)
target_link_libraries(glfw PRIVATE 
    imgui
)

add_library(impl STATIC 
    imgui/backends/imgui_impl_glfw.h
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.h
    imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(impl PUBLIC imgui/backends/)
target_link_libraries(impl PUBLIC
    imgui
    glfw
)
