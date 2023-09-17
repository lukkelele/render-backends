#include <iostream>
#include "backends/Core/Window.h" 


int main()
{
    std::shared_ptr<Window> window = Window::Create("Render Backends Window", 1440, 1080);
    GLFWwindow* glfwWindow = window->GetGLFWWindow();

    while (!glfwWindowShouldClose(glfwWindow))
    {
        window->BeginFrame();

        ImGui::Begin("Main Window");
        ImGui::Text("Lukas wrote this");
        ImGui::End();

        window->EndFrame();
    }

    return 0;
}