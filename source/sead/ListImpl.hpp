#pragma once

#include <common.hpp>
#include "ListNode.hpp"

namespace sead {
    struct PACKED ListImpl {
        ListNode mStartEnd;
        int mCount;
    };
    static_assert(sizeof(ListImpl) == 0x14);

}