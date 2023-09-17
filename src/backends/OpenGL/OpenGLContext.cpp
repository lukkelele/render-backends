#include "OpenGLContext.h"
// temporary
#include <iostream>
#include "Window.h"


OpenGLContext::OpenGLContext(void* _window)
{
    Window* window = static_cast<Window*>(_window);
    m_Window = std::shared_ptr<Window>(window);
}

void OpenGLContext::Init()
{
	GLenum err = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	if (err == 0)
	{
		printf("[ERROR] Error starting GLAD");
		return;
	}
	else
	{
		printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
		// GLFW_Initialized = true;
		std::cout << "OpenGLContext attached to window with title: " << m_Window->GetTitle() << std::endl;
	}

	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGLContext::Destroy()
{
}

void OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_Window->GetGLFWWindow());
}

