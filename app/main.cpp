#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_opengl3_loader.h"

#include "GLFW/glfw3.h"

#include <cstdio>

#include "cycle.hpp"
#include "render.hpp"

static void glfw_error_callback(int error, const char* description);

int main(int, char**) {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    auto* window{glfwCreateWindow(WindowWidth, WindowHeight, "Spark", nullptr, nullptr)};
    if (window == nullptr) {
        return 1;
    }
    glfwMakeContextCurrent(window);
    // Enable vsync
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    auto& io{ImGui::GetIO()};
    io.ConfigFlags = ImGuiConfigFlags_DockingEnable;

    // Spark code called here
    while (!glfwWindowShouldClose(window)) {
        start_cycle();

        ImGui::NewFrame();
        render();
        ImGui::Render();

        end_cycle(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}
