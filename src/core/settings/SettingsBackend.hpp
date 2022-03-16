#pragma once
#include "base/Qv2rayBase.hpp"

namespace Qvmessocket::core::config
{
    void SaveGlobalSettings();
    bool LocateConfiguration();
    void SetConfigDirPath(const QString &path);
    bool CheckSettingsPathAvailability(const QString &_path, bool checkExistingConfig);
} // namespace Qv2ray::core::config

namespace Qvmessocket
{
    // Extra header for QvConfigUpgrade.cpp
    QJsonObject UpgradeSettingsVersion(int fromVersion, int toVersion, const QJsonObject &root);
} // namespace Qv2ray

using namespace Qvmessocket::core;
using namespace Qvmessocket::core::config;
