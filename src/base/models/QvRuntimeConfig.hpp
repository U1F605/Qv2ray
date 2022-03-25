#pragma once

#define SET_RUNTIME_CONFIG(conf, val) RuntimeConfig.conf = val();
#define RESTORE_RUNTIME_CONFIG(conf, func) func(RuntimeConfig.conf);

namespace Qvmessocket::base
{
    struct QvRuntimeConfig
    {
        bool screenShotHideQv = false;
    };
    inline base::QvRuntimeConfig RuntimeConfig = base::QvRuntimeConfig();
}
