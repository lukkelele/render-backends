#include <iostream>
#include "Base/Window.h" 


int main()
{
    std::cout << "Hello World!" << std::endl;

    Window* window = Window::Create("Window", 1440, 1080);

	// Windows_Window* window = new Windows_Window("Window", 1440, 1080);
    GLFWwindow* glfwWindow = window->GetGLFWWindow();

    while (!glfwWindowShouldClose(glfwWindow))
    {
        glClearColor(0.0f, 1.0f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw calls

        glfwSwapBuffers(glfwWindow);
        glfwPollEvents();
    }

    return 0;
}