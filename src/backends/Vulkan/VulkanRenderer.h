#include "Renderer.h"


class VulkanRenderer : public Renderer
{
public:
    VulkanRenderer();
    ~VulkanRenderer() = default;

    void Init(const std::string& glslVersion);
    void Clear();
    void NewFrame();
    void EndFrame();
    void Draw();
    void CreateCommandPool();

};