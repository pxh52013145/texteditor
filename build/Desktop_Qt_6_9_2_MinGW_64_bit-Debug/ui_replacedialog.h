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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReplaceDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelFind;
    QLineEdit *editFind;
    QLabel *labelReplace;
    QLineEdit *editReplace;
    QCheckBox *chkCase;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnReplace;
    QPushButton *btnReplaceAll;
    QPushButton *btnClose;

    void setupUi(QDialog *ReplaceDialog)
    {
        if (ReplaceDialog->objectName().isEmpty())
            ReplaceDialog->setObjectName("ReplaceDialog");
        verticalLayout = new QVBoxLayout(ReplaceDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelFind = new QLabel(ReplaceDialog);
        labelFind->setObjectName("labelFind");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelFind);

        editFind = new QLineEdit(ReplaceDialog);
        editFind->setObjectName("editFind");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, editFind);

        labelReplace = new QLabel(ReplaceDialog);
        labelReplace->setObjectName("labelReplace");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelReplace);

        editReplace = new QLineEdit(ReplaceDialog);
        editReplace->setObjectName("editReplace");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, editReplace);


        verticalLayout->addLayout(formLayout);

        chkCase = new QCheckBox(ReplaceDialog);
        chkCase->setObjectName("chkCase");

        verticalLayout->addWidget(chkCase);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnReplace = new QPushButton(ReplaceDialog);
        btnReplace->setObjectName("btnReplace");

        horizontalLayout->addWidget(btnReplace);

        btnReplaceAll = new QPushButton(ReplaceDialog);
        btnReplaceAll->setObjectName("btnReplaceAll");

        horizontalLayout->addWidget(btnReplaceAll);

        btnClose = new QPushButton(ReplaceDialog);
        btnClose->setObjectName("btnClose");

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ReplaceDialog);
        QObject::connect(btnClose, &QPushButton::clicked, ReplaceDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(ReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplaceDialog)
    {
        ReplaceDialog->setWindowTitle(QCoreApplication::translate("ReplaceDialog", "\346\233\277\346\215\242", nullptr));
        labelFind->setText(QCoreApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\345\206\205\345\256\271\357\274\232", nullptr));
        labelReplace->setText(QCoreApplication::translate("ReplaceDialog", "\346\233\277\346\215\242\344\270\272\357\274\232", nullptr));
        chkCase->setText(QCoreApplication::translate("ReplaceDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        btnReplace->setText(QCoreApplication::translate("ReplaceDialog", "\346\233\277\346\215\242", nullptr));
        btnReplaceAll->setText(QCoreApplication::translate("ReplaceDialog", "\345\205\250\351\203\250\346\233\277\346\215\242", nullptr));
        btnClose->setText(QCoreApplication::translate("ReplaceDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplaceDialog: public Ui_ReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
