#include "backends/Core/Image.h"


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

