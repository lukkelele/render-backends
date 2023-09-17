cmake_minimum_required(VERSION 3.4)

project(RendererBackends C CXX ASM)

list(APPEND CMAKE_MODULE_PATH 
	"${CMAKE_SOURCE_DIR}/cmake"
	"${CMAKE_SOURCE_DIR}/lib/glfw/CMake/modules"
)
option(RENDERER_API_VULKAN "Vulkan Renderer API" OFF)


if (RENDERER_API_VULKAN)
	set(RENDERER_API RENDERER_API_VULKAN)
elseif(NOT RENDERER_API_VULKAN)
	set(RENDERER_API RENDERER_API_OPENGL)
else()
	message(STATUS "No renderer set (Vulkan / OpenGL)")
endif()

find_package(GLFW3)
# find_package(VULKAN)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")


add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/main.cpp)
add_subdirectory(lib)

if(WIN32)
	# add_compile_definitions(${PROJECT_NAME} -DPLATFORM_WINDOWS)
	option(PLATFORM_WINDOWS "Graphics for Windows" ON)
	add_definitions(-DPLATFORM_WINDOWS)
	# if (NOT Vulkan_FOUND)
	# 	find_library(Vulkan_LIBRARY NAMES vulkan-1 vulkan PATHS ${CMAKE_SOURCE_DIR}/libs/vulkan)
	# 	if(Vulkan_LIBRARY)
	# 		set(Vulkan_FOUND ON)
	# 		MESSAGE("Using bundled Vulkan library version")
	# 	endif()
	# endif()
	# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_WIN32_KHR")
elseif(LINUX)
	option(PLATFORM_LINUX "Graphics for Linux" ON)
    if(NOT Vulkan_FOUND)
        # find_library(Vulkan_LIBRARY NAMES vulkan HINTS "$ENV{VULKAN_SDK}/lib" "${CMAKE_SOURCE_DIR}/lib/vulkan" REQUIRED)
    endif()
endif ()

message(STATUS "GLFW found: ${GLFW3_FOUND}")

target_link_libraries(${PROJECT_NAME} 
	PRIVATE
		${GLFW3_LIBRARY}
)

target_sources(${PROJECT_NAME} 
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/src/Backends/Core/Window.h
		${CMAKE_CURRENT_LIST_DIR}/src/Backends/Core/Window.cpp
)

target_include_directories(${PROJECT_NAME}
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/src
		${CMAKE_CURRENT_LIST_DIR}/src/backends
		${CMAKE_CURRENT_LIST_DIR}/src/backends/Core
		${CMAKE_CURRENT_LIST_DIR}/src/backends/Platform

		# Move this to its own CMakeLists.txt
		${CMAKE_CURRENT_LIST_DIR}/lib
		${CMAKE_CURRENT_LIST_DIR}/lib/imgui
		# ${CMAKE_CURRENT_LIST_DIR}/lib/GLFW
		${CMAKE_CURRENT_LIST_DIR}/lib/glad/include
		${GLFW3_INCLUDE_DIR}
)
message(STATUS "GLFW3 include dir: ${GLFW3_INCLUDE_DIR}")

if (PLATFORM_WINDOWS)
	target_sources(${PROJECT_NAME} 
		PRIVATE
			${CMAKE_CURRENT_LIST_DIR}/src/backends/Platform/Windows/Windows_Window.h
			${CMAKE_CURRENT_LIST_DIR}/src/backends/Platform/Windows/Windows_Window.cpp
	)
endif()

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		ImGui
)


install(
	TARGETS ${PROJECT_NAME} 
	DESTINATION ${CMAKE_INSTALL_BINDIR}
)
