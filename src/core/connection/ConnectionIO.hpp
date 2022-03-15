#pragma once
#include "base/Qv2rayBase.hpp"
namespace Qvmessocket::core::connection::connectionIO
{
    CONFIGROOT ConvertConfigFromFile(const QString &sourceFilePath, bool importComplex);
} // namespace Qv2ray::core::connection::connectionIO

using namespace Qvmessocket::core::connection;
using namespace Qvmessocket::core::connection::connectionIO;
