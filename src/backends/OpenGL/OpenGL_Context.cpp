#include "backends/OpenGL/OpenGL_Context.h"
#include "Window.h"


OpenGL_Context::OpenGL_Context(void* _window)
{
    Window* window = static_cast<Window*>(_window);
    m_Window = std::shared_ptr<Window>(window);
}

void OpenGL_Context::Init(const std::string& glslVersion)
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
		printf("OpenGL_Context attached to window with title: %s\n", m_Window->GetTitle().c_str());
	}

	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	InitImGui(glslVersion);
}

void OpenGL_Context::Destroy()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void OpenGL_Context::SwapBuffers()
{
	glfwSwapBuffers(m_Window->GetGLFWWindow());
}

void OpenGL_Context::InitImGui(const std::string& glslVersion)
{
    ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
	// io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport
	io.Fonts->AddFontFromFileTTF("assets/fonts/SourceCodePro/SourceSansProSemibold.ttf", 20);
    ImGui_ImplGlfw_InitForOpenGL(m_Window->GetGLFWWindow(), true);
    ImGui_ImplOpenGL3_Init(glslVersion.c_str());
}

