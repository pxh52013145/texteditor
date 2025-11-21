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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *row1;
    QLabel *label;
    QLineEdit *editText;
    QPushButton *btnFindNext;
    QGroupBox *groupDirection;
    QHBoxLayout *dirLayout;
    QRadioButton *radioUp;
    QRadioButton *radioDown;
    QHBoxLayout *row3;
    QCheckBox *chkCase;
    QSpacerItem *spacer;
    QPushButton *btnClose;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName("FindDialog");
        FindDialog->setMinimumSize(QSize(420, 160));
        verticalLayout = new QVBoxLayout(FindDialog);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        row1 = new QHBoxLayout();
        row1->setObjectName("row1");
        label = new QLabel(FindDialog);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignVCenter);

        row1->addWidget(label);

        editText = new QLineEdit(FindDialog);
        editText->setObjectName("editText");
        editText->setMinimumWidth(240);

        row1->addWidget(editText);

        btnFindNext = new QPushButton(FindDialog);
        btnFindNext->setObjectName("btnFindNext");
        btnFindNext->setMinimumWidth(110);

        row1->addWidget(btnFindNext);


        verticalLayout->addLayout(row1);

        groupDirection = new QGroupBox(FindDialog);
        groupDirection->setObjectName("groupDirection");
        dirLayout = new QHBoxLayout(groupDirection);
        dirLayout->setObjectName("dirLayout");
        radioUp = new QRadioButton(groupDirection);
        radioUp->setObjectName("radioUp");

        dirLayout->addWidget(radioUp);

        radioDown = new QRadioButton(groupDirection);
        radioDown->setObjectName("radioDown");
        radioDown->setChecked(true);

        dirLayout->addWidget(radioDown);


        verticalLayout->addWidget(groupDirection);

        row3 = new QHBoxLayout();
        row3->setObjectName("row3");
        chkCase = new QCheckBox(FindDialog);
        chkCase->setObjectName("chkCase");

        row3->addWidget(chkCase);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        row3->addItem(spacer);

        btnClose = new QPushButton(FindDialog);
        btnClose->setObjectName("btnClose");
        btnClose->setMinimumWidth(110);

        row3->addWidget(btnClose);


        verticalLayout->addLayout(row3);


        retranslateUi(FindDialog);
        QObject::connect(btnClose, &QPushButton::clicked, FindDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276", nullptr));
        label->setText(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276\347\233\256\346\240\207:", nullptr));
        btnFindNext->setText(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252(&F)", nullptr));
        groupDirection->setTitle(QCoreApplication::translate("FindDialog", "\346\226\271\345\220\221", nullptr));
        radioUp->setText(QCoreApplication::translate("FindDialog", "\345\220\221\344\270\212(&U)", nullptr));
        radioDown->setText(QCoreApplication::translate("FindDialog", "\345\220\221\344\270\213(&D)", nullptr));
        chkCase->setText(QCoreApplication::translate("FindDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        btnClose->setText(QCoreApplication::translate("FindDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
