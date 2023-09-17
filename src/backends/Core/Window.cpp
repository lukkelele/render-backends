#include "Window.h"

#include "Platform/Windows/Windows_Window.h"

bool Window::GLFW_Initialized = false;

std::shared_ptr<Window> Window::Create(const char* title, uint32_t width, uint32_t height)
{
#ifdef PLATFORM_WINDOWS
	// Windows_Window* window = new Windows_Window(title, width, height);
	std::shared_ptr<Window> window = std::make_shared<Windows_Window>(title, width, height);
	return window;
#else PLATFORM_LINUX
	// Window_Linux* window = new Window_Linux(title, width, height);
	std::shared_ptr<Window> window = std::make_shared<Linux_Window>(title, width, height);
	return window;
#endif
}

void Window::BeginFrame()
{
	// ImGui_ImplOpenGL3_NewFrame();
	// ImGui_ImplGlfw_NewFrame();
	// ImGui::NewFrame();
	// ImGuizmo::BeginFrame();
	// StartViewportDocking();
}

void Window::EndFrame()
{
	// EndViewportDocking();                         
	// ImGuiIO& io = ImGui::GetIO();
	// io.DisplaySize = ImVec2((float)window->Width, (float)window->Height);
	// ImGui::Render();
	// ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	// if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	// {
	// 	auto currentContext = glfwGetCurrentContext();
	// 	ImGui::UpdatePlatformWindows();
	// 	ImGui::RenderPlatformWindowsDefault();  // Multi-Viewport
	// 	glfwMakeContextCurrent(currentContext);
	// }
	// // ImGui::EndFrame();
}


#ifdef RENDER_API_OPENGL
void OpenGL_ClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool OpenGL_LogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ")"
			<< "\nFile: " << file
			<< "\nFunction: " << function
			<< "\nLine: " << line << std::endl;
		return false;
	}
	return true;
}
#endif // RENDER_API_OPENGL
