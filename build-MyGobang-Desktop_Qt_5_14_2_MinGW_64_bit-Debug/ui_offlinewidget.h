/********************************************************************************
** Form generated from reading UI file 'offlinewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFFLINEWIDGET_H
#define UI_OFFLINEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OfflineWidget
{
public:
    QPushButton *btn_ai_first;
    QPushButton *btn_human_first;
    QPushButton *btn_hotseat;
    QPushButton *btn_return;

    void setupUi(QWidget *OfflineWidget)
    {
        if (OfflineWidget->objectName().isEmpty())
            OfflineWidget->setObjectName(QString::fromUtf8("OfflineWidget"));
        OfflineWidget->resize(1280, 720);
        btn_ai_first = new QPushButton(OfflineWidget);
        btn_ai_first->setObjectName(QString::fromUtf8("btn_ai_first"));
        btn_ai_first->setGeometry(QRect(410, 90, 200, 50));
        btn_ai_first->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_human_first = new QPushButton(OfflineWidget);
        btn_human_first->setObjectName(QString::fromUtf8("btn_human_first"));
        btn_human_first->setGeometry(QRect(410, 180, 200, 50));
        btn_human_first->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_hotseat = new QPushButton(OfflineWidget);
        btn_hotseat->setObjectName(QString::fromUtf8("btn_hotseat"));
        btn_hotseat->setGeometry(QRect(410, 280, 200, 50));
        btn_hotseat->setLayoutDirection(Qt::LeftToRight);
        btn_hotseat->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_return = new QPushButton(OfflineWidget);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));
        btn_return->setGeometry(QRect(410, 380, 200, 50));
        btn_return->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        retranslateUi(OfflineWidget);

        QMetaObject::connectSlotsByName(OfflineWidget);
    } // setupUi

    void retranslateUi(QWidget *OfflineWidget)
    {
        OfflineWidget->setWindowTitle(QCoreApplication::translate("OfflineWidget", "Form", nullptr));
        btn_ai_first->setText(QCoreApplication::translate("OfflineWidget", "AI FIRST", nullptr));
        btn_human_first->setText(QCoreApplication::translate("OfflineWidget", "HUMAN FIRST", nullptr));
        btn_hotseat->setText(QCoreApplication::translate("OfflineWidget", "HOTSEAT MODE", nullptr));
        btn_return->setText(QCoreApplication::translate("OfflineWidget", "RETURN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OfflineWidget: public Ui_OfflineWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFFLINEWIDGET_H
