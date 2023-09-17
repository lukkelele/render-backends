#include "OpenGLRenderer.h"


OpenGLRenderer::OpenGLRenderer()
{
}

void OpenGLRenderer::Init(const std::string& glslVersion)
{

}

void OpenGLRenderer::Clear()
{
    glClearColor(0.42f, 0.20f, 0.30f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderer::BeginFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void OpenGLRenderer::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
