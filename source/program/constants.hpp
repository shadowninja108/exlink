#pragma once

namespace exlnk {
    namespace slink {
        static constexpr int s_InstanceOffset = 0x0471A578;
        static constexpr int s_RootCallbackOffset = 0x11D8;
        static constexpr int s_VtableHookOffset = 0x043C67D8;
    }

    namespace elink {
        static constexpr int s_InstanceOffset = 0x0471A548;
        static constexpr int s_RootCallbackOffset = 0x11C8;
        static constexpr int s_VtableHookOffset = 0x042E7818;
    }
}