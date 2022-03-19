#include "Qv2rayCliApplication.hpp"

Qv2rayCliApplication::Qv2rayCliApplication(int &argc, char *argv[]) : Qv2rayPlatformApplication(argc, argv)
{
}

QStringList Qv2rayCliApplication::checkPrerequisitesInternal()
{
    return {};
}
QvExitReason Qv2rayCliApplication::runQv2rayInternal()
{
    return (QvExitReason) exec();
}

void Qv2rayCliApplication::terminateUIInternal()
{
}

#ifndef QV2RAY_NO_SINGLEAPPLICATON
void Qv2rayCliApplication::onMessageReceived(quint32 clientID, QByteArray msg)
{
}
#endif
