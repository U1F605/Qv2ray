#pragma once

#include "base/QvBaseApplication.hpp"
#include "components/translations/QvTranslator.hpp"
#include "core/handler/ConfigHandler.hpp"
#include "core/handler/RouteHandler.hpp"
#include "core/settings/SettingsBackend.hpp"
#include "utils/QvHelpers.hpp"

#ifndef QCLASH_NO_SINGLEAPPLICATON
#ifdef Q_OS_ANDROID
// No SingleApplication on Android platform
#define QCLASH_NO_SINGLEAPPLICATON
#endif
#endif

#ifdef Q_OS_WIN
#include <windows.h>
#endif

#ifdef QCLASH_GUI
#include <QApplication>
#include <QMessageBox>
const static inline QMap<MessageOpt, QMessageBox::StandardButton> MessageBoxButtonMap //
    = { { No, QMessageBox::No },
        { OK, QMessageBox::Ok },
        { Yes, QMessageBox::Yes },
        { Cancel, QMessageBox::Cancel },
        { Ignore, QMessageBox::Ignore } };
#else
#include <QCoreApplication>
#endif

#ifndef QCLASH_NO_SINGLEAPPLICATON
#include <SingleApplication>
#define QVBASEAPPLICATION SingleApplication
#define QVBASEAPPLICATION_CTORARGS argc, argv, true, User | ExcludeAppPath | ExcludeAppVersion
#else
#define QVBASEAPPLICATION QAPPLICATION_CLASS
#define QVBASEAPPLICATION_CTORARGS argc, argv
#endif

class QvPlatformApplication
    : public QVBASEAPPLICATION
    , public QvApplicationInterface
{
    Q_OBJECT
  public:
    QvPlatformApplication(int &argc, char *argv[]) : QVBASEAPPLICATION(QVBASEAPPLICATION_CTORARGS), QvApplicationInterface(){};
    virtual ~QvPlatformApplication(){};
    virtual QvExitReason GetExitReason() const final
    {
        return _exitReason;
    }

    virtual QStringList CheckPrerequisites() final;
    virtual bool Initialize() final;
    virtual QvExitReason RunQvmessocket() final;

  protected:
    virtual QStringList checkPrerequisitesInternal() = 0;
    virtual QvExitReason runQvmessocketInternal() = 0;
    virtual void terminateUIInternal() = 0;
    virtual void SetExitReason(QvExitReason r) final
    {
        _exitReason = r;
    }

#ifndef QCLASH_NO_SINGLEAPPLICATON
    virtual void onMessageReceived(quint32 clientId, QByteArray msg) = 0;
#endif

  private:
    void quitInternal();
    QvExitReason _exitReason;
    bool parseCommandLine(QString *errorMessage, bool *canContinue);
};
