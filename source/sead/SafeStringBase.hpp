#pragma once

namespace sead {
    template<typename T>
    struct SafeStringBase {
        T* mStringTop;
    };
    using SafeString = SafeStringBase<char>;
}