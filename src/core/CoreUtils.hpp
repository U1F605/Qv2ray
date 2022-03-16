#pragma once
#include "base/models/CoreObjectModels.hpp"
#include "base/models/QvConfigIdentifier.hpp"
#include "base/models/QvSafeType.hpp"

#define CurrentStatAPIType (GlobalConfig.uiConfig.graphConfig.useOutboundStats ? API_OUTBOUND_PROXY : API_INBOUND)

namespace Qvmessocket::core
{
    const inline GroupId DefaultGroupId{ "000000000000" };
    using namespace Qvmessocket::base;
    using namespace Qvmessocket::base::safetype;
    using namespace Qvmessocket::base::objects;
    inline const QString getTag(const INBOUND &in)
    {
        return in["tag"].toString();
    }

    inline const QString getTag(const OUTBOUND &in)
    {
        return in["tag"].toString();
    }

    inline const QString getTag(const RuleObject &in)
    {
        return in.QVMESSOCKET_RULE_TAG;
    }
    //
    int64_t GetConnectionLatency(const ConnectionId &id);
    uint64_t GetConnectionTotalData(const ConnectionId &id);
    const std::tuple<quint64, quint64> GetConnectionUsageAmount(const ConnectionId &id);
    //
    bool GetOutboundInfo(const OUTBOUND &out, QString *host, int *port, QString *protocol);
    inline ProtocolSettingsInfoObject GetOutboundInfo(const OUTBOUND &out)
    {
        ProtocolSettingsInfoObject o;
        GetOutboundInfo(out, &o.address, &o.port, &o.protocol);
        return o;
    }
    const ProtocolSettingsInfoObject GetConnectionInfo(const ConnectionId &id, bool *status = nullptr);
    const ProtocolSettingsInfoObject GetConnectionInfo(const CONFIGROOT &out, bool *status = nullptr);
    //
    bool IsComplexConfig(const CONFIGROOT &root);
    bool IsComplexConfig(const ConnectionId &id);
    //
    const QString GetConnectionProtocolString(const ConnectionId &id);
    //
    const QString GetDisplayName(const ConnectionId &id, int limit = -1);
    const QString GetDisplayName(const GroupId &id, int limit = -1);
    bool GetInboundInfo(const INBOUND &in, QString *listen, int *port, QString *protocol);
    inline ProtocolSettingsInfoObject GetInboundInfo(const INBOUND &in)
    {
        ProtocolSettingsInfoObject o;
        GetInboundInfo(in, &o.address, &o.port, &o.protocol);
        return o;
    }

    const QMap<QString, ProtocolSettingsInfoObject> GetInboundInfo(const CONFIGROOT &root);
    const QMap<QString, ProtocolSettingsInfoObject> GetInboundInfo(const ConnectionId &id);
}

using namespace Qvmessocket::core;
