#pragma once

#include <common.hpp>
#include <sead/OffsetList.hpp>
#include "Dummy.hpp"
#include "ResMode.hpp"
#include "User.hpp"

namespace xlink2 {
    
    struct UserInstance {
        uintptr_t __vftable;
        sead::OffsetList<Event> mEventList;
        uintptr_t field_20;
        uintptr_t field_28;
        uintptr_t field_30;
        uintptr_t field_38;
        uintptr_t field_40;
        UserInstanceParam* mParamsByResMode[ResMode_End];
        User* mUser;
        /* ... */
    };

}