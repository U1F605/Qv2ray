#pragma once
#include <QHostAddress>
#include <QObject>
#include <QString>
//
namespace Qvmessocket::components::proxy
{
    void ClearSystemProxy();
    void SetSystemProxy(const QString &address, int http_port, int socks_port);
} // namespace Qv2ray::components::proxy

using namespace Qvmessocket::components;
using namespace Qvmessocket::components::proxy;
