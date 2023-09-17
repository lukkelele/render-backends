#include "RendererAPI.h"




class VulkanRenderer : public RendererAPI
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