#include "GraphicsContext.h"

#ifdef RENDER_API_VULKAN
#include "VulkanContext.h"
#elif defined(RENDER_API_OPENGL)
#include "OpenGLContext.h"
#endif


std::shared_ptr<GraphicsContext> GraphicsContext::Create(void* window)
{
#ifdef RENDER_API_VULKAN
    return std::make_shared<VulkanContext>(window);
#elif defined(RENDER_API_OPENGL)
    return std::make_shared<OpenGLContext>(window);
#else
    return nullptr;
#endif
}
