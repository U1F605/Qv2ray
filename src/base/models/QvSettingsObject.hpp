#pragma once
#include "base/models/QvConfigIdentifier.hpp"
#include "base/models/QvCoreSettings.hpp"
#include "base/models/QvSafeType.hpp"

#include <chrono>

constexpr int QVMESSOCKET_CONFIG_VERSION = 14;

namespace Qvmessocket::base::config
{
    struct QvGraphPenConfig
    {
        int R = 150, G = 150, B = 150;
        float width = 1.5f;
        Qt::PenStyle style = Qt::SolidLine;
        QvGraphPenConfig(){};
        QvGraphPenConfig(int R, int G, int B, float w, Qt::PenStyle s)
        {
            this->R = R;
            this->G = G;
            this->B = B;
            this->width = w;
            this->style = s;
        };
        friend bool operator==(const QvGraphPenConfig &one, const QvGraphPenConfig &another)
        {
            return one.R == another.R && one.G == another.G && one.B == another.B && one.width == another.width && one.style == another.style;
        }
        JSONSTRUCT_REGISTER(QvGraphPenConfig, F(R, G, B, width, style))
    };

    struct QvConfig_Graph
    {
        bool useOutboundStats = true;
        bool hasDirectStats = true;
        safetype::QvEnumMap<StatisticsType, safetype::QvPair<QvGraphPenConfig>> colorConfig;
        JSONSTRUCT_COMPARE(QvConfig_Graph, useOutboundStats, hasDirectStats, colorConfig)
        JSONSTRUCT_REGISTER(QvConfig_Graph, F(useOutboundStats, hasDirectStats, colorConfig))
        const static inline QvPair<QvGraphPenConfig> DefaultPen{ { 134, 196, 63, 1.5f, Qt::SolidLine }, { 50, 153, 255, 1.5f, Qt::SolidLine } };
        const static inline QvPair<QvGraphPenConfig> DirectPen{ { 0, 210, 240, 1.5f, Qt::DotLine }, { 235, 220, 42, 1.5f, Qt::DotLine } };
    };

    struct QvConfig_UI
    {
#ifdef Q_OS_WIN
        QString theme = "windowsvista";
#elif defined(Q_OS_MACOS)
        QString theme = "macintosh";
#else
        QString theme = "Fusion";
#endif
        QString language = "en_US";
        QList<ConnectionGroupPair> recentConnections;
        QvConfig_Graph graphConfig;
        bool quietMode = false;
        bool useDarkTheme = false;
        bool useGlyphTrayIcon = true;
        bool useDarkTrayIcon = false;
        int maximumLogLines = 500;
        int maxJumpListCount = 20;
        bool useOldShareLinkFormat = false;
        bool startMinimized = true;
        bool exitByCloseEvent = false;
        JSONSTRUCT_COMPARE(QvConfig_UI, theme, language, quietMode, graphConfig, useDarkTheme, useDarkTrayIcon, useGlyphTrayIcon, maximumLogLines,
                           maxJumpListCount, recentConnections, useOldShareLinkFormat, startMinimized, exitByCloseEvent)
        JSONSTRUCT_REGISTER(QvConfig_UI, F(theme, language, quietMode, graphConfig, useDarkTheme, useDarkTrayIcon, useGlyphTrayIcon,
                                               maximumLogLines, maxJumpListCount, recentConnections, useOldShareLinkFormat, startMinimized, exitByCloseEvent))
    };

    struct QvConfig_Plugin
    {
        QMap<QString, bool> pluginStates;
        bool Integration = true;
        int portAllocationStart = 15000;
        JSONSTRUCT_COMPARE(QvConfig_Plugin, pluginStates, Integration, portAllocationStart)
        JSONSTRUCT_REGISTER(QvConfig_Plugin, F(pluginStates, Integration, portAllocationStart))
    };

    struct QvConfig_Kernel
    {
        bool enableAPI = true;
        int statsPort = 15490;
        //
        QString CorePath_linux;
        QString AssetsPath_linux;
        QString CorePath_win;
        QString AssetsPath_win;

#ifdef Q_OS_LINUX
#define _VARNAME_VCOREPATH_ CorePath_linux
#define _VARNAME_VASSETSPATH_ AssetsPath_linux
#elif defined(Q_OS_WIN)
#define _VARNAME_VCOREPATH_ CorePath_win
#define _VARNAME_VASSETSPATH_ AssetsPath_win
#endif

        inline const QString KernelPath(const QString &path = "")
        {
            return path.isEmpty() ? _VARNAME_VCOREPATH_ : _VARNAME_VCOREPATH_ = path;
        }
        inline const QString AssetsPath(const QString &path = "")
        {
            return path.isEmpty() ? _VARNAME_VASSETSPATH_ : _VARNAME_VASSETSPATH_ = path;
        }

#undef _VARNAME_VCOREPATH_
#undef _VARNAME_VASSETSPATH_

