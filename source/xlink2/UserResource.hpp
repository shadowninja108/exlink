#pragma once

#include <common.hpp>
#include "ResMode.hpp"
#include "UserResourceParam.hpp"
#include "Dummy.hpp"

namespace xlink2 {

    struct User;
    
    struct UserResource {
        uintptr_t __vftable;
        User* mUser;
        uintptr_t field_10;
        ResMode mResMode;
        UserResourceParam* mParamsByMode[ResMode_End];

        inline UserResourceParam* GetCurrentParam() const { return mParamsByMode[mResMode]; }
    };
}