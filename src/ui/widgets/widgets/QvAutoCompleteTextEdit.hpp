#pragma once
#include <QAbstractItemModel>
#include <QPlainTextEdit>
QT_BEGIN_NAMESPACE
class QCompleter;
QT_END_NAMESPACE

namespace Qvmessocket::ui::widgets
{
    class AutoCompleteTextEdit : public QPlainTextEdit
    {
        Q_OBJECT

      public:
        AutoCompleteTextEdit(const QString &prefix, const QStringList &sourceStrings, QWidget *parent = nullptr);
        ~AutoCompleteTextEdit();

      protected:
        void keyPressEvent(QKeyEvent *e) override;
        void focusInEvent(QFocusEvent *e) override;

      private slots:
        void insertCompletion(const QString &completion);

      private:
        QString lineUnderCursor() const;
        QString wordUnderCursor() const;

        QString prefix;
        QCompleter *c = nullptr;
    };
}
using namespace Qvmessocket::ui::widgets;
