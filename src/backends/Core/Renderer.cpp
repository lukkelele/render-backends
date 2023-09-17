#include "Renderer.h"

#ifdef RENDER_API_VULKAN
    #include "backends/Vulkan/VulkanRenderer.h"
    Renderer::API Renderer::m_API = API::Vulkan;
#elif defined(RENDER_API_OPENGL)
    #include "backends/OpenGL/OpenGL_Renderer.h" 
    Renderer::API Renderer::m_API = API::OpenGL;
#else
    Renderer::API Renderer::m_API = API::None;
#endif
std::string Renderer::m_GlslVersion = "";
Renderer* Renderer::m_Instance = nullptr;


std::shared_ptr<Renderer> Renderer::Create(const std::string& glslVersion)
{
    m_GlslVersion = glslVersion;
#ifdef RENDERER_API_VULKAN
    return std::make_shared<VulkanRenderer>(glslVersion);
#else 
    return std::make_shared<OpenGL_Renderer>(glslVersion);
#endif
}

void Renderer::Draw(std::shared_ptr<Image> image)
{
    auto renderer = Instance();
    Image* image_ptr = &(*image);
    renderer->DrawImage(image_ptr);
}

void Renderer::Draw(Image* image)
{
    auto renderer = Instance();
    renderer->DrawImage(image);
}
