/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReplaceDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *labelFind;
    QLineEdit *editFind;
    QLabel *labelReplace;
    QLineEdit *editReplace;
    QGroupBox *groupDirection;
    QHBoxLayout *dirLayout;
    QRadioButton *radioUp;
    QRadioButton *radioDown;
    QCheckBox *chkCase;
    QVBoxLayout *rightColumn;
    QPushButton *btnFindNext;
    QPushButton *btnReplace;
    QPushButton *btnReplaceAll;
    QPushButton *btnClose;

    void setupUi(QDialog *ReplaceDialog)
    {
        if (ReplaceDialog->objectName().isEmpty())
            ReplaceDialog->setObjectName("ReplaceDialog");
        ReplaceDialog->setMinimumSize(QSize(540, 220));
        gridLayout = new QGridLayout(ReplaceDialog);
        gridLayout->setSpacing(8);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(8, 8, 8, 8);
        labelFind = new QLabel(ReplaceDialog);
        labelFind->setObjectName("labelFind");

        gridLayout->addWidget(labelFind, 0, 0, 1, 1);

        editFind = new QLineEdit(ReplaceDialog);
        editFind->setObjectName("editFind");
        editFind->setMinimumWidth(280);

        gridLayout->addWidget(editFind, 0, 1, 1, 1);

        labelReplace = new QLabel(ReplaceDialog);
        labelReplace->setObjectName("labelReplace");

        gridLayout->addWidget(labelReplace, 1, 0, 1, 1);

        editReplace = new QLineEdit(ReplaceDialog);
        editReplace->setObjectName("editReplace");
        editReplace->setMinimumWidth(280);

        gridLayout->addWidget(editReplace, 1, 1, 1, 1);

        groupDirection = new QGroupBox(ReplaceDialog);
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


        gridLayout->addWidget(groupDirection, 2, 0, 1, 2);

        chkCase = new QCheckBox(ReplaceDialog);
        chkCase->setObjectName("chkCase");

        gridLayout->addWidget(chkCase, 3, 0, 1, 2);

        rightColumn = new QVBoxLayout();
        rightColumn->setSpacing(8);
        rightColumn->setObjectName("rightColumn");
        btnFindNext = new QPushButton(ReplaceDialog);
        btnFindNext->setObjectName("btnFindNext");
        btnFindNext->setMinimumWidth(120);

        rightColumn->addWidget(btnFindNext);

        btnReplace = new QPushButton(ReplaceDialog);
        btnReplace->setObjectName("btnReplace");
        btnReplace->setMinimumWidth(120);

        rightColumn->addWidget(btnReplace);

        btnReplaceAll = new QPushButton(ReplaceDialog);
        btnReplaceAll->setObjectName("btnReplaceAll");
        btnReplaceAll->setMinimumWidth(120);

        rightColumn->addWidget(btnReplaceAll);

        btnClose = new QPushButton(ReplaceDialog);
        btnClose->setObjectName("btnClose");
        btnClose->setMinimumWidth(120);

        rightColumn->addWidget(btnClose);


        gridLayout->addLayout(rightColumn, 0, 2, 4, 1);


        retranslateUi(ReplaceDialog);
        QObject::connect(btnClose, &QPushButton::clicked, ReplaceDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(ReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplaceDialog)
    {
        ReplaceDialog->setWindowTitle(QCoreApplication::translate("ReplaceDialog", "\346\233\277\346\215\242", nullptr));
        labelFind->setText(QCoreApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\347\233\256\346\240\207:", nullptr));
        labelReplace->setText(QCoreApplication::translate("ReplaceDialog", "\346\233\277\346\215\242\344\270\272:", nullptr));
        groupDirection->setTitle(QCoreApplication::translate("ReplaceDialog", "\346\226\271\345\220\221", nullptr));
        radioUp->setText(QCoreApplication::translate("ReplaceDialog", "\345\220\221\344\270\212(&U)", nullptr));
        radioDown->setText(QCoreApplication::translate("ReplaceDialog", "\345\220\221\344\270\213(&D)", nullptr));
        chkCase->setText(QCoreApplication::translate("ReplaceDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        btnFindNext->setText(QCoreApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252(&F)", nullptr));
        btnReplace->setText(QCoreApplication::translate("ReplaceDialog", "\346\233\277\346\215\242(&R)", nullptr));
        btnReplaceAll->setText(QCoreApplication::translate("ReplaceDialog", "\345\205\250\351\203\250\346\233\277\346\215\242(&A)", nullptr));
        btnClose->setText(QCoreApplication::translate("ReplaceDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplaceDialog: public Ui_ReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
