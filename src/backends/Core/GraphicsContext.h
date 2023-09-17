#pragma once
#include <GLFW/glfw3.h>
#include <memory>

// Forward Declaration
class Window;

class GraphicsContext
{
public:
    virtual ~GraphicsContext() = default;

    virtual void Init() = 0;
    virtual void Destroy() = 0;
    virtual void SwapBuffers() = 0;
    
    static std::shared_ptr<GraphicsContext> Create(void* window);

protected:
    std::shared_ptr<Window> m_Window = nullptr;
};