#include "Platform/Windows/Windows_Window.h"
#include "Core/Renderer.h"
#ifdef RENDER_API_VULKAN
#include "Vulkan/VulkanContext.h
#elif defined(RENDER_API_OPENGL)
#include "OpenGL/OpenGL_Context.h"
#endif


Windows_Window::Windows_Window(const char* title, uint32_t width, uint32_t height)
{
	m_Title = title;
	m_Width = width;
	m_Height = height;
}

Windows_Window::~Windows_Window()
{
}

void Windows_Window::Init(const std::string& glslVersion)
{
	if (GLFW_Initialized)
		return;

	glfwInit();

	Renderer::API renderAPI = Renderer::GetAPI();
	if (renderAPI == Renderer::API::Vulkan)
	{
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	}
	else if (renderAPI == Renderer::API::OpenGL)
	{
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Set core profile
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Major version
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Minor version
	}

	m_GlfwWindow = glfwCreateWindow((int)m_Width, (int)m_Height, m_Title.c_str(), nullptr, nullptr);
	ASSERT(m_GlfwWindow);
	glfwMakeContextCurrent(m_GlfwWindow);

	if (!GLFW_Initialized)
	{
		m_GraphicsContext = GraphicsContext::Create(this);
		m_GraphicsContext->Init(glslVersion);
		m_Renderer = Renderer::Create(glslVersion);
		m_Renderer->Init();
		m_GraphicsContext->SetDarkTheme();
	}

	SetVSync(true);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if (glfwRawMouseMotionSupported())
		glfwSetInputMode(m_GlfwWindow, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
	glfwSetWindowAttrib(m_GlfwWindow, GLFW_FOCUSED, GL_TRUE);
	glfwSetInputMode(m_GlfwWindow, GLFW_STICKY_KEYS, GLFW_TRUE);
	glfwSetInputMode(m_GlfwWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	GLFW_Initialized = true;
}

void Windows_Window::Exit()
{
	m_GraphicsContext->Destroy();
	glfwDestroyWindow(m_GlfwWindow);
	glfwTerminate();
}

void Windows_Window::OnUpdate()
{
}

void Windows_Window::Clear()
{
	m_Renderer->Clear();
}

void Windows_Window::BeginFrame()
{
	m_Renderer->Clear();
	m_Renderer->BeginFrame();
}

void Windows_Window::EndFrame()
{
	m_Renderer->EndFrame();
	m_GraphicsContext->SwapBuffers();
	glfwPollEvents();
}

void Windows_Window::SetVSync(bool enabled)
{
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);
	m_VSync = enabled;
}

bool Windows_Window::IsVSync() const
{
	return m_VSync;
}
