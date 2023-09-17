#pragma once
#include <glad/glad.h>
#include "GraphicsContext.h"


class OpenGL_Context : public GraphicsContext
{
public:
    OpenGL_Context(void* window);
    ~OpenGL_Context() = default;

    void Init(const std::string& glslVersion);
    void Destroy();
    void SwapBuffers();

private:
    void InitImGui(const std::string& glslVersion);
};