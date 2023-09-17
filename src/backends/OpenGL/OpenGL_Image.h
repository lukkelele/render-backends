#pragma once
#include <glad/glad.h>
#include "backends/Core/Image.h"

class OpenGL_Image : public Image
{
public:
    OpenGL_Image(std::string_view filepath);
    ~OpenGL_Image();

    void SetData(const void* data);
    void Resize(uint32_t width, uint32_t height);
    int64_t GetImageFormat(ImageFormat format);

    GLuint GetRendererID() const { return m_RendererID; }

private:
	void AllocateMemory(uint64_t size);
	void ReleaseMemory();

private:
    GLuint m_RendererID = 0;
    unsigned char* m_localBuffer;
};
