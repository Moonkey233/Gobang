/********************************************************************************
** Form generated from reading UI file 'indexwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXWIDGET_H
#define UI_INDEXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IndexWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_offline;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btn_online;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btn_setting;
    QSpacerItem *verticalSpacer_4;
    QPushButton *btn_info;
    QSpacerItem *verticalSpacer_5;
    QPushButton *btn_exit;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *IndexWidget)
    {
        if (IndexWidget->objectName().isEmpty())
            IndexWidget->setObjectName(QString::fromUtf8("IndexWidget"));
        IndexWidget->resize(1280, 720);
        horizontalLayout = new QHBoxLayout(IndexWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(622, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_offline = new QPushButton(IndexWidget);
        btn_offline->setObjectName(QString::fromUtf8("btn_offline"));
        btn_offline->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        verticalLayout->addWidget(btn_offline);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btn_online = new QPushButton(IndexWidget);
        btn_online->setObjectName(QString::fromUtf8("btn_online"));
        btn_online->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        verticalLayout->addWidget(btn_online);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        btn_setting = new QPushButton(IndexWidget);
        btn_setting->setObjectName(QString::fromUtf8("btn_setting"));
        btn_setting->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        verticalLayout->addWidget(btn_setting);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        btn_info = new QPushButton(IndexWidget);
        btn_info->setObjectName(QString::fromUtf8("btn_info"));
        btn_info->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        verticalLayout->addWidget(btn_info);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        btn_exit = new QPushButton(IndexWidget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        verticalLayout->addWidget(btn_exit);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        verticalLayout->setStretch(0, 4);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 1);
        verticalLayout->setStretch(6, 1);
        verticalLayout->setStretch(7, 1);
        verticalLayout->setStretch(8, 1);
        verticalLayout->setStretch(9, 1);
        verticalLayout->setStretch(10, 4);

        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(309, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        retranslateUi(IndexWidget);

        QMetaObject::connectSlotsByName(IndexWidget);
    } // setupUi

    void retranslateUi(QWidget *IndexWidget)
    {
        IndexWidget->setWindowTitle(QCoreApplication::translate("IndexWidget", "Form", nullptr));
        btn_offline->setText(QCoreApplication::translate("IndexWidget", "OFFLINE GAME", nullptr));
        btn_online->setText(QCoreApplication::translate("IndexWidget", "ONLINE GAME", nullptr));
        btn_setting->setText(QCoreApplication::translate("IndexWidget", "GAME SETTINGS", nullptr));
        btn_info->setText(QCoreApplication::translate("IndexWidget", "GAME INFO", nullptr));
        btn_exit->setText(QCoreApplication::translate("IndexWidget", "EXIT GAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndexWidget: public Ui_IndexWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXWIDGET_H
