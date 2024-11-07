/********************************************************************************
** Form generated from reading UI file 'dprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPRINCIPAL_H
#define UI_DPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DPrincipal
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *bMenus;
    QPushButton *bRealizarPedido;

    void setupUi(QDialog *DPrincipal)
    {
        if (DPrincipal->objectName().isEmpty())
            DPrincipal->setObjectName(QString::fromUtf8("DPrincipal"));
        DPrincipal->resize(400, 300);
        buttonBox = new QDialogButtonBox(DPrincipal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(220, 260, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        bMenus = new QPushButton(DPrincipal);
        bMenus->setObjectName(QString::fromUtf8("bMenus"));
        bMenus->setGeometry(QRect(10, 230, 80, 25));
        bRealizarPedido = new QPushButton(DPrincipal);
        bRealizarPedido->setObjectName(QString::fromUtf8("bRealizarPedido"));
        bRealizarPedido->setGeometry(QRect(100, 230, 291, 25));

        retranslateUi(DPrincipal);
        QObject::connect(buttonBox, SIGNAL(accepted()), DPrincipal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DPrincipal, SLOT(reject()));

        QMetaObject::connectSlotsByName(DPrincipal);
    } // setupUi

    void retranslateUi(QDialog *DPrincipal)
    {
        DPrincipal->setWindowTitle(QCoreApplication::translate("DPrincipal", "Dialog", nullptr));
        bMenus->setText(QCoreApplication::translate("DPrincipal", "Men\303\272s", nullptr));
        bRealizarPedido->setText(QCoreApplication::translate("DPrincipal", "RealizarPedido", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DPrincipal: public Ui_DPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPRINCIPAL_H
