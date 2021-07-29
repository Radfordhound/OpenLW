#pragma once
#include <Hedgehog/Base/hhBase.h>

namespace hh
{
namespace ut
{
template<typename T>
class ResCommon
{
protected:
    T* m_ptr;

public:
    typedef T value_type;

    const T* ptr() const
    {
        return m_ptr;
    }

    T* ptr()
    {
        return m_ptr;
    }

    const T& ref() const
    {
        return *m_ptr;
    }

    T& ref()
    {
        return *m_ptr;
    }

    bool IsValid() const
    {
        return (m_ptr != nullptr);
    }

    // TODO: Is this function actually a thing?
    inline ResCommon(std::nullptr_t) :
        m_ptr(nullptr) {}

    ResCommon(const void* data) :
        m_ptr(static_cast<T*>(const_cast<void*>(data))) {}

    ResCommon(void* data = nullptr) :
        m_ptr(static_cast<T*>(data)) {}
};

enum ResFileCommonPof0Flags
{
    /* Masks */
    POF0_SIZE_MASK = 0xC0U,
    POF0_DATA_MASK = 0x3FU,

    /* Sizes */
    POF0_SIZE_SIX_BIT = 0x40U,
    POF0_SIZE_FOURTEEN_BIT = 0x80U,
    POF0_SIZE_THIRTY_BIT = 0xC0U
};

class ResFileCommon
{
    // TODO: Any data members or anything??

public:
    // Wii U: 0x036945dc, PC: TODO
    static void ChangeEndian32(bool doSwap, const u32* input, u32* output);

    // TODO: Is this function actually a thing?
    inline static void ChangeEndian32(bool doSwap, const s32* input, s32* output)
    {
        ChangeEndian32(doSwap, reinterpret_cast<const u32*>(input),
            reinterpret_cast<u32*>(output));
    }

    // Wii U: 0x036945fc, PC: 0x00c1a210
    static u32 GetReverseBigEndian(u32 val);

    // Wii U: 0x03694630, PC: 0x00c1a240
    static void ReplacePof0(void* baseAddress,
        void* pof0Address, u32 pof0Size, bool doSwap);

    // Wii U: 0x03694790, PC: TODO
    static void ReplaceDic(unsigned int version, void* param_2,
        void* param_3, unsigned int depth, bool doSwap);
};
}
}
