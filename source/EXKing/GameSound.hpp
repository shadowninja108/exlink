#pragma once

#include <sead/FixedPtrArray.hpp>
#include <xlink2/IEventCallbackSLink.hpp>

namespace game::sound {
    struct GameSoundModule {
        struct SLinkCallback : xlink2::IEventCallbackSLink {
            // sead::FixedPtrArray<DelegateCreator, 17> mCB_eventActivating;
            // sead::FixedPtrArray<DelegateCreator, 17> mCB_eventActivated;
            // sead::FixedPtrArray<DelegateCreator, 17> mCB_soundPrePlay;
            // sead::FixedPtrArray<DelegateCreator, 17> mCB_unk1;
            // sead::FixedPtrArray<DelegateCreator, 17> mCB_soundPlayed;
            // sead::FixedPtrArray<DelegateCreator, 17> mCB_soundCalced;
            // sead::FixedPtrArray<DelegateCreator, 17> mCB_replaceAssetInfo;
            // sead::FixedPtrArray<DelegateCreator, 17> mCB_unk2;

            virtual ~SLinkCallback();

            virtual int eventActivating(xlink2::IEventCallbackSLink::EventArg const&);
            virtual void eventActivated(xlink2::IEventCallbackSLink::EventArg const&);
            virtual bool soundPrePlay(xlink2::IEventCallbackSLink::EventArg const&);
            virtual void unk1(xlink2::IEventCallbackSLink::EventArg const&);
            virtual void soundPlayed(xlink2::IEventCallbackSLink::EventArg const&);
            virtual void soundCalced(xlink2::IEventCallbackSLink::EventArg const&);
            virtual int replaceAssetInfo(aal::AssetInfo*, xlink2::IEventCallbackSLink::ReplaceAssetInfoArg const&);
            virtual void unk2(uintptr_t);

            virtual void registerCB_eventActivating(uintptr_t cb);
            virtual void registerCB_eventActivated(uintptr_t cb);
            virtual void registerCB_soundPrePlay(uintptr_t cb);
            virtual void registerCB_unk1(uintptr_t cb);
            virtual void registerCB_soundPlayed(uintptr_t cb);
            virtual void registerCB_soundCalced(uintptr_t cb);
            virtual void registerCB_replaceAssetInfo(uintptr_t cb);
            virtual void registerCB_unk2(uintptr_t cb);
        };
    };
}