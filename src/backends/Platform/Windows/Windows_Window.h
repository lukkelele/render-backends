#pragma once
#include "Window.h"

// Forward Declaration
class Renderer;

class Windows_Window : public Window
{
public:
    Windows_Window(const char* title, uint32_t width, uint32_t height);
    virtual ~Windows_Window();

    void Init();
    void OnUpdate();
    void Exit();
    void Clear();
    void BeginFrame();
    void EndFrame();
    bool IsVSync() const;
    void SetVSync(bool enabled);
};