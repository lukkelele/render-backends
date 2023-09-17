#include "VulkanRenderer.h"


VulkanRenderer::VulkanRenderer()
{
    m_Instance = this;
}

void VulkanRenderer::Init(const std::string& glslVersion)
{
    std::string glsl;
    if (glslVersion.empty())
    {
        glsl = m_GlslVersion;
    }


}

void VulkanRenderer::Clear()
{
}

void VulkanRenderer::NewFrame()
{
}

void VulkanRenderer::EndFrame()
{
}

// To be impl
void VulkanRenderer::Draw()
{
}

void VulkanRenderer::CreateCommandPool()
{
}
