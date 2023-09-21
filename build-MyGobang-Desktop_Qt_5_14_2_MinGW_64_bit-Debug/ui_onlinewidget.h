/********************************************************************************
** Form generated from reading UI file 'onlinewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINEWIDGET_H
#define UI_ONLINEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OnlineWidget
{
public:
    QPushButton *btn_match;
    QPushButton *btn_rank;
    QPushButton *btn_history;
    QPushButton *btn_logout;
    QPushButton *btn_change;
    QPushButton *btn_exit;
    QPushButton *btn_setting;
    QPushButton *btn_create;
    QPushButton *btn_join;

    void setupUi(QWidget *OnlineWidget)
    {
        if (OnlineWidget->objectName().isEmpty())
            OnlineWidget->setObjectName(QString::fromUtf8("OnlineWidget"));
        OnlineWidget->resize(1280, 720);
        btn_match = new QPushButton(OnlineWidget);
        btn_match->setObjectName(QString::fromUtf8("btn_match"));
        btn_match->setGeometry(QRect(240, 60, 200, 50));
        btn_match->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_rank = new QPushButton(OnlineWidget);
        btn_rank->setObjectName(QString::fromUtf8("btn_rank"));
        btn_rank->setGeometry(QRect(520, 60, 200, 50));
        btn_rank->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_history = new QPushButton(OnlineWidget);
        btn_history->setObjectName(QString::fromUtf8("btn_history"));
        btn_history->setGeometry(QRect(240, 280, 200, 50));
        btn_history->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_logout = new QPushButton(OnlineWidget);
        btn_logout->setObjectName(QString::fromUtf8("btn_logout"));
        btn_logout->setGeometry(QRect(240, 480, 200, 50));
        btn_logout->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_change = new QPushButton(OnlineWidget);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));
        btn_change->setGeometry(QRect(240, 380, 200, 50));
        btn_change->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_exit = new QPushButton(OnlineWidget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setGeometry(QRect(530, 480, 200, 50));
        btn_exit->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_setting = new QPushButton(OnlineWidget);
        btn_setting->setObjectName(QString::fromUtf8("btn_setting"));
        btn_setting->setGeometry(QRect(520, 370, 200, 50));
        btn_setting->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_create = new QPushButton(OnlineWidget);
        btn_create->setObjectName(QString::fromUtf8("btn_create"));
        btn_create->setGeometry(QRect(240, 160, 200, 50));
        btn_create->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_join = new QPushButton(OnlineWidget);
        btn_join->setObjectName(QString::fromUtf8("btn_join"));
        btn_join->setGeometry(QRect(510, 160, 200, 50));
        btn_join->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        retranslateUi(OnlineWidget);

        QMetaObject::connectSlotsByName(OnlineWidget);
    } // setupUi

    void retranslateUi(QWidget *OnlineWidget)
    {
        OnlineWidget->setWindowTitle(QCoreApplication::translate("OnlineWidget", "Form", nullptr));
        btn_match->setText(QCoreApplication::translate("OnlineWidget", "Online Match", nullptr));
        btn_rank->setText(QCoreApplication::translate("OnlineWidget", "Rank", nullptr));
        btn_history->setText(QCoreApplication::translate("OnlineWidget", "History", nullptr));
        btn_logout->setText(QCoreApplication::translate("OnlineWidget", "Logout", nullptr));
        btn_change->setText(QCoreApplication::translate("OnlineWidget", "Change Password", nullptr));
        btn_exit->setText(QCoreApplication::translate("OnlineWidget", "Exit Game", nullptr));
        btn_setting->setText(QCoreApplication::translate("OnlineWidget", "Settings", nullptr));
        btn_create->setText(QCoreApplication::translate("OnlineWidget", "Create Room", nullptr));
        btn_join->setText(QCoreApplication::translate("OnlineWidget", "Join Room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnlineWidget: public Ui_OnlineWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINEWIDGET_H
