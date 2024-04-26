#include <lib.hpp>
#include "xlink.hpp"
#include "constants.hpp"
#include "util.hpp"
#include <source_location>

#include <xlink2/IEventCallbackELink.hpp>

namespace exlnk::elink {

    namespace {
        /* Get pointer to the callback object pointer in the SLink system. */
        static xlink2::IEventCallbackELink** GetRootEventCallbackPtr() {
            return exl::util::pointer_path::FollowSafe<xlink2::IEventCallbackELink*, s_InstanceOffset, s_RootCallbackOffset>();
        }

        /* Get pointer to a function pointer within a vtable. */
        using HookedFuncType = void (*)(uintptr_t, uintptr_t);
        static HookedFuncType* GetHookFuncPtr() {
            return exl::util::pointer_path::FollowSafe<HookedFuncType, s_VtableHookOffset>();
        }
    }

    /* Our custom implementation of the callback object, which passes through to the original. */
    struct CustomEventCallbackELink : xlink2::IEventCallbackELink {
        
        xlink2::IEventCallbackELink* m_Impl = nullptr;

        virtual ~CustomEventCallbackELink() {
            char buf[500];
            PRINT("%s", __func__);
            if(m_Impl != nullptr) { m_Impl->~IEventCallbackELink(); }
            m_Impl = nullptr;
        }
        virtual void eventCreate(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(eventCreate(arg));
        }
        virtual void eventDestroy(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(eventDestroy(arg));
        }
        virtual void unk1(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(unk1(arg));
        }
        virtual void unk2(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(unk2(arg));
        }
        virtual bool effectPreEmit(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(effectPreEmit(arg));
            return false;
        }
        virtual void unk3(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(unk3(arg));
        }
        virtual void unk4(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(unk4(arg));
        }
        virtual void unk5(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(unk5(arg));
        }
        virtual void unk6(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(unk6(arg));
        }
        virtual void unk7(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(unk7(arg));
        }
        virtual void eventCalced(EventArg const& arg) {
            //char buf[500];
            //BASE(eventCalced(arg));
            if(m_Impl != nullptr) { m_Impl->eventCalced(arg); }
        }
        virtual void unk8(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(unk8(arg));
        }
        virtual void unk9(uintptr_t arg) {
            char buf[500];
            PRINT("%s", __func__);
            if(m_Impl != nullptr) { m_Impl->unk9(arg); }
        }
        virtual void resetResEset(xlink2::ResEset* eset, xlink2::ResAssetCallTable const& act, xlink2::ResourceAccessorELink const& accessor, char const* name) {
            //char buf[500];
            //PRINT("%s: %s", __func__, act.mKeyName);
            if(m_Impl != nullptr) {                                                                            
                m_Impl->resetResEset(eset, act, accessor, name);                                                                    
            }
        }
        virtual void drawDebugInformation(sead::TextWriter* writer) {
            char buf[500];
            PRINT("%s", __func__);
            if(m_Impl != nullptr) {                                                                            
                m_Impl->drawDebugInformation(writer);                                                                    
            }
        }
        virtual void drawEsetDebugInformation(sead::BufferedSafeString* out, sead::ptcl::EmitterSet* emitter) {
            char buf[500];
            PRINT("%s", __func__);
            if(m_Impl != nullptr) {                                                                            
                return m_Impl->drawEsetDebugInformation(out, emitter);                                                                    
            }
        }
        virtual void unk10(EventArg const& arg) {
            char buf[500];
            XLINK_CALLBACK_WRAP(unk10(arg));
        }
    };

    static CustomEventCallbackELink s_Callback {};
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