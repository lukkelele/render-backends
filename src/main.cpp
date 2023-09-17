#include <iostream>
#include "backends/Core/Window.h" 


int main()
{
    std::shared_ptr<Window> window = Window::Create("Render Backends Window", 1440, 1080);
    window->Init(DEFAULT_GLSL_VERSION);
    GLFWwindow* glfwWindow = window->GetGLFWWindow();

    while (!glfwWindowShouldClose(glfwWindow))
    {
        window->BeginFrame();

        ImGui::Begin("Main Window", (bool*)true, ImGuiWindowFlags_MenuBar);
        ImGui::Text("Lukas wrote this");
        ImGui::End();

        window->EndFrame();
    }
    window->Exit();

    return 0;
}