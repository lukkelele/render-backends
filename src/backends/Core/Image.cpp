#include "backends/Core/Image.h"
#ifdef RENDER_API_VULKAN
	#include "Vulkan/VulkanImage.h"
#elif defined(RENDER_API_OPENGL)
	#include "OpenGL/OpenGL_Image.h"
#endif


// TODO: Remove / Patch out
Image::Image(std::string_view filepath)
{
#ifdef RENDER_API_VULKAN
#elif defined(RENDER_API_OPENGL)
#endif
}

std::shared_ptr<Image> Image::Create(std::string_view filepath)
{
#ifdef RENDER_API_VULKAN
	#include "Vulkan/VulkanImage.h"
	return NULL; // to be impl
#elif defined(RENDER_API_OPENGL)
	#include "OpenGL/OpenGL_Image.h"
	return std::make_shared<OpenGL_Image>(filepath);
#endif
}

uint32_t Image::BytesPerPixel(ImageFormat format)
{
	switch (format)
	{
		case ImageFormat::RGBA:    return 4;
		case ImageFormat::RGBA32F: return 16;
		case ImageFormat::None:	   return 0;
	}
	return 0;
}

int64_t Image::GetImageFormat(ImageFormat format)
{
	switch (format)
	{
		case ImageFormat::RGBA:    return 4;
		case ImageFormat::RGBA32F: return 16;
		case ImageFormat::None:	   return 0;
	}
	return 0;
}

