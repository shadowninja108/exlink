#pragma once

#include <common.hpp>
#include <sead/SafeStringBase.hpp>

namespace aal {

    struct AudioResource {
        uintptr_t __vftable;
        char padding8[0x10-0x8];
        uintptr_t mBARSPtr;
        uintptr_t field_18;
        const sead::SafeString* mFileNamePtr;
        uintptr_t mFileNameOnHeap;
        bool mInitialized;
        char field_31;
        char padding32[0x40-0x32];
        int field_40;
        char padding44[0xA0-0x44];
        uintptr_t field_A0;
        uintptr_t field_A8;
        bool mIsNewBars;
        uintptr_t mSharcArchiveRes;
    };
}