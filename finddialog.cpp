#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget* parent) : QDialog(parent), ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    connect(ui->btnFindNext, &QPushButton::clicked, this, &FindDialog::onFindNext);
    ui->btnFindNext->setEnabled(false);
    connect(ui->editText, &QLineEdit::textChanged, this, [this](const QString& s){ ui->btnFindNext->setEnabled(!s.isEmpty()); });
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::onFindNext()
{
    QTextDocument::FindFlags flags;
    if (ui->chkCase->isChecked()) flags |= QTextDocument::FindCaseSensitively;
    if (ui->radioUp && ui->radioUp->isChecked()) flags |= QTextDocument::FindBackward;
    if (flags.testFlag(QTextDocument::FindBackward))
        emit findPrevious(ui->editText->text(), flags);
    else
        emit findNext(ui->editText->text(), flags);
}