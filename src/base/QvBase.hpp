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

#define QVMESSOCKET_BUILD_INFO QString(_QVMESSOCKET_BUILD_INFO_STR_)
#define QVMESSOCKET_BUILD_EXTRA_INFO QString(_QVMESSOCKET_BUILD_EXTRA_INFO_STR_)

#define _BOMB_
#define QVMESSOCKET_CONFIG_DIR_SUFFIX "/"

#ifdef Q_OS_WIN
#define QVMESSOCKET_EXECUTABLE_SUFFIX ".exe"
#else
#define QVMESSOCKET_EXECUTABLE_SUFFIX ""
#endif

#ifdef Q_OS_WIN
#define QVMESSOCKET_LIBRARY_SUFFIX ".dll"
#else
#define QVMESSOCKET_LIBRARY_SUFFIX ".so"
#endif

#define QVMESSOCKET_CONFIG_DIR (QvCoreApplication->ConfigPath)
#define QVMESSOCKET_CONFIG_FILE (QVMESSOCKET_CONFIG_DIR + "Qv2ray.conf")
#define QVMESSOCKET_CONNECTIONS_DIR (QVMESSOCKET_CONFIG_DIR + "connections/")
#define QVMESSOCKET_PLUGIN_SETTINGS_DIR (QVMESSOCKET_CONFIG_DIR + "plugin_settings/")
#define QV2RAY_CONFIG_FILE_EXTENSION ".qv2ray.json"
#define QV2RAY_GENERATED_DIR (QVMESSOCKET_CONFIG_DIR + "generated/")

#if !defined(QVMESSOCKET_DEFAULT_VCORE_PATH) && !defined(QVMESSOCKET_DEFAULT_VASSETS_PATH)
#define QVMESSOCKET_DEFAULT_VASSETS_PATH (QVMESSOCKET_CONFIG_DIR + "vcore/")
#define QVMESSOCKET_DEFAULT_VCORE_PATH (QVMESSOCKET_CONFIG_DIR + "vcore/v2ray" QVMESSOCKET_EXECUTABLE_SUFFIX)
#define QV2RAY_DEFAULT_VCTL_PATH (QVMESSOCKET_CONFIG_DIR + "vcore/v2ctl" QVMESSOCKET_EXECUTABLE_SUFFIX)
#elif defined(QVMESSOCKET_DEFAULT_VCORE_PATH) && defined(QVMESSOCKET_DEFAULT_VASSETS_PATH)

#else
#error Both QVMESSOCKET_DEFAULT_VCORE_PATH and QVMESSOCKET_DEFAULT_VASSETS_PATH need to be presented when using manually specify the paths.
#endif

#define QSTRN(num) QString::number(num)

#define OUTBOUND_TAG_DIRECT "DIRECT"
#define OUTBOUND_TAG_PROXY "PROXY"
#define OUTBOUND_TAG_FORWARD_PROXY "QV2RAY_FORWARD_PROXY"

#define API_TAG_DEFAULT "QV2RAY_API"
#define API_TAG_INBOUND "QV2RAY_API_INBOUND"

#define QV2RAY_USE_FPROXY_KEY "_QV2RAY_USE_GLOBAL_FORWARD_PROXY_"
