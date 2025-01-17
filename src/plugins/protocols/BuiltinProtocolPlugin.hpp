#pragma once

#include "QvPluginInterface.hpp"

#include <QObject>
#include <QtPlugin>

using namespace Qv2rayPlugin;

class InternalProtocolSupportPlugin
    : public QObject
    , public Qv2rayInterface
{
    Q_INTERFACES(Qv2rayPlugin::Qv2rayInterface)
    Q_PLUGIN_METADATA(IID Qv2rayInterface_IID)
    Q_OBJECT
  public:
    //
    // Basic metainfo of this plugin
    const QvPluginMetadata GetMetadata() const override
    {
        return { "Builtin Protocol Support",                                                  //
                 "vmessocket project",                                                     //
                 "qvplugin_builtin_protocol",                                                 //
                 "VMess, SOCKS, HTTP, Shadowsocks, DNS editor support",        //
                 QCLASH_VERSION_STRING,                                                  //
                 "Qvmessocket",                                                             //
                 {
                     COMPONENT_OUTBOUND_HANDLER, //
                     COMPONENT_GUI               //
                 },
                 UPDATE_NONE };
    }

    bool InitializePlugin(const QString &, const QJsonObject &) override;
    //
  signals:
    void PluginLog(const QString &) const override;
    void PluginErrorMessageBox(const QString &, const QString &) const override;
};

DECLARE_PLUGIN_INSTANCE(InternalProtocolSupportPlugin);
