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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DPrincipal
{
public:
    QPushButton *bMenus;
    QPushButton *bPedido;

    void setupUi(QDialog *DPrincipal)
    {
        if (DPrincipal->objectName().isEmpty())
            DPrincipal->setObjectName(QString::fromUtf8("DPrincipal"));
        DPrincipal->resize(400, 300);
        bMenus = new QPushButton(DPrincipal);
        bMenus->setObjectName(QString::fromUtf8("bMenus"));
        bMenus->setGeometry(QRect(50, 260, 80, 25));
        bPedido = new QPushButton(DPrincipal);
        bPedido->setObjectName(QString::fromUtf8("bPedido"));
        bPedido->setGeometry(QRect(220, 260, 151, 25));

        retranslateUi(DPrincipal);

        QMetaObject::connectSlotsByName(DPrincipal);
    } // setupUi

    void retranslateUi(QDialog *DPrincipal)
    {
        DPrincipal->setWindowTitle(QCoreApplication::translate("DPrincipal", "Dialog", nullptr));
        bMenus->setText(QCoreApplication::translate("DPrincipal", "Men\303\272s", nullptr));
        bPedido->setText(QCoreApplication::translate("DPrincipal", "Realizar pedido", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DPrincipal: public Ui_DPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPRINCIPAL_H
