#pragma once
#include <string>
#include <memory>
#include <GLFW/glfw3.h>
#include <imgui/imgui_impl_glfw.h>
#include "Core/Image.h"

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

    static Renderer* Instance() { return m_Instance; }
    
    virtual void Init(const std::string& glslVersion = "") = 0;
    virtual void Clear() = 0;
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void DrawImage(Image* img) = 0;

    // static void DrawImage(Image*& img);
    static void Draw(std::shared_ptr<Image> img);
    static void Draw(Image* img);

    static std::shared_ptr<Renderer> Create(const std::string& glslVersion);
    static API GetAPI() { return m_API; }
    static std::string GetGLSLVersion() { return m_GlslVersion; }

protected:
    static Renderer* m_Instance;
    static std::string m_GlslVersion;
    static API m_API;
};