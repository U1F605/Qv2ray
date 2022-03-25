#include "DarkmodeDetector.hpp"

#include "base/QvBase.hpp"

#include <QApplication>
#include <QStyle>
#ifdef Q_OS_LINUX
#elif defined(Q_OS_WIN32)
#include <QSettings>
#endif

namespace Qvmessocket::components::darkmode
{
    bool isDarkMode()
    {
#if defined(Q_OS_WIN32)
        QSettings settings(R"(HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize)", QSettings::NativeFormat);
        return settings.value("AppsUseLightTheme", 1).toInt() == 0;
#endif

        if (!qApp || !qApp->style())
        {
            return false;
        }
        return qApp->style()->standardPalette().color(QPalette::Window).toHsl().lightness() < 110;
    }

}
