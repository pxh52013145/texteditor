#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include "codeeditor.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionNew_triggered();
    void on_actionNewWindow_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionPrint_triggered();
    void on_actionExit_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionSelectAll_triggered();
    void on_actionFind_triggered();
    void on_actionReplace_triggered();
    void on_actionFont_triggered();
    void on_actionTextColor_triggered();
    void on_actionTextBackgroundColor_triggered();
    void on_actionBackgroundColor_triggered();
    void on_actionToggleLineNumbers_toggled(bool checked);
    void on_actionToggleWordWrap_toggled(bool checked);
    void on_actionToggleToolbar_toggled(bool checked);
    void on_actionToggleStatusBar_toggled(bool checked);
    void on_actionAbout_triggered();
    void on_actionAutoSave_toggled(bool checked);
    void updateWindowTitle(bool modified);
    void updateStatus();
    void updateClipboard();
    void doFindNext(const QString& text, QTextDocument::FindFlags flags);
    void doFindPrev(const QString& text, QTextDocument::FindFlags flags);
    void doReplaceOne(const QString& from, const QString& to, QTextDocument::FindFlags flags);
    void doReplaceAll(const QString& from, const QString& to, QTextDocument::FindFlags flags);
    void autosaveOnce();
private:
    Ui::MainWindow* ui;
    CodeEditor* editor;
    QString filePath;
    QTimer autosaveTimer;
    QLabel* statusInfo;
};

#endif // MAINWINDOW_H