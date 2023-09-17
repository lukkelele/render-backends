#pragma once
#include <glad/glad.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include "RendererAPI.h"


class OpenGLRenderer : public RendererAPI
{
public:
    OpenGLRenderer();
    ~OpenGLRenderer() = default;

    void Init(const std::string& glslVersion);
    void Clear();
    void BeginFrame();
    void EndFrame();
    void Draw();

};