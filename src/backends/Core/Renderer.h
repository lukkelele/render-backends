#pragma once
#include <string>
#include <memory>
#include <GLFW/glfw3.h>
#include <imgui/imgui_impl_glfw.h>

static constexpr auto DEFAULT_GLSL_VERSION = "#version 330";


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
    virtual ~Renderer() = default;
    
    virtual void Init(const std::string& glslVersion = "") = 0;
    virtual void Clear() = 0;
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;

    static std::shared_ptr<Renderer> Create(const std::string& glslVersion);
    static API GetAPI() { return m_API; }
    static std::string GetGLSLVersion() { return m_GlslVersion; }

protected:
    static std::string m_GlslVersion;
    static API m_API;
};