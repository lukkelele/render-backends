#include "RendererAPI.h"
#include "Renderer.h"

#ifdef RENDER_API_VULKAN
    #include "backends/Vulkan/VulkanRenderer.h"
    Renderer::API Renderer::m_API = API::Vulkan;
#elif defined(RENDER_API_OPENGL)
    #include "backends/OpenGL/OpenGLRenderer.h" // to be impl
    Renderer::API Renderer::m_API = API::OpenGL;
#else
    Renderer::API Renderer::m_API = API::None;
#endif


std::shared_ptr<RendererAPI> RendererAPI::Create(const std::string& glslVersion)
{
#ifdef RENDERER_API_VULKAN
    return std::make_shared<VulkanRenderer>();
#else 
    return std::make_shared<OpenGLRenderer>();
#endif
}
