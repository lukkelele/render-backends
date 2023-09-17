#include <iostream>
#include "backends/Core/Window.h" 

// temporary
#ifdef RENDER_API_OPENGL
#include "OpenGL/OpenGL_Image.h" 
#endif

int main()
{
    std::shared_ptr<Window> window = Window::Create("Render Backends Window", 1440, 1080);
    window->Init(DEFAULT_GLSL_VERSION);
    GLFWwindow* glfwWindow = window->GetGLFWWindow();

    auto img = Image::Create("assets/img/atte_square.png");
    OpenGL_Image* img2 = new OpenGL_Image("assets/img/atte_square.png");
    Image* img2_conv = static_cast<Image*>(img2);


    while (!glfwWindowShouldClose(glfwWindow))
    {
        window->BeginFrame();

        ImGui::Begin("Main Window", (bool*)true, ImGuiWindowFlags_MenuBar);
        ImGui::Text("window text");
        ImFont* font = ImGui::GetFont();
        float originalFontSize = font->FontSize;
        // font->FontSize = 32;
        font->Scale = 1.5;
        ImGui::PushFont(font);
        ImGui::Text("Testing large sized font here");
        ImGui::PopFont();
        // font->FontSize = originalFontSize;
        font->Scale = 0.5;
        ImGui::PushFont(font);
        ImGui::Text("small sized font here");
        ImGui::PopFont();
        font->Scale = 1;
        ImGui::PushFont(font);
        ImGui::Text("normal sized font here");
        ImGui::PopFont();

        Renderer::Draw(img);
        Renderer::Draw(img2);
        Renderer::Instance()->DrawImage(static_cast<Image*>(img2));
        ImGui::End();

        window->EndFrame();
    }
    window->Exit();

    return 0;
}