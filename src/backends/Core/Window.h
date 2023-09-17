#pragma once
#include "backends/Core/Base.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

#include "Renderer.h"
#include "GraphicsContext.h"


class Window
{
public:
    virtual ~Window() = default;

    static std::shared_ptr<Window> Create(const char* title, uint32_t width, uint32_t height);
    virtual void Init(const std::string& glslVersion = "#version 330") = 0;
    virtual void OnUpdate() = 0;
    virtual void Exit() = 0;
    virtual void Clear() = 0;
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void SetVSync(bool enabled) = 0;

    uint32_t GetWidth()  const { return m_Width; }
    uint32_t GetHeight() const { return m_Height; }
    std::string GetTitle()  const { return m_Title; }
    GLFWwindow* GetGLFWWindow() const { return m_GlfwWindow; }
    bool IsVSync() const { return m_VSync; }


protected:
    uint32_t m_Width;
    uint32_t m_Height;
    std::string m_Title;
    bool m_VSync;
    GLFWwindow* m_GlfwWindow = nullptr;
    std::shared_ptr<Renderer> m_Renderer;
    std::shared_ptr<GraphicsContext> m_GraphicsContext = nullptr;

    static bool GLFW_Initialized;
};

// OpenGL Functions
// static void OpenGL_ClearError();
// static bool OpenGL_LogCall(const char* func, const char* file, int line);