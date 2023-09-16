#pragma once
#include "Window.h"


class Windows_Window : public Window
{
public:
    Windows_Window(const char* title, uint32_t width, uint32_t height);
    virtual ~Windows_Window();

    void Init();
    void Shutdown();
    void OnUpdate();
    void Clear();
    bool IsVSync() const;
    void SetVSync(bool enabled);
};