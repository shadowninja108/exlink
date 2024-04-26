#include "lib.hpp"

#include "util.hpp"
#include "hooks/elink.hpp"
#include "hooks/slink.hpp"

extern "C" void exl_main(void* x0, void* x1) {
    exl::hook::Initialize();

    exlnk::elink::Install();
    exlnk::slink::Install();
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}