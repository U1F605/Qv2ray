#pragma once

class QImage;
class QSize;
class QString;

namespace Qvmessocket::ui
{
    QString DecodeQRCode(const QImage &img);
    QImage EncodeQRCode(const QString content, int size);
} // namespace Qv2ray::ui
using namespace Qvmessocket::ui;
