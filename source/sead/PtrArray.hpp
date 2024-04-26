#pragma once

#include "PtrArrayImpl.hpp"

namespace sead {
    template<typename T> 
    struct PtrArray : PtrArrayImpl {
        T* at(s32 pos) const { return static_cast<T*>(PtrArrayImpl::at(pos)); }
        T* unsafeAt(s32 pos) const { return static_cast<T*>(PtrArrayImpl::unsafeAt(pos)); }
        T* operator()(s32 pos) const { return unsafeAt(pos); }
        T* operator[](s32 pos) const { return at(pos); }
    };
}