        JSONSTRUCT_COMPARE(QvConfig_Kernel, enableAPI, statsPort, //
                           CorePath_linux, AssetsPath_linux,      //
                           CorePath_win, AssetsPath_win)
        JSONSTRUCT_REGISTER(QvConfig_Kernel,                     //
                            F(enableAPI, statsPort),                 //
                            F(CorePath_linux, AssetsPath_linux), //
                            F(CorePath_win, AssetsPath_win))
    };

    struct QvConfig_Update
    {
        enum UpdateChannel
        {
            CHANNEL_STABLE = 0,
            CHANNEL_TESTING = 1
        };
        UpdateChannel updateChannel = CHANNEL_STABLE;
        QString ignoredVersion;
        JSONSTRUCT_COMPARE(QvConfig_Update, updateChannel, ignoredVersion)
        JSONSTRUCT_REGISTER(QvConfig_Update, F(ignoredVersion, updateChannel))
    };

    struct QvConfig_Advanced
    {
        bool testLatencyPeriodically = false;
        bool disableSystemRoot = false;
        bool testLatencyOnConnected = false;
        JSONSTRUCT_COMPARE(QvConfig_Advanced, testLatencyPeriodically, disableSystemRoot, testLatencyOnConnected)
        JSONSTRUCT_REGISTER(QvConfig_Advanced, F(testLatencyPeriodically, disableSystemRoot, testLatencyOnConnected))
    };

    enum QvLatencyTestingMethod
    {
        TCPING = 0,
        ICMPING = 1,
        REALPING = 2
    };

    struct QvConfig_Network
    {
        enum QvProxyType
        {
            QVPROXY_NONE = 0,
            QVPROXY_SYSTEM = 1,
            QVPROXY_CUSTOM = 2
        };

        QvLatencyTestingMethod latencyTestingMethod = TCPING;
        QString latencyRealPingTestURL = "https://www.google.com";
        QvProxyType proxyType = QVPROXY_NONE;
        QString address = "127.0.0.1";
        QString type = "http";
        int port = 8000;
        QString userAgent = "Qv2ray/$VERSION WebRequestHelper";
        JSONSTRUCT_COMPARE(QvConfig_Network, latencyTestingMethod, latencyRealPingTestURL, proxyType, type, address, port, userAgent)
        JSONSTRUCT_REGISTER(QvConfig_Network, F(latencyTestingMethod, latencyRealPingTestURL, proxyType, type, address, port, userAgent))
    };

    enum Qv2rayAutoConnectionBehavior
    {
        AUTO_CONNECTION_NONE = 0,
        AUTO_CONNECTION_FIXED = 1,
        AUTO_CONNECTION_LAST_CONNECTED = 2
    };

    struct QvConfigObject
    {
        int config_version;
        int logLevel = 0;
        //
        ConnectionGroupPair autoStartId;
        ConnectionGroupPair lastConnectedId;
        Qv2rayAutoConnectionBehavior autoStartBehavior = AUTO_CONNECTION_NONE;
        //
        QvConfig_UI uiConfig;
        QvConfig_Plugin pluginConfig;
        QvConfig_Kernel kernelConfig;
        QvConfig_Update updateConfig;
        QvConfig_Network networkConfig;
        QvConfig_Inbounds inboundConfig;
        QvConfig_Outbounds outboundConfig;
        QvConfig_Advanced advancedConfig;
        GroupRoutingConfig defaultRouteConfig;

        explicit QvConfigObject()
        {
            config_version = QVMESSOCKET_CONFIG_VERSION;
        }
#if QT_VERSION < QT_VERSION_CHECK(5, 13, 0)
        Q_DISABLE_COPY(QvConfigObject);
#else
        Q_DISABLE_COPY_MOVE(QvConfigObject);
#endif
        JSONSTRUCT_COMPARE(QvConfigObject, config_version, logLevel, autoStartId, lastConnectedId, autoStartBehavior, uiConfig, pluginConfig,
                           kernelConfig, updateConfig, networkConfig, inboundConfig, outboundConfig, advancedConfig, defaultRouteConfig)
        JSONSTRUCT_REGISTER_NOCOPYMOVE(QvConfigObject,                                                                   //
                                       A(config_version, autoStartId, lastConnectedId, autoStartBehavior, logLevel),         //
                                       A(uiConfig, advancedConfig, pluginConfig, updateConfig, kernelConfig, networkConfig), //
                                       A(inboundConfig, outboundConfig, defaultRouteConfig))
    };
}
