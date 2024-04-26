#pragma once

#include <common.hpp>
#include <sead/Dummy.hpp>
#include <sead/BufferedSafeStringBase.hpp>
#include "ResAssetCallTable.hpp"
#include "UserInstanceELink.hpp"
#include "Dummy.hpp"

namespace xlink2 {
    struct IEventCallbackELink {
        struct EventArg {
            uintptr_t field_0;
            uintptr_t field_8;
            ResAssetCallTable const* mResAssetCallTable;
            UserInstanceELink* mUserInstance;
            uintptr_t mPtclHandle;
            AssetExecutorELink* mAssetExecutor;
            EventELink* mEvent;
        };

        virtual ~IEventCallbackELink() {};
        virtual void eventCreate(EventArg const& arg) {}
        virtual void eventDestroy(EventArg const& arg) {}
        virtual void unk1(EventArg const& arg) {}
        virtual void unk2(EventArg const& arg) {}
        virtual bool effectPreEmit(EventArg const& arg) { return false; }
        virtual void unk3(EventArg const& arg) {}
        virtual void unk4(EventArg const& arg) {}
        virtual void unk5(EventArg const& arg) {}
        virtual void unk6(EventArg const& arg) {}
        virtual void unk7(EventArg const& arg) {}
        virtual void eventCalced(EventArg const& arg) {}
        virtual void unk8(EventArg const& arg) {}
        virtual void unk9(uintptr_t arg) {}
        virtual void resetResEset(ResEset* eset, ResAssetCallTable const& act, ResourceAccessorELink const& accessor, char const* name) {}
        virtual void drawDebugInformation(sead::TextWriter* writer) {}
        virtual void drawEsetDebugInformation(sead::BufferedSafeString* out, sead::ptcl::EmitterSet* emitter) {}
        virtual void unk10(EventArg const& arg) {}
    };
}
