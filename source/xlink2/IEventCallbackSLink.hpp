#pragma once

#include <sead/SafeStringBase.hpp>
#include <aal/Dummy.hpp>
#include "Dummy.hpp"
#include "ResAssetCallTable.hpp"
#include "UserInstanceSLink.hpp"

namespace xlink2 {
    
    struct IEventCallbackSLink {

        struct EventArg {
            UserInstanceSLink* mUserInstance;
            aal::Handle* mAalHandle;
            ResAssetCallTable const* mResAssetCallTable;
            AssetExecutorSLink* mExecutor;
            EventSLink* mEvent;
        };

        struct ReplaceAssetInfoArg {
            sead::SafeString const* mAssetName;
            UserInstanceSLink* mUserInstance;
            EventSLink* mEvent;
            ResAssetCallTable const* mResAssetCallTable;
        };

        virtual ~IEventCallbackSLink() {}

        virtual int eventActivating(EventArg const&) { return 0; }
        virtual void eventActivated(EventArg const&) {}
        virtual bool soundPrePlay(EventArg const&) { return false; }
        virtual void unk1(EventArg const&) {}
        virtual void soundPlayed(EventArg const&) {}
        virtual void soundCalced(EventArg const&) {}
        virtual int replaceAssetInfo(aal::AssetInfo*, ReplaceAssetInfoArg const&) { return 0; }
        virtual void unk2(uintptr_t) {}
    };
}