#pragma once

#include <common.hpp>
#include <numeric>
#include <sead/BitFlagUtil.hpp>
#include "ResParam.hpp"

namespace xlink2 {
    struct ResAssetParam {
        NON_COPYABLE(ResAssetParam);
        NON_MOVEABLE(ResAssetParam);

        ulong mBitfield;

        inline int GetCount() const {
            return std::popcount(mBitfield);
        }

        inline const ResParam* GetValues() const {
            return reinterpret_cast<const ResParam*>(this + 1);
        }

        inline bool IsValueDefault(int n) const {
            return (mBitfield & (1ul << n)) == 0;
        }

        inline const ResParam* GetNthValue(int n) const {
            if(IsValueDefault(n)) {
                return nullptr;
            }
            return &GetValues()[sead::BitFlagUtil::CountRightOnBit64(mBitfield, n) - 1];
        }

        static constexpr size_t CalculateSize(int count) {
            return sizeof(ResAssetParam) + (sizeof(ResParam) * count);
        }
    };
}