#include "imgui.h"
#include "imgui_demo.cpp"

#include "render.hpp"

void render() {
    // allows window docking in the main window
    ImGui::DockSpaceOverViewport();

    // Create a window instance
    ImGui::Begin("Demo window", nullptr, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoDecoration);
    ImGui::SetWindowPos({0.f, 0.f});
    
    // This represents the txt buffer for now (read/write buffer, create new buffer if nothing to read/write from?)
    static char text[1024 * 16] ="Welcome to Spark. The thaddiest text editor you have ever come across.";

    /* Create a multi-line text input widget in our current window instance
    * 2nd arg is the text buffer
    * 3rd arg is sizeof entire buffer based off sizeof(char) / sizeof(*(char))
    * 4th arg is the dimensions of the widget
    * 5th arg is just different flags you can set for the widget
    * 
    * I think we can use this info to set up a txt file buffer to be able to read/write from/into?
    * Lemme know what you think.
    */
    ImGui::InputTextMultiline("our source of text", text, IM_ARRAYSIZE(text), ImVec2(600, 720), ImGuiInputTextFlags_AllowTabInput);
    
    ImGui::End();

    // ImGui::ShowDemoWindow();
}
