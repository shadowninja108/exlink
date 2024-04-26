#pragma once

#include "CommonResourceParam.hpp"
#include "ValueReferenceType.hpp"

namespace xlink2 {
    struct __attribute__((packed)) ResParam {
        int mValue : 24;
        ValueReferenceType mType;

        inline const char* GetAsString(const CommonResourceParam* param) const {
            if(mType != ValueReferenceType::String)
                return nullptr;

            return param->mNameTable + mValue;
        }

        inline int GetAsInt(const CommonResourceParam* param) const {
            return reinterpret_cast<int*>(param->mDirectValueTable)[mValue];
        }

        inline float GetAsFloat(const CommonResourceParam* param) const {
            return reinterpret_cast<float*>(param->mDirectValueTable)[mValue];
        }
    };
    static_assert(sizeof(ResParam) == 0x4);
}