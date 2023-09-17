// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
#ifdef _WIN64
	/* Windows x64  */
#ifndef PLATFORM_WINDOWS
#define PLATFORM_WINDOWS
#endif
#else
#error "x86 Builds are not supported!"
#endif

#elif defined(__ANDROID__)
#define PLATFORM_ANDROID
#error "Android is not supported!"
#elif defined(__linux__)
#ifndef PLATFORM_LINUX
#define PLATFORM_LINUX
#endif
#else
#error "Unknown platform!"
#endif // End of platform detection
