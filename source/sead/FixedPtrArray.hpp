#pragma once

#include "PtrArray.hpp"

namespace sead {
    template<typename T, size_t Length>
    struct FixedPtrArray : PtrArray<T> {
        T* mWork[Length];
    };
}