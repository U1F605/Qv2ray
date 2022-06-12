#pragma once
#include <QString>
namespace Qvmessocket::components::port
{
    bool CheckTCPPortStatus(const QString &addr, int port);
    inline bool CheckTCPPortStatus(std::pair<QString, int> config)
    {
        return CheckTCPPortStatus(config.first, config.second);
    }
} // namespace Qv2ray::components::port
