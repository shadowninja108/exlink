#pragma once

#include <common.hpp>
#include "Dummy.hpp"
#include "ResAssetParam.hpp"

namespace xlink2 {

    struct ResAssetCallTable {
        const char* mKeyName;
        ushort mAssetId;
        ushort mFlag;
        int mDuration;
        int mParentIndex;
        ushort mEnumIndex;
        bool mIsSolved;
        int mKeyNameHash;
        union {
            ResAssetParam* mParamAsAsset;
            ResContainerParam* mParamAsContainer;
        };
        ResCondition* mCondition;

        inline bool IsContainer() const { return static_cast<bool>(mFlag & 1); }
        inline bool IsAsset() const { return !IsContainer(); } 
    };
    static_assert(sizeof(ResAssetCallTable) == 0x30);
}