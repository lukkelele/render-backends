#pragma once
#include <glad/glad.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include "Renderer.h"


class OpenGL_Renderer : public Renderer
{
public:
    OpenGL_Renderer(const std::string& glslVersion = "");
    ~OpenGL_Renderer() = default;

    void Init(const std::string& glslVersion);
    void Clear();
    void BeginFrame();
    void EndFrame();
    void Draw();

};