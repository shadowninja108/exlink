#pragma once

namespace sead {
    struct ListNode {
        ListNode* mPrev;
        ListNode* mNext;
    };
    static_assert(sizeof(ListNode) == 0x10);
}