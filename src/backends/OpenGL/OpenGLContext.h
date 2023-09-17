#pragma once
#include <glad/glad.h>
#include "GraphicsContext.h"


class OpenGLContext : public GraphicsContext
{
public:
    OpenGLContext(void* window);
    ~OpenGLContext() = default;

    void Init();
    void Destroy();
    void SwapBuffers();
};