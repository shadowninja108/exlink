#pragma once

#include <common.hpp>

namespace exlnk::xlink {

    struct GeneralInfo {
        const char* m_UserName = nullptr;
        const char* m_AssetCallName = nullptr;
        const char* m_RuntimeAssetName = nullptr;
    };

    template<typename ArgT>
    inline GeneralInfo GetGeneralInfo(ArgT const& arg) {
        GeneralInfo info;

        const auto act = arg.mResAssetCallTable;
        const auto instance = arg.mUserInstance;

        const auto user = instance->mUser;
        info.m_UserName = user->mName;
        info.m_AssetCallName = act->mKeyName;

        if(act->IsAsset()) {
            auto runtimeAssetName = act->mParamAsAsset->GetNthValue(1);
            if(runtimeAssetName != nullptr) {
                info.m_RuntimeAssetName = runtimeAssetName->GetAsString(user->mResource->GetCurrentParam()->mCommonResourceParam);
            }
        }
        
        #define ESCAPE_NULL(expr)   \
            expr = (expr != nullptr) ? expr : "(null)"

        ESCAPE_NULL(info.m_UserName);
        ESCAPE_NULL(info.m_AssetCallName);
        ESCAPE_NULL(info.m_RuntimeAssetName);

        #undef ESCAPE_NULL

        return info;
    }

    #define XLINK_CALLBACK_WRAP(...)                                                                        \
        auto info = xlink::GetGeneralInfo(arg);                                                             \
        PRINT("%s: %s | %s | %s", __func__, info.m_UserName, info.m_AssetCallName, info.m_RuntimeAssetName);\
        if(m_Impl != nullptr) {                                                                             \
            return m_Impl->__VA_ARGS__;                                                                     \
        }
}