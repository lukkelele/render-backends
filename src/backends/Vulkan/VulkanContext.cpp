#include "Vulkan/VulkanContext.h"



VulkanContext::VulkanContext(void* _window)
{
    Window* window = static_cast<Window*>(_window);
    m_Window = std::shared_ptr<Window>(window);
}

void VulkanContext::Init()
{
}

void VulkanContext::Destroy()
{
}

void VulkanContext::SwapBuffers()
{

}
