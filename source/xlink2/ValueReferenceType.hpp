#pragma once

#include <common.hpp>

namespace xlink2 {
    enum class ValueReferenceType : u8 {
        Direct = 0,
        String = 1,
        Curve = 2,
    };

}