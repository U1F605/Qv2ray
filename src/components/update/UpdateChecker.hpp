#pragma once

#include <QObject>

namespace Qvmessocket::common::network
{
    class NetworkRequestHelper;
}

namespace Qvmessocket::components
{
    struct QvUpdateInfo
    {
        int channel;
        QString tag;
        QString title;
        QString releaseNotes;
        QString downloadLink;
    };

    class QvUpdateChecker : public QObject
    {
        Q_OBJECT
      public:
        explicit QvUpdateChecker(QObject *parent = nullptr);
        void CheckUpdate();
        ~QvUpdateChecker();
      signals:
        void OnCheckUpdateCompleted(bool hasUpdate, const QvUpdateInfo &updateInfo);

      private:
        Qvmessocket::common::network::NetworkRequestHelper *requestHelper;
        void static VersionUpdate(const QByteArray &data);
    };
} // namespace Qv2ray::components
using namespace Qvmessocket::components;
