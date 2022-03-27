#pragma once

#include "3rdparty/QJsonStruct/macroexpansion.hpp"
#include "base/QvBaseApplication.hpp"
#include "base/models/QvStartupConfig.hpp"

#include <QPair>
#include <QString>
#include <QTextStream>
#include <iostream>

#define NEWLINE "\r\n"
#define ___LOG_EXPAND(___x) , QPair<std::string, decltype(___x)>(std::string(#___x), [&] { return ___x; }())
#define A(...) FOREACH_CALL_FUNC(___LOG_EXPAND, __VA_ARGS__)

#ifdef QT_DEBUG
#define QV_IS_DEBUG true
// __FILE__ ":" QT_STRINGIFY(__LINE__),
#define QV_LOG_PREPEND_CONTENT Q_FUNC_INFO,
#else
#define QV_IS_DEBUG false
#define QV_LOG_PREPEND_CONTENT
#endif

#define _LOG_ARG_(...) QV_LOG_PREPEND_CONTENT "[" QV_MODULE_NAME "]", __VA_ARGS__

#define LOG(...) Qvmessocket::base::log_internal<QV_LOG_NORMAL>(_LOG_ARG_(__VA_ARGS__))
#define DEBUG(...) Qvmessocket::base::log_internal<QV_LOG_DEBUG>(_LOG_ARG_(__VA_ARGS__))

enum QvLogType
{
    QV_LOG_NORMAL = 0,
    QV_LOG_DEBUG = 1
};

Q_DECLARE_METATYPE(const char *)

namespace Qvmessocket::base
{
    inline QString logBuffer;
    inline QString tempBuffer;
    inline QTextStream logStream{ &logBuffer };
    inline QTextStream tempStream{ &tempBuffer };

    inline QString ReadLog()
    {
        return logStream.readAll();
    }

    template<QvLogType t, typename... T>
    inline void log_internal(T... v)
    {
        ((logStream << v << " "), ...);
        ((tempStream << v << " "), ...);
        logStream << NEWLINE;
#ifndef QT_DEBUG
        // We only process DEBUG log in Release mode
        // Prevent QvCoreApplication nullptr
        // TODO: Move log function inside QvCoreApplication
        if (t == QV_LOG_DEBUG && QvCoreApplication && !QvCoreApplication->StartupArguments.debugLog)
        {
            // Discard debug log in non-debug Qv2ray version with
            // no-debugLog mode.
            return;
        }
#endif

        const auto logString = tempStream.readAll();
        std::cout << logString.toStdString() << std::endl;
    }
}

template<typename TKey, typename TVal>
QTextStream &operator<<(QTextStream &stream, const QPair<TKey, TVal> &pair)
{
    return stream << pair.first << ": " << pair.second;
}

inline QTextStream &operator<<(QTextStream &stream, const std::string &ss)
{
    return stream << ss.data();
}

template<typename TKey, typename TVal>
QTextStream &operator<<(QTextStream &stream, const QMap<TKey, TVal> &map)
{
    stream << "{ ";
    for (const auto &[k, v] : map.toStdMap())
        stream << QPair<TKey, TVal>(k, v) << "; ";
    stream << "}";
    return stream;
}

template<typename TVal>
QTextStream &operator<<(QTextStream &stream, const std::initializer_list<TVal> &init_list)
{
    for (const auto &x : init_list)
        stream << x;
    return stream;
}
