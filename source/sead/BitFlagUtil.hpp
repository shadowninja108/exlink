#pragma once

#include <common.hpp>

namespace sead {

    struct BitFlagUtil {
        static constexpr int CountOnBit(u32 x) {
            x = x - ((x >> 1) & 0x55555555);
            x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
            x = (x + (x >> 4)) & 0x0F0F0F0F;
            x += (x >> 8);
            x += (x >> 16);
            return x & 0x3f;
        }

        static constexpr int CountOnBit64(u64 x) {
            return CountOnBit(static_cast<u32>(x)) + CountOnBit(static_cast<u32>(x >> 32));
        }
        
        static constexpr int CountRightOnBit64(ulong x, int bit) {
            ulong mask = ((1ul << bit) - 1) | (1ul << bit);
            return CountOnBit64(x & mask);
        }
    };
}