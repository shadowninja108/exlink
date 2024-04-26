#pragma once

namespace sead {
    template<typename T>
    struct BufferedSafeStringBase {
        const char* mOldStringTop;
        char* mStringTop;
        u32 mSize;
    };
    using BufferedSafeString = BufferedSafeStringBase<char>;
}