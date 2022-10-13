#pragma once
#include "base/QvBase.hpp"
namespace Qvmessocket::core::connection::connectionIO
{
    CONFIGROOT ConvertConfigFromFile(const QString &sourceFilePath, bool importComplex);
}

using namespace Qvmessocket::core::connection;
using namespace Qvmessocket::core::connection::connectionIO;
