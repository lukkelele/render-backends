#include "OpenGL_Image.h"
#include <glad/glad.h>


OpenGL_Image::OpenGL_Image(std::string_view filepath)
{
    m_FilePath = filepath;
    int width, height, channels;
    uint8_t* data = nullptr;
    if (stbi_is_hdr(m_FilePath.c_str()))
    {
        data = (uint8_t*)stbi_loadf(m_FilePath.c_str(), &width, &height, &channels, 4);
        m_Format = ImageFormat::RGBA32F;
    }
    else
    {
        data = stbi_load(m_FilePath.c_str(), &width, &height, &channels, 4);
        m_Format = ImageFormat::RGBA;
    }

    m_BPP = BytesPerPixel(m_Format);
    m_Width = width;
    m_Height = height;

    m_localBuffer = data;
    AllocateMemory(m_Width * m_Height * BytesPerPixel(m_Format));
    SetData(data);

    if (m_localBuffer)
        stbi_image_free(data);
}

OpenGL_Image::~OpenGL_Image()
{
    ReleaseMemory();
}

int64_t OpenGL_Image::GetImageFormat(ImageFormat format)
{
	switch (format)
	{
		case ImageFormat::RGBA:    return GL_RGBA;
		case ImageFormat::RGBA32F: return GL_RGBA32F;
		case ImageFormat::None:	   return 0;
	}
	return 0;
}


void OpenGL_Image::SetData(const void* data)
{
}

void OpenGL_Image::Resize(uint32_t width, uint32_t height)
{
}

void OpenGL_Image::AllocateMemory(uint64_t size)
{
    glGenTextures(1, &m_RendererID); 
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
    // Size is indirectly calculated from m_Width * m_Height * bytesPerPixel. Arg is still passed because of Vulkan impl
    GLint textureFormat = (GLint)GetImageFormat(m_Format);
    // Set texture filtering and wrapping properties (equivalent to vkCreateSampler)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, textureFormat, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer);
    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);

}

void OpenGL_Image::ReleaseMemory()
{
}


