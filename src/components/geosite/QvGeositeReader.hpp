#pragma once
#include "base/Qv2rayBase.hpp"

namespace Qvmessocket::components::geosite
{
    QStringList ReadGeoSiteFromFile(const QString &filepath);
} // namespace Qv2ray::components::geosite

using namespace Qvmessocket::components;
using namespace Qvmessocket::components::geosite;
