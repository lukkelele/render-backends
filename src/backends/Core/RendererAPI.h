#pragma once
#include <GLFW/glfw3.h>
#include <imgui/imgui_impl_glfw.h>
#include <glm/glm.hpp>
#include "Base.h"

// Forward Declaration
class Renderer;

class RendererAPI
{
public:
    enum class API
    {
        None = 0,
        Vulkan = 1,
        OpenGL = 2
    };

public:
    virtual ~RendererAPI() = default;
    
    virtual void Init(const std::string& glslVersion) = 0;
    virtual void Clear() = 0;
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;

    static std::shared_ptr<RendererAPI> Create(const std::string& glslVersion);
    static API GetAPI() { return m_API; }

private:
    static API m_API;
};