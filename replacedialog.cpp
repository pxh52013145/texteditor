#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QWidget* parent) : QDialog(parent), ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
    connect(ui->btnReplace, &QPushButton::clicked, this, &ReplaceDialog::onReplaceOne);
    connect(ui->btnReplaceAll, &QPushButton::clicked, this, &ReplaceDialog::onReplaceAll);
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
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