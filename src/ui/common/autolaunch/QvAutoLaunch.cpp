#include "QvAutoLaunch.hpp"

#include "base/QvBase.hpp"

#include <QCoreApplication>
#include <QDir>
#include <QSettings>
#include <QStandardPaths>
#include <QTextStream>

namespace Qvmessocket::components::autolaunch
{
    QString getUserAutostartDir_private()
    {
        QString config = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
        config += QLatin1String("/autostart/");
        return config;
    }

    bool GetLaunchAtLoginStatus()
    {
#ifdef Q_OS_WIN
        QString appName = QCoreApplication::applicationName();
        QSettings reg("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
        return reg.contains(appName);
    }

#elif defined Q_OS_LINUX
        QString appName = QCoreApplication::applicationName();
        QString desktopFileLocation = getUserAutostartDir_private() + appName + QLatin1String(".desktop");
        return QFile::exists(desktopFileLocation);
    }
#endif

    void SetLaunchAtLoginStatus(bool enable)
    {
#ifdef Q_OS_WIN
        QString appName = QCoreApplication::applicationName();
        QSettings reg("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);

        if (enable)
        {
            QString strAppPath = QDir::toNativeSeparators(QCoreApplication::applicationFilePath());
            reg.setValue(appName, strAppPath);
        }
        else
        {
            reg.remove(appName);
        }
    }

#elif defined Q_OS_LINUX
        //
        // For AppImage packaging.
        auto binPath = qEnvironmentVariableIsSet("APPIMAGE") ? qEnvironmentVariable("APPIMAGE") : QCoreApplication::applicationFilePath();
        //
        // From https://github.com/nextcloud/desktop/blob/master/src/common/utility_unix.cpp
        QString appName = QCoreApplication::applicationName();
        QString userAutoStartPath = getUserAutostartDir_private();
        QString desktopFileLocation = userAutoStartPath + appName + QLatin1String(".desktop");
        QStringList appCmdList = QCoreApplication::arguments();
        appCmdList.replace(0, binPath);

        if (enable)
        {
            if (!QDir().exists(userAutoStartPath) && !QDir().mkpath(userAutoStartPath))
            {
                // qCWarning(lcUtility) << "Could not create autostart folder"
                // << userAutoStartPath;
                return;
            }

            QFile iniFile(desktopFileLocation);

            if (!iniFile.open(QIODevice::WriteOnly))
            {
                // qCWarning(lcUtility) << "Could not write auto start entry" <<
                // desktopFileLocation;
                return;
            }

            QTextStream ts(&iniFile);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
            ts.setCodec("UTF-8");
#endif
            ts << QLatin1String("[Desktop Entry]") << NEWLINE                                 //
               << QLatin1String("Name=") << appName << NEWLINE                                //
               << QLatin1String("GenericName=") << QLatin1String("V2Ray Frontend") << NEWLINE //
               << QLatin1String("Exec=") << appCmdList.join(" ") << NEWLINE                   //
               << QLatin1String("Terminal=") << "false" << NEWLINE                            //
               << QLatin1String("Icon=") << "qv2ray" << NEWLINE                               //
               << QLatin1String("Categories=") << "Network" << NEWLINE                        //
               << QLatin1String("Type=") << "Application" << NEWLINE                          //
               << QLatin1String("StartupNotify=") << "false" << NEWLINE                       //
               << QLatin1String("X-GNOME-Autostart-enabled=") << "true" << NEWLINE;
            ts.flush();
            iniFile.close();
        }
        else
        {
            QFile::remove(desktopFileLocation);
            QFile::remove(desktopFileLocation.replace("qv2ray", "Qv2ray"));
        }
    }
#endif
}
