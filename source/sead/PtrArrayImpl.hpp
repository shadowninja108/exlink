#pragma once

#include <common.hpp>

namespace sead {
    struct PtrArrayImpl {
        s32 mPtrNum = 0;
        s32 mPtrNumMax = 0;
        void** mPtrs = nullptr;

        void* unsafeAt(s32 idx) const { return mPtrs[idx]; }

        void* at(s32 idx) const {
            if (u32(mPtrNum) <= u32(idx)) {
                return nullptr;
            }
            return mPtrs[idx];
        }
    };
}