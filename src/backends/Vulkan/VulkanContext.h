#pragma once
#include "GraphicsContext.h"


class VulkanContext : public GraphicsContext
{
public:
    VulkanContext(void* window);
    ~VulkanContext() = default;

    void Init();
    void Destroy();
    void SwapBuffers();

};