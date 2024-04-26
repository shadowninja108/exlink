#pragma once

#include <common.hpp>
#include "UserResource.hpp"
#include <sead/OffsetList.hpp>

namespace xlink2 {
    
    struct UserInstance;

    struct User {
        uintptr_t __vftable;
        uintptr_t field_8;
        const char* mName;
        UserResource* mResource;
        sead::OffsetList<UserInstance> mInstanceList;
        /* ... */
    };
}