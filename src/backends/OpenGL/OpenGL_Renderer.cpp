#include "backends/OpenGL/OpenGL_Renderer.h"


OpenGL_Renderer::OpenGL_Renderer(const std::string& glslVersion)
{
    m_GlslVersion = glslVersion;
}

void OpenGL_Renderer::Init(const std::string& glslVersion)
{
}

void OpenGL_Renderer::Clear()
{
    glClearColor(0.42f, 0.20f, 0.30f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGL_Renderer::BeginFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void OpenGL_Renderer::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
