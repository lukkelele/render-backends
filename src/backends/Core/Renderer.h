#pragma once
#include "RendererAPI.h"


class Renderer
{
public:    
    enum class API 
    {
        None = 0,
        Vulkan = 1,
        OpenGL = 2
    };

public:
    Renderer();
    virtual ~Renderer() = default;
    
    void Init(const std::string& glslVersion);
    void Clear();
    void BeginFrame();
    void EndFrame();

    static API GetAPI() { return m_API; }

private:
    std::shared_ptr<RendererAPI> m_RendererAPI = nullptr;
    static API m_API;
};