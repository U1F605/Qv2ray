#pragma once
#include "base/QvBase.hpp"

namespace Qvmessocket::core::config
{
    void SaveGlobalSettings();
    bool LocateConfiguration();
    void SetConfigDirPath(const QString &path);
    bool CheckSettingsPathAvailability(const QString &_path, bool checkExistingConfig);
} // namespace Qv2ray::core::config

namespace Qvmessocket
{
    QJsonObject UpgradeSettingsVersion(int fromVersion, int toVersion, const QJsonObject &root);
}

using namespace Qvmessocket::core;
using namespace Qvmessocket::core::config;
