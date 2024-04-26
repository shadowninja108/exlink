#pragma once

#include "ListImpl.hpp"

namespace sead {
    template<typename T>
    struct OffsetList : ListImpl {
        int mOffset;

        T* listNodeToObj(ListNode* obj) const {
            return static_cast<T*>(reinterpret_cast<uintptr_t>(obj) - mOffset);
        }
    };
}