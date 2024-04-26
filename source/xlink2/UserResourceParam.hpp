#pragma once

#include "CommonResourceParam.hpp"

namespace xlink2 {
    
    struct UserResourceParam {
        const xlink2::CommonResourceParam *mCommonResourceParam;
        /* xlink2::UserBinParam mUserBinParam; */
        /* sead::Buffer<uchar> mPropertyNameIndexToPropertyIndex; */
        /* sead::Buffer<ResCallTable> mCallTableArry; */
        /* sead::Buffer<bool> mActionTriggerBools; */
        /* ulong mPropertyAssignedBitfield; */
        /* xlink2::ResourceAccessor *field_A0; */
        /* bool mSetup; */
    };

}