#pragma once
#include <cstdint>
#include <memory>


class FrameBuffer
{
public:
    virtual ~FrameBuffer() = default;

    virtual void Bind() = 0;
    virtual void Unbind() = 0;
    virtual void ReadPixel(uint32_t attachIndex, int x, int y) = 0;

    // static std::shared_ptr<FrameBuffer> Create();

};
