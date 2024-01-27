workspace "RenderBackends"
    architecture "x86_64"

    configurations
    {
        "Debug",
		"Release",
        "Dist"
    }

    flags { "MultiProcessorCompile" }

    filter "configurations:Debug"
        defines { "LK_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "LK_RELEASE" }
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines { "LK_DIST" }
        runtime "Release"
        optimize "On"


outputdir = "%{cfg.buildcfg}-%{cfg.system}"

include "external/GLFW/glfw.lua"
include "external/glad/glad.lua"
include "external/imgui/imgui.lua"

project "RenderBackends"
    location "src"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    defines
    {
        "RENDER_API_OPENGL",

		"_GLM_WIN32",
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
        "IMGUI_IMPL_OPENGL_LOADER_GLAD",
        "IMGUI_DEFINE_MATH_OPERATORS",
    }

    files
    { 
        "%{wks.location}/src/**.h",
        "%{wks.location}/src/**.cpp",

        "%{wks.location}/external/stb_image/**.h",
        "%{wks.location}/external/stb_image/**.cpp",
   	}

    libdirs
    {
        "%{wks.location}/external/GLFW/lib",
    }

    includedirs
    {
        "src",
        "%{prj.name}",
		"%{wks.location}",
		"%{wks.location}/src",
		"%{wks.location}/src/backends",
		"%{wks.location}/src/backends/Platform",
		"%{wks.location}/src/backends/Core",
		"%{wks.location}/src/backends/Vulkan",
		"%{wks.location}/src/backends/OpenGL",
		"%{wks.location}/external",
		"%{wks.location}/external/glm",
		"%{wks.location}/external/imgui",
		"%{wks.location}/external/imgui/backends",
		"%{wks.location}/external/imgui/examples",
		"%{wks.location}/external/glad",
		"%{wks.location}/external/glad/include",
		"%{wks.location}/external/stb_image",
		"%{wks.location}/external/GLFW/include",
		"%{wks.location}/external/spdlog/include",
		"%{wks.location}/external/stb_image",

		"%{wks.location}/external/assimp/include",
    }

    links
    {
        "GLFW",
        "glad",
        "opengl32",
        "ImGui",
    }

	filter "system:windows"
		defines 
        { 
			"PLATFORM_WINDOWS",
			"_IMGUI_WIN32",
			"_CRT_SECURE_NO_WARNINGS",
		}

	filter "configurations:Debug"
		defines "LK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "LK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LK_DIST"
		runtime "Release"
		optimize "on"