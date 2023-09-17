#pragma once
#include "RendererAPI.h"


class Renderer
{
public:
    Renderer();
    virtual ~Renderer() = default;
    
    void Init(const std::string& glslVersion);
    void Clear();
    void BeginFrame();
    void EndFrame();

private:
    std::shared_ptr<RendererAPI> m_RendererAPI = nullptr;
};