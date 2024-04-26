#pragma once

#include <common.hpp>
#include "Dummy.hpp"

namespace xlink2 {

    struct CommonResourceParam {
        int mNumResParam;
        int mNumResAssetParam;
        int mNumResTriggerOverwriteParam;
        int mNumLocalPropertyNameRefTable;
        int mNumLocalPropertyEnumNameRefTable;
        int mNumDirectValueTable;
        int mNumRandomTable;
        int mNumCurveTable;
        int mNumCurvePointTable;
        ResAssetParamTable *mResAssetParamTable;
        ulong mTriggerOverwriteParamTable;
        ulong *mLocalPropertyNameRefTable;
        ulong *mLocalPropertyEnumNameRefTable;
        uint *mDirectValueTable;
        ResRandomCallTable *mRandomTable;
        ResCurveCallTable *mCurveTable;
        CurvePointTable *mCurvePointTable;
        ResCondition *mConditionTable;
        void *mExRegion;
        char *mNameTable;
        void *mDataPtr;
        uint *mUserDataHashes;
        ulong *mUserOffsets;
    };
}