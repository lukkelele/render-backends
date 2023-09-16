cmake_minimum_required(VERSION 3.4)

project(RendererBackends C CXX ASM)
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH 
	"${CMAKE_SOURCE_DIR}/cmake"
	"${CMAKE_SOURCE_DIR}/lib/glfw/CMake/modules"
)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

# find_package(VULKAN)
find_package(GLFW3)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

add_subdirectory(lib)


if(WIN32)
	# add_compile_definitions(${PROJECT_NAME} -DPLATFORM_WINDOWS)
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
    if(NOT Vulkan_FOUND)
        # find_library(Vulkan_LIBRARY NAMES vulkan HINTS "$ENV{VULKAN_SDK}/lib" "${CMAKE_SOURCE_DIR}/lib/vulkan" REQUIRED)
    endif()
endif ()

message(STATUS "GLFW found: ${GLFW3_FOUND}")

include(lib/glad/CMakeLists.txt)

target_link_libraries(${PROJECT_NAME} 
	PRIVATE
		${GLFW3_LIBRARY}
)

# FIXME
# Temporary fix
target_sources(${PROJECT_NAME} 
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/src/Backends/Base/Window.h
		${CMAKE_CURRENT_LIST_DIR}/src/Backends/Base/Window.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/backends/Platform/Windows/Windows_Window.h
		${CMAKE_CURRENT_LIST_DIR}/src/backends/Platform/Windows/Windows_Window.cpp
)

target_include_directories(${PROJECT_NAME}
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/src
		${CMAKE_CURRENT_LIST_DIR}/src/backends
		${CMAKE_CURRENT_LIST_DIR}/src/backends/Base
		${CMAKE_CURRENT_LIST_DIR}/src/backends/Platform

		# Move this to its own CMakeLists.txt
		${CMAKE_CURRENT_LIST_DIR}/lib
		${CMAKE_CURRENT_LIST_DIR}/lib/glad/include
		${GLFW3_INCLUDE_DIR}
)
message(STATUS "GLFW3 include dir: ${GLFW3_INCLUDE_DIR}")


install(
	TARGETS ${PROJECT_NAME} 
	DESTINATION ${CMAKE_INSTALL_BINDIR}
)
