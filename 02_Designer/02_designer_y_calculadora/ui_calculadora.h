/********************************************************************************
** Form generated from reading UI file 'calculadora.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORA_H
#define UI_CALCULADORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculadora
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLCDNumber *lcdNumero;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *bSiete;
    QPushButton *bOcho;
    QPushButton *bNueve;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bCuatro;
    QPushButton *bCinco;
    QPushButton *bSeis;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *bUno;
    QPushButton *bDos;
    QPushButton *bTres;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *bCero;
    QPushButton *bPunto;
    QVBoxLayout *verticalLayout_2;
    QPushButton *bSumar;
    QPushButton *bIgual;

    void setupUi(QDialog *Calculadora)
    {
        if (Calculadora->objectName().isEmpty())
            Calculadora->setObjectName(QString::fromUtf8("Calculadora"));
        Calculadora->resize(429, 300);
        widget = new QWidget(Calculadora);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 421, 271));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lcdNumero = new QLCDNumber(widget);
        lcdNumero->setObjectName(QString::fromUtf8("lcdNumero"));
        lcdNumero->setDigitCount(12);

        verticalLayout_3->addWidget(lcdNumero);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bSiete = new QPushButton(widget);
        bSiete->setObjectName(QString::fromUtf8("bSiete"));

        horizontalLayout->addWidget(bSiete);

        bOcho = new QPushButton(widget);
        bOcho->setObjectName(QString::fromUtf8("bOcho"));

        horizontalLayout->addWidget(bOcho);

        bNueve = new QPushButton(widget);
        bNueve->setObjectName(QString::fromUtf8("bNueve"));

        horizontalLayout->addWidget(bNueve);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        bCuatro = new QPushButton(widget);
        bCuatro->setObjectName(QString::fromUtf8("bCuatro"));

        horizontalLayout_2->addWidget(bCuatro);

        bCinco = new QPushButton(widget);
        bCinco->setObjectName(QString::fromUtf8("bCinco"));

        horizontalLayout_2->addWidget(bCinco);

        bSeis = new QPushButton(widget);
        bSeis->setObjectName(QString::fromUtf8("bSeis"));

        horizontalLayout_2->addWidget(bSeis);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        bUno = new QPushButton(widget);
        bUno->setObjectName(QString::fromUtf8("bUno"));

        horizontalLayout_3->addWidget(bUno);

        bDos = new QPushButton(widget);
        bDos->setObjectName(QString::fromUtf8("bDos"));

        horizontalLayout_3->addWidget(bDos);

        bTres = new QPushButton(widget);
        bTres->setObjectName(QString::fromUtf8("bTres"));

        horizontalLayout_3->addWidget(bTres);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        bCero = new QPushButton(widget);
        bCero->setObjectName(QString::fromUtf8("bCero"));

        horizontalLayout_4->addWidget(bCero);

        bPunto = new QPushButton(widget);
        bPunto->setObjectName(QString::fromUtf8("bPunto"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bPunto->sizePolicy().hasHeightForWidth());
        bPunto->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(bPunto);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        bSumar = new QPushButton(widget);
        bSumar->setObjectName(QString::fromUtf8("bSumar"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bSumar->sizePolicy().hasHeightForWidth());
        bSumar->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(bSumar);

        bIgual = new QPushButton(widget);
        bIgual->setObjectName(QString::fromUtf8("bIgual"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bIgual->sizePolicy().hasHeightForWidth());
        bIgual->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(bIgual);


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_5);


        retranslateUi(Calculadora);

        QMetaObject::connectSlotsByName(Calculadora);
    } // setupUi

    void retranslateUi(QDialog *Calculadora)
    {
        Calculadora->setWindowTitle(QCoreApplication::translate("Calculadora", "Dialog", nullptr));
        bSiete->setText(QCoreApplication::translate("Calculadora", "7", nullptr));
        bOcho->setText(QCoreApplication::translate("Calculadora", "8", nullptr));
        bNueve->setText(QCoreApplication::translate("Calculadora", "9", nullptr));
        bCuatro->setText(QCoreApplication::translate("Calculadora", "4", nullptr));
        bCinco->setText(QCoreApplication::translate("Calculadora", "5", nullptr));
        bSeis->setText(QCoreApplication::translate("Calculadora", "6", nullptr));
        bUno->setText(QCoreApplication::translate("Calculadora", "1", nullptr));
        bDos->setText(QCoreApplication::translate("Calculadora", "2", nullptr));
        bTres->setText(QCoreApplication::translate("Calculadora", "3", nullptr));
        bCero->setText(QCoreApplication::translate("Calculadora", "0", nullptr));
        bPunto->setText(QCoreApplication::translate("Calculadora", ".", nullptr));
        bSumar->setText(QCoreApplication::translate("Calculadora", "+", nullptr));
        bIgual->setText(QCoreApplication::translate("Calculadora", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculadora: public Ui_Calculadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORA_H
