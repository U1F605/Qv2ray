#pragma once
//
#include <QMap>
#include <QtCore>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <optional>
#include <vector>
// Base support.
#include "base/JsonHelpers.hpp"
#include "base/QvFeatures.hpp"
#include "base/QvLog.hpp"
// Code Models
#include "base/QvBaseApplication.hpp"
#include "base/models/CoreObjectModels.hpp"
#include "base/models/QvConfigIdentifier.hpp"
#include "base/models/QvRuntimeConfig.hpp"
#include "base/models/QvSafeType.hpp"
#include "base/models/QvSettingsObject.hpp"
#include "base/models/QvStartupConfig.hpp"

using namespace Qvmessocket;
using namespace Qvmessocket::base;
using namespace Qvmessocket::base::safetype;
using namespace Qvmessocket::base::config;
using namespace Qvmessocket::base::objects;
using namespace Qvmessocket::base::objects::protocol;
using namespace Qvmessocket::base::objects::transfer;

#define QV2RAY_BUILD_INFO QString(_QV2RAY_BUILD_INFO_STR_)
#define QV2RAY_BUILD_EXTRA_INFO QString(_QV2RAY_BUILD_EXTRA_INFO_STR_)

#ifdef QT_DEBUG
#define QV2RAY_CONFIG_DIR_SUFFIX "_debug/"
#define _BOMB_ (static_cast<QObject *>(nullptr)->event(nullptr))
#else
#define _BOMB_
#define QV2RAY_CONFIG_DIR_SUFFIX "/"
#endif

#ifdef Q_OS_WIN
#define QV2RAY_EXECUTABLE_SUFFIX ".exe"
#else
#define QV2RAY_EXECUTABLE_SUFFIX ""
#endif

#ifdef Q_OS_WIN
#define QV2RAY_LIBRARY_SUFFIX ".dll"
#else
#define QV2RAY_LIBRARY_SUFFIX ".so"
#endif

#define QV2RAY_CONFIG_DIR (QvCoreApplication->ConfigPath)
#define QV2RAY_CONFIG_FILE (QV2RAY_CONFIG_DIR + "Qv2ray.conf")
#define QV2RAY_CONNECTIONS_DIR (QV2RAY_CONFIG_DIR + "connections/")
#define QV2RAY_PLUGIN_SETTINGS_DIR (QV2RAY_CONFIG_DIR + "plugin_settings/")
#define QV2RAY_CONFIG_FILE_EXTENSION ".qv2ray.json"
#define QV2RAY_GENERATED_DIR (QV2RAY_CONFIG_DIR + "generated/")

#if !defined(QV2RAY_DEFAULT_VCORE_PATH) && !defined(QV2RAY_DEFAULT_VASSETS_PATH)
#define QV2RAY_DEFAULT_VASSETS_PATH (QV2RAY_CONFIG_DIR + "vcore/")
#define QV2RAY_DEFAULT_VCORE_PATH (QV2RAY_CONFIG_DIR + "vcore/v2ray" QV2RAY_EXECUTABLE_SUFFIX)
#define QV2RAY_DEFAULT_VCTL_PATH (QV2RAY_CONFIG_DIR + "vcore/v2ctl" QV2RAY_EXECUTABLE_SUFFIX)
#elif defined(QV2RAY_DEFAULT_VCORE_PATH) && defined(QV2RAY_DEFAULT_VASSETS_PATH)

#else
#error Both QV2RAY_DEFAULT_VCORE_PATH and QVMESSOCKET_DEFAULT_VASSETS_PATH need to be presented when using manually specify the paths.
#endif

#define QSTRN(num) QString::number(num)

#define OUTBOUND_TAG_BLACKHOLE "BLACKHOLE"
#define OUTBOUND_TAG_DIRECT "DIRECT"
#define OUTBOUND_TAG_PROXY "PROXY"
#define OUTBOUND_TAG_FORWARD_PROXY "QV2RAY_FORWARD_PROXY"

#define API_TAG_DEFAULT "QV2RAY_API"
#define API_TAG_INBOUND "QV2RAY_API_INBOUND"

#define QV2RAY_USE_FPROXY_KEY "_QV2RAY_USE_GLOBAL_FORWARD_PROXY_"
