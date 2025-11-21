/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *editText;
    QCheckBox *chkCase;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnFindPrev;
    QPushButton *btnFindNext;
    QPushButton *btnClose;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName("FindDialog");
        verticalLayout = new QVBoxLayout(FindDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(FindDialog);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        editText = new QLineEdit(FindDialog);
        editText->setObjectName("editText");

        horizontalLayout->addWidget(editText);


        verticalLayout->addLayout(horizontalLayout);

        chkCase = new QCheckBox(FindDialog);
        chkCase->setObjectName("chkCase");

        verticalLayout->addWidget(chkCase);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnFindPrev = new QPushButton(FindDialog);
        btnFindPrev->setObjectName("btnFindPrev");

        horizontalLayout_2->addWidget(btnFindPrev);

        btnFindNext = new QPushButton(FindDialog);
        btnFindNext->setObjectName("btnFindNext");

        horizontalLayout_2->addWidget(btnFindNext);

        btnClose = new QPushButton(FindDialog);
        btnClose->setObjectName("btnClose");

        horizontalLayout_2->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FindDialog);
        QObject::connect(btnClose, &QPushButton::clicked, FindDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276", nullptr));
        label->setText(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276\345\206\205\345\256\271\357\274\232", nullptr));
        chkCase->setText(QCoreApplication::translate("FindDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        btnFindPrev->setText(QCoreApplication::translate("FindDialog", "\345\220\221\344\270\212\346\237\245\346\211\276", nullptr));
        btnFindNext->setText(QCoreApplication::translate("FindDialog", "\345\220\221\344\270\213\346\237\245\346\211\276", nullptr));
        btnClose->setText(QCoreApplication::translate("FindDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
