#include <lib.hpp>
#include <source_location>
#include "xlink.hpp"
#include "constants.hpp"
#include "util.hpp"

#include <xlink2/IEventCallbackSLink.hpp>
#include <EXKing/GameSound.hpp>

namespace exlnk::slink {
    namespace {
        /* Get pointer to the callback object pointer in the SLink system. */
        static game::sound::GameSoundModule::SLinkCallback** GetRootEventCallbackPtr() {
            return exl::util::pointer_path::FollowSafe<game::sound::GameSoundModule::SLinkCallback*, s_InstanceOffset, s_RootCallbackOffset>();
        }

        /* Get pointer to a function pointer within a vtable. This is in SplSoundMgr and it registers the SLink root callback. */
        using HookedFuncType = void (*)(uintptr_t, uintptr_t);
        static HookedFuncType* GetHookFuncPtr() {
            return exl::util::pointer_path::FollowSafe<HookedFuncType, s_VtableHookOffset>();
        }
    }

    /* Our custom implementation of the callback object, which passes through to the original. */
    struct CustomEventCallbackSLink : game::sound::GameSoundModule::SLinkCallback {
        
        game::sound::GameSoundModule::SLinkCallback* m_Impl = nullptr;

        virtual ~CustomEventCallbackSLink() {
            if(m_Impl != nullptr) { m_Impl->~SLinkCallback(); }
            m_Impl = nullptr;
        }

        virtual int eventActivating(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(eventActivating(arg));
            return 0;
        }
        virtual void eventActivated(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(eventActivated(arg));
        }
        virtual bool soundPrePlay(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(soundPrePlay(arg));
            return false;
        }
        virtual void unk1(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(unk1(arg));
        }
        virtual void soundPlayed(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(soundPlayed(arg));
        }
        virtual void soundCalced(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(soundCalced(arg));
        }
        virtual int replaceAssetInfo(aal::AssetInfo* assetInfo, ReplaceAssetInfoArg const& arg) {
            char buf[500];
            PRINT("AssetName: %s", arg.mAssetName->mStringTop);
            XLINK_CALLBACK_WRAP(replaceAssetInfo(assetInfo, arg));
            return 0;
        }
        virtual void unk2(uintptr_t arg) {
            char buf[500];
            PRINT(__func__);
        }
        virtual void registerCB_eventActivating(uintptr_t cb) {
            char buf[500];
            PRINT(__func__);
            if(m_Impl != nullptr)
                m_Impl->registerCB_eventActivating(cb);
        }
        virtual void registerCB_eventActivated(uintptr_t cb) {
            char buf[500];
            PRINT(__func__);
            if(m_Impl != nullptr)
                m_Impl->registerCB_eventActivated(cb);
        }
        virtual void registerCB_soundPrePlay(uintptr_t cb) {
            char buf[500];
            PRINT(__func__);
            if(m_Impl != nullptr)
                m_Impl->registerCB_soundPrePlay(cb);
        }
        virtual void registerCB_unk1(uintptr_t cb) {
            char buf[500];
            PRINT(__func__);
            if(m_Impl != nullptr)
                m_Impl->registerCB_unk1(cb);
        }
        virtual void registerCB_soundPlayed(uintptr_t cb) {
            char buf[500];
            PRINT(__func__);
            if(m_Impl != nullptr)
                m_Impl->registerCB_soundPlayed(cb);
        }
        virtual void registerCB_soundCalced(uintptr_t cb) {
            char buf[500];
            PRINT(__func__);
            if(m_Impl != nullptr)
                m_Impl->registerCB_soundCalced(cb);
        }
        virtual void registerCB_replaceAssetInfo(uintptr_t cb) {
            char buf[500];
            PRINT(__func__);
            if(m_Impl != nullptr)
                m_Impl->registerCB_replaceAssetInfo(cb);
        }
        virtual void registerCB_unk2(uintptr_t cb) {
            char buf[500];
            PRINT(__func__);
            if(m_Impl != nullptr)
                m_Impl->registerCB_unk2(cb);
        }
    };

    static CustomEventCallbackSLink s_Callback {};
    static HookedFuncType s_OriginalHookedFunc = nullptr;

    static void Callback(uintptr_t self, uintptr_t unk) {
        /* Call the original function. */
        s_OriginalHookedFunc(self, unk);

        char buf[500];

        PRINT("callback!")

        /* Try get the SLink root event callback object. */
        auto callbackPtr = GetRootEventCallbackPtr();
        PRINT("RootCallbackPtr: %lx", reinterpret_cast<uintptr_t>(callbackPtr));

        /* If the object exists, attempt to hook into it. */
        if(callbackPtr != nullptr) {
            auto callback = *callbackPtr;
            PRINT("RootCallback: %lx", reinterpret_cast<uintptr_t>(callback));

            /* Give the original callback object to ours, then make ours the one to use. */
            s_Callback.m_Impl = callback;
            *callbackPtr = &s_Callback;
        }

        /* Restore vtable entry. */
        *GetHookFuncPtr() = s_OriginalHookedFunc;
    }

    void Install() {
        /* Temporarily modify a vtable entry to call our func. */
        auto ptr = GetHookFuncPtr();
        s_OriginalHookedFunc = *ptr;
        *ptr = Callback;
    }
}