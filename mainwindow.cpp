#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finddialog.h"
#include "replacedialog.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QClipboard>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow), editor(nullptr), statusInfo(new QLabel(this))
{
    ui->setupUi(this);
    editor = qobject_cast<CodeEditor*>(ui->plainTextEdit);
    if (!editor) editor = new CodeEditor(this), setCentralWidget(editor);
    QAction* actionTextBg = new QAction("字体背景色...", this);
    ui->menuFormat->insertAction(ui->actionBackgroundColor, actionTextBg);
    connect(actionTextBg, &QAction::triggered, this, &MainWindow::on_actionTextBackgroundColor_triggered);
    ui->actionToggleLineNumbers->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));
    setWindowTitle("未命名 - 文本编辑器");
    statusBar()->addPermanentWidget(statusInfo);
    connect(editor->document(), &QTextDocument::modificationChanged, this, &MainWindow::updateWindowTitle);
    connect(editor, &CodeEditor::cursorPositionChanged, this, &MainWindow::updateStatus);
    connect(editor, &CodeEditor::blockCountChanged, this, &MainWindow::updateStatus);
    connect(editor, &CodeEditor::copyAvailable, ui->actionCut, &QAction::setEnabled);
    connect(editor, &CodeEditor::copyAvailable, ui->actionCopy, &QAction::setEnabled);
    connect(QApplication::clipboard(), &QClipboard::dataChanged, this, &MainWindow::updateClipboard);
    updateClipboard();
    updateStatus();
    autosaveTimer.setInterval(60000);
    connect(&autosaveTimer, &QTimer::timeout, this, &MainWindow::autosaveOnce);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionNew_triggered()
{
    editor->clear();
    editor->document()->setModified(false);
    filePath.clear();
    setWindowTitle("未命名 - 文本编辑器");
}

void MainWindow::on_actionNewWindow_triggered()
{
    MainWindow* w = new MainWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
}

void MainWindow::on_actionOpen_triggered()
{
    QString name = QFileDialog::getOpenFileName(this, "打开文件");
    if (name.isEmpty()) return;
    QFile f(name);
    if (!f.open(QFile::ReadOnly | QFile::Text)) { QMessageBox::warning(this, "提示", "无法打开文件"); return; }
    QTextStream in(&f);
    editor->setPlainText(in.readAll());
    f.close();
    filePath = name;
    editor->document()->setModified(false);
    setWindowTitle(QFileInfo(filePath).fileName() + " - 文本编辑器");
}

void MainWindow::on_actionSave_triggered()
{
    if (filePath.isEmpty()) { on_actionSaveAs_triggered(); return; }
    QFile f(filePath);
    if (!f.open(QFile::WriteOnly | QFile::Text)) { QMessageBox::warning(this, "提示", "无法保存文件"); return; }
    QTextStream out(&f);
    out << editor->toPlainText();
    f.flush();
    f.close();
    editor->document()->setModified(false);
}

void MainWindow::on_actionSaveAs_triggered()
{
    QString name = QFileDialog::getSaveFileName(this, "另存为");
    if (name.isEmpty()) return;
    filePath = name;
    on_actionSave_triggered();
    setWindowTitle(QFileInfo(filePath).fileName() + " - 文本编辑器");
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    if (dlg.exec() != QDialog::Accepted) return;
    editor->document()->print(&printer);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionUndo_triggered() { editor->undo(); }
void MainWindow::on_actionRedo_triggered() { editor->redo(); }
void MainWindow::on_actionCut_triggered() { editor->cut(); }
void MainWindow::on_actionCopy_triggered() { editor->copy(); }
void MainWindow::on_actionPaste_triggered() { editor->paste(); }
void MainWindow::on_actionSelectAll_triggered() { editor->selectAll(); }

void MainWindow::on_actionFind_triggered()
{
    FindDialog* dlg = new FindDialog(this);
    connect(dlg, &FindDialog::findNext, this, &MainWindow::doFindNext);
    connect(dlg, &FindDialog::findPrevious, this, &MainWindow::doFindPrev);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->show();
}

void MainWindow::on_actionReplace_triggered()
{
    ReplaceDialog* dlg = new ReplaceDialog(this);
    connect(dlg, &ReplaceDialog::replaceOne, this, &MainWindow::doReplaceOne);
    connect(dlg, &ReplaceDialog::replaceAll, this, &MainWindow::doReplaceAll);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->show();
}

void MainWindow::on_actionFont_triggered()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, editor->font(), this);
    if (ok) editor->setFont(font);
}

