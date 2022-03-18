#include "QvAutoCompleteTextEdit.hpp"

#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QApplication>
#include <QCompleter>
#include <QKeyEvent>
#include <QModelIndex>
#include <QScrollBar>
#include <QStringListModel>
#include <QToolTip>
#include <QtDebug>

namespace Qvmessocket::ui::widgets
{
    AutoCompleteTextEdit::AutoCompleteTextEdit(const QString &prefix, const QStringList &sourceStrings, QWidget *parent) : QPlainTextEdit(parent)
    {
        this->prefix = prefix;
        this->setLineWrapMode(QPlainTextEdit::NoWrap);
        c = new QCompleter(this);
        c->setModel(new QStringListModel(sourceStrings, c));
        c->setWidget(this);
        c->setCompletionMode(QCompleter::PopupCompletion);
        c->setCaseSensitivity(Qt::CaseInsensitive);
        QObject::connect(c, QOverload<const QString &>::of(&QCompleter::activated), this, &AutoCompleteTextEdit::insertCompletion);
    }

    AutoCompleteTextEdit::~AutoCompleteTextEdit()
    {
    }

    void AutoCompleteTextEdit::insertCompletion(const QString &completion)
    {
        QTextCursor tc = textCursor();
        int extra = completion.length() - c->completionPrefix().length();
        tc.movePosition(QTextCursor::Left);
        tc.movePosition(QTextCursor::EndOfWord);
        tc.insertText(completion.right(extra));
        setTextCursor(tc);
    }

    QString AutoCompleteTextEdit::lineUnderCursor() const
    {
        QTextCursor tc = textCursor();
        tc.select(QTextCursor::LineUnderCursor);
        return tc.selectedText();
    }

    QString AutoCompleteTextEdit::wordUnderCursor() const
    {
        QTextCursor tc = textCursor();
        tc.select(QTextCursor::WordUnderCursor);
        return tc.selectedText();
    }

    void AutoCompleteTextEdit::focusInEvent(QFocusEvent *e)
    {
        if (c)
            c->setWidget(this);

        QPlainTextEdit::focusInEvent(e);
    }

    void AutoCompleteTextEdit::keyPressEvent(QKeyEvent *e)
    {
        const bool hasCtrlOrShiftModifier = e->modifiers().testFlag(Qt::ControlModifier) || e->modifiers().testFlag(Qt::ShiftModifier);
        const bool hasOtherModifiers = (e->modifiers() != Qt::NoModifier) && !hasCtrlOrShiftModifier; // has other modifiers
        //
        const bool isSpace = (e->modifiers().testFlag(Qt::ShiftModifier) || e->modifiers().testFlag(Qt::NoModifier)) //
                             && e->key() == Qt::Key_Space;
        const bool isTab = (e->modifiers().testFlag(Qt::NoModifier) && e->key() == Qt::Key_Tab);
        const bool isOtherSpace = e->text() == "　";
        //
        if (isSpace || isTab || isOtherSpace)
        {
            QToolTip::showText(this->mapToGlobal(QPoint(0, 0)), tr("You can not input space characters here."), this, QRect{}, 2000);
            return;
        }
        //
        if (c && c->popup()->isVisible())
        {
            // The following keys are forwarded by the completer to the widget
            switch (e->key())
            {
                case Qt::Key_Enter:
                case Qt::Key_Return:
                case Qt::Key_Escape:
                case Qt::Key_Tab:
                case Qt::Key_Backtab: e->ignore(); return; // let the completer do default behavior

                default: break;
            }
        }

        QPlainTextEdit::keyPressEvent(e);

        if (!c || (hasCtrlOrShiftModifier && e->text().isEmpty()))
            return;

        // if we have other modifiers, or the text is empty, or the line does not start with our prefix.
        if (hasOtherModifiers || e->text().isEmpty() || !lineUnderCursor().startsWith(prefix))
        {
            c->popup()->hide();
            return;
        }

        if (auto word = wordUnderCursor(); word != c->completionPrefix())
        {
            c->setCompletionPrefix(word);
            c->popup()->setCurrentIndex(c->completionModel()->index(0, 0));
        }

        QRect cr = cursorRect();
        cr.setWidth(c->popup()->sizeHintForColumn(0) + c->popup()->verticalScrollBar()->sizeHint().width());
        c->complete(cr); // popup it up!
    }
}
