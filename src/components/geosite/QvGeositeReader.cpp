#include "QvGeositeReader.hpp"

#define QV_MODULE_NAME "GeositeReader"

namespace Qvmessocket::components::geosite
{
    QMap<QString, QStringList> GeositeEntries;
    QStringList ReadGeoSiteFromFile(const QString &filepath)
    {
        if (GeositeEntries.contains(filepath))
        {
            return GeositeEntries.value(filepath);
        }
        else
        {
            QStringList list;
            list.sort();
            GeositeEntries[filepath] = list;
            return list;
        }
    }
}