void MainWindow::on_actionTextColor_triggered()
{
    QColor c = QColorDialog::getColor(editor->palette().text().color(), this, "字体颜色");
    if (c.isValid()) { QPalette p = editor->palette(); p.setColor(QPalette::Text, c); editor->setPalette(p); }
}

void MainWindow::on_actionBackgroundColor_triggered()
{
    QColor c = QColorDialog::getColor(editor->palette().base().color(), this, "背景色");
    if (c.isValid()) { QPalette p = editor->palette(); p.setColor(QPalette::Base, c); editor->setPalette(p); }
}

void MainWindow::on_actionTextBackgroundColor_triggered()
{
    QColor c = QColorDialog::getColor(Qt::yellow, this, "字体背景色");
    if (!c.isValid()) return;
    QTextCursor cursor(editor->document());
    cursor.select(QTextCursor::Document);
    QTextCharFormat fmt;
    fmt.setBackground(c);
    cursor.mergeCharFormat(fmt);
}

void MainWindow::on_actionToggleLineNumbers_toggled(bool checked)
{
    editor->setLineNumbersVisible(checked);
}

void MainWindow::on_actionToggleWordWrap_toggled(bool checked)
{
    editor->setLineWrapMode(checked ? QPlainTextEdit::WidgetWidth : QPlainTextEdit::NoWrap);
}

void MainWindow::on_actionToggleToolbar_toggled(bool checked)
{
    ui->mainToolBar->setVisible(checked);
}

void MainWindow::on_actionToggleStatusBar_toggled(bool checked)
{
    statusBar()->setVisible(checked);
}

void MainWindow::on_actionAbout_triggered()
{
    QString t = "作者: 学生\n实验: LAB2 多窗口文本编辑器\n参考: Qt 文档";
    QMessageBox::about(this, "关于", t);
}

void MainWindow::on_actionAutoSave_toggled(bool checked)
{
    if (checked) autosaveTimer.start(); else autosaveTimer.stop();
}

void MainWindow::updateWindowTitle(bool modified)
{
    QString name = filePath.isEmpty() ? "未命名" : QFileInfo(filePath).fileName();
    setWindowTitle(name + (modified ? "*" : "") + " - 文本编辑器");
}

void MainWindow::updateStatus()
{
    statusInfo->setText(QString("Ln %1, Col %2  %3")
        .arg(editor->currentLine()).arg(editor->currentColumn())
        .arg(editor->lineNumbersVisible() ? "行号:开" : "行号:关"));
}

void MainWindow::updateClipboard()
{
    bool has = !QApplication::clipboard()->text().isEmpty();
    ui->actionPaste->setEnabled(has);
}

void MainWindow::doFindNext(const QString& text, QTextDocument::FindFlags flags)
{
    if (!editor->find(text, flags)) QMessageBox::information(this, "查找", "未找到");
}

void MainWindow::doFindPrev(const QString& text, QTextDocument::FindFlags flags)
{
    if (!editor->find(text, flags | QTextDocument::FindBackward)) QMessageBox::information(this, "查找", "未找到");
}

void MainWindow::doReplaceOne(const QString& from, const QString& to, QTextDocument::FindFlags flags)
{
    QTextCursor c = editor->textCursor();
    if (c.hasSelection() && c.selectedText() == from) c.insertText(to);
    editor->find(from, flags);
}

void MainWindow::doReplaceAll(const QString& from, const QString& to, QTextDocument::FindFlags flags)
{
    QTextCursor c(editor->document());
    c.beginEditBlock();
    while (true) {
        QTextCursor found = editor->document()->find(from, c, flags);
        if (found.isNull()) break;
        found.insertText(to);
        c = found;
    }
    c.endEditBlock();
}

void MainWindow::autosaveOnce()
{
    if (!filePath.isEmpty() && editor->document()->isModified()) on_actionSave_triggered();
}