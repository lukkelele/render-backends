#pragma once
#include <string>
#include <cstdint>
#include <stb_image/stb_image.h>


enum class ImageFormat
{
    None = 0,
    RGBA,
    RGBA32F
};


class Image
{
public:
	virtual ~Image() = default;

	virtual void SetData(const void* data) = 0;
	virtual void Resize(uint32_t width, uint32_t height) = 0;

	uint32_t GetWidth() const { return m_Width; }
	uint32_t GetHeight() const { return m_Height; }
	// ImageFormat GetFormat() const { return m_Format; }
	// virtual u uint64_t GetImageFormat(ImageFormat fmt) = 0;
	virtual int64_t GetImageFormat(ImageFormat fmt) = 0;

	static uint32_t BytesPerPixel(ImageFormat format);

protected:
	virtual void AllocateMemory(uint64_t size) = 0;
	virtual void ReleaseMemory() = 0;

protected:
	uint32_t m_Width = 0;
	uint32_t m_Height = 0;
	ImageFormat m_Format;
	std::string m_FilePath;
};