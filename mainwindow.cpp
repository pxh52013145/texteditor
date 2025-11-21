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
    experimenterName = QStringLiteral("潘翾寰");
    connect(ui->actionTextBackgroundColor, &QAction::triggered, this, &MainWindow::on_actionTextBackgroundColor_triggered);
    ui->actionToggleLineNumbers->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));
    setWindowTitle("未命名 - 文本编辑器");
    statusBar()->addPermanentWidget(statusInfo);
    connect(editor->document(), &QTextDocument::modificationChanged, this, &MainWindow::updateWindowTitle);
    connect(editor, &CodeEditor::cursorPositionChanged, this, &MainWindow::updateStatus);
    connect(editor, &CodeEditor::blockCountChanged, this, &MainWindow::updateStatus);
    connect(editor, &CodeEditor::textChanged, this, &MainWindow::updateStatus);
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
    connect(dlg, &ReplaceDialog::findNext, this, &MainWindow::doFindNext);
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
    QMessageBox box(this);
    box.setWindowTitle("关于");
    box.setIcon(QMessageBox::Information);
    box.setTextFormat(Qt::RichText);
    QString t = QString(
        "<div style='min-width:360px;background-color:#2b2b2b;padding:12px;border-radius:6px;color:#fff'>"
        "<div style='font-size:28px;font-weight:bold;margin-bottom:12px;color:#fff'>文本编辑器</div>"
        "<div style='color:#fff;margin:8px 0;font-size:14px'>开发者：%1<br>学号：2023414290320<br>email：3162524860@qq.com</div>"
        "<div style='margin-top:12px;color:#fff'>V1.0 build 202110</div>"
        "</div>").arg(experimenterName);
    box.setText(t);
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
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
    QString name = experimenterName.isEmpty() ? QStringLiteral("用户") : experimenterName;
    int len = editor->toPlainText().length();
    int lines = editor->document()->blockCount();
    statusInfo->setText(QString("length: %1  lines: %2  Ln: %3  Col: %4  %5")
        .arg(len).arg(lines).arg(editor->currentLine()).arg(editor->currentColumn()).arg(name));
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