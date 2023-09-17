#include <iostream>
#include "backends/Core/Window.h" 


int main()
{
    std::cout << "Hello World!" << std::endl;

    std::shared_ptr<Window> window = Window::Create("Window", 1440, 1080);
    GLFWwindow* glfwWindow = window->GetGLFWWindow();

    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(glfwWindow))
    {
        glClearColor(0.0f, 1.0f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Main Window");
        ImGui::Text("Lukas wrote this");
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(glfwWindow);
        glfwPollEvents();
    }

    return 0;
}