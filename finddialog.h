#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QTextDocument>

namespace Ui { class FindDialog; }

class FindDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FindDialog(QWidget* parent = nullptr);
    ~FindDialog();
signals:
    void findNext(const QString& text, QTextDocument::FindFlags flags);
    void findPrevious(const QString& text, QTextDocument::FindFlags flags);
private slots:
    void onFindNext();
private:
    Ui::FindDialog* ui;
};

#endif // FINDDIALOG_H