#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QTextDocument>

namespace Ui { class ReplaceDialog; }

class ReplaceDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ReplaceDialog(QWidget* parent = nullptr);
    ~ReplaceDialog();
signals:
    void replaceOne(const QString& from, const QString& to, QTextDocument::FindFlags flags);
    void replaceAll(const QString& from, const QString& to, QTextDocument::FindFlags flags);
private slots:
    void onReplaceOne();
    void onReplaceAll();
private:
    Ui::ReplaceDialog* ui;
};

#endif // REPLACEDIALOG_H