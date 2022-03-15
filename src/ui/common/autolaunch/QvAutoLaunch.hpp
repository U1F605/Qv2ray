#pragma once

namespace Qvmessocket::components::autolaunch
{
    bool GetLaunchAtLoginStatus();
    void SetLaunchAtLoginStatus(bool enable);
} // namespace Qvmessocket::components::autolaunch

using namespace Qvmessocket::components;
using namespace Qvmessocket::components::autolaunch;
