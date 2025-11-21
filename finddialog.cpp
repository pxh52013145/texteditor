#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget* parent) : QDialog(parent), ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    connect(ui->btnFindNext, &QPushButton::clicked, this, &FindDialog::onFindNext);
    connect(ui->btnFindPrev, &QPushButton::clicked, this, &FindDialog::onFindPrev);
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::onFindNext()
{
    QTextDocument::FindFlags flags;
    if (ui->chkCase->isChecked()) flags |= QTextDocument::FindCaseSensitively;
    emit findNext(ui->editText->text(), flags);
}

void FindDialog::onFindPrev()
{
    QTextDocument::FindFlags flags = QTextDocument::FindBackward;
    if (ui->chkCase->isChecked()) flags |= QTextDocument::FindCaseSensitively;
    emit findPrevious(ui->editText->text(), flags);
}