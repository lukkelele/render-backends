#include "Renderer.h"

Renderer::Renderer()
{
}

void Renderer::Init(const std::string& glslVersion)
{
    m_RendererAPI = RendererAPI::Create(glslVersion);
    m_RendererAPI->Init(glslVersion);
}

void Renderer::Clear()
{
    m_RendererAPI->Clear();
}

void Renderer::BeginFrame()
{
    m_RendererAPI->BeginFrame();
}

void Renderer::EndFrame()
{
    m_RendererAPI->EndFrame();
}
