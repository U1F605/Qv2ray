#pragma once

#include "ui/QvPlatformApplication.hpp"

#include <QSystemTrayIcon>

class MainWindow;

namespace Qvmessocket
{
    class Qv2rayWidgetApplication : public Qv2rayPlatformApplication
    {
        Q_OBJECT
      public:
        explicit Qv2rayWidgetApplication(int &argc, char *argv[]);
        QJsonObject UIStates;

      public:
        void MessageBoxWarn(QWidget *parent, const QString &title, const QString &text) override;
        void MessageBoxInfo(QWidget *parent, const QString &title, const QString &text) override;
        MessageOpt MessageBoxAsk(QWidget *parent, const QString &title, const QString &text, const QList<MessageOpt> &buttons) override;
        void ShowTrayMessage(const QString &m, int msecs = 10000);
        void OpenURL(const QString &url) override;

        inline QSystemTrayIcon **GetTrayIcon()
        {
            return &hTray;
        }

      private:
        QStringList checkPrerequisitesInternal() override;
        QvExitReason runQv2rayInternal() override;
        bool isInitialized;
        void terminateUIInternal() override;
#ifndef QV2RAY_NO_SINGLEAPPLICATON
        void onMessageReceived(quint32 clientID, QByteArray msg) override;
#endif
        QSystemTrayIcon *hTray;
        MainWindow *mainWindow;
    };
}

#ifdef Qv2rayApplication
#undef Qv2rayApplication
#endif
#define Qv2rayApplication Qv2rayWidgetApplication

#define QvWidgetApplication static_cast<Qv2rayWidgetApplication *>(qApp)
#define qvAppTrayIcon (*(QvWidgetApplication->GetTrayIcon()))

using namespace Qvmessocket;
