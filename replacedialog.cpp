#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QWidget* parent) : QDialog(parent), ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
    connect(ui->btnFindNext, &QPushButton::clicked, this, &ReplaceDialog::onFindNext);
    connect(ui->btnReplace, &QPushButton::clicked, this, &ReplaceDialog::onReplaceOne);
    connect(ui->btnReplaceAll, &QPushButton::clicked, this, &ReplaceDialog::onReplaceAll);
    ui->btnFindNext->setEnabled(false);
    ui->btnReplace->setEnabled(false);
    ui->btnReplaceAll->setEnabled(false);
    auto upd = [this](const QString& s){
        bool en = !s.isEmpty();
        ui->btnFindNext->setEnabled(en);
        ui->btnReplace->setEnabled(en);
        ui->btnReplaceAll->setEnabled(en);
    };
    connect(ui->editFind, &QLineEdit::textChanged, this, upd);
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

void ReplaceDialog::onFindNext()
{
    QTextDocument::FindFlags flags;
    if (ui->chkCase->isChecked()) flags |= QTextDocument::FindCaseSensitively;
    if (ui->radioUp && ui->radioUp->isChecked()) flags |= QTextDocument::FindBackward;
    emit findNext(ui->editFind->text(), flags);
}

void ReplaceDialog::onReplaceOne()
{
    QTextDocument::FindFlags flags;
    if (ui->chkCase->isChecked()) flags |= QTextDocument::FindCaseSensitively;
    emit replaceOne(ui->editFind->text(), ui->editReplace->text(), flags);
}

void ReplaceDialog::onReplaceAll()
{
    QTextDocument::FindFlags flags;
    if (ui->chkCase->isChecked()) flags |= QTextDocument::FindCaseSensitively;
    emit replaceAll(ui->editFind->text(), ui->editReplace->text(), flags);
}