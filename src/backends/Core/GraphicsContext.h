#pragma once
#include <GLFW/glfw3.h>
#include <memory>
#include <string>

// Forward Declaration
class Window;

class GraphicsContext
{
public:
    virtual ~GraphicsContext() = default;

    virtual void Init(const std::string& glslVersion) = 0;
    virtual void Destroy() = 0;
    virtual void SwapBuffers() = 0;
    
    static std::shared_ptr<GraphicsContext> Create(void* window);

    void SetDarkTheme();

protected:
    virtual void InitImGui(const std::string& glslVersion) = 0;

protected:
    std::shared_ptr<Window> m_Window = nullptr;
};