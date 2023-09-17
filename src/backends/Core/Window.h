#pragma once
#include "backends/Core/Base.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
// #include <imgui/backends/imgui_impl_opengl3_loader.h>



class Window
{
public:
    virtual ~Window() = default;

    static std::shared_ptr<Window> Create(const char* title, uint32_t width, uint32_t height);
    virtual void Init() = 0;
    virtual void OnUpdate() = 0;
    virtual void Clear() = 0;
    virtual bool IsVSync() const = 0;
    virtual void SetVSync(bool enabled) = 0;

    uint32_t GetWidth()  const { return m_Width; }
    uint32_t GetHeight() const { return m_Height; }
    std::string GetTitle()  const { return m_Title; }
    GLFWwindow* GetGLFWWindow() const { return m_GlfwWindow; }

    void BeginFrame();
    void EndFrame();

protected:
    uint32_t m_Width;
    uint32_t m_Height;
    std::string m_Title;
    GLFWwindow* m_GlfwWindow = nullptr;
    bool m_VSync;

    static bool GLFW_Initialized;
};

// OpenGL Functions
// static void OpenGL_ClearError();
// static bool OpenGL_LogCall(const char* func, const char* file, int line);