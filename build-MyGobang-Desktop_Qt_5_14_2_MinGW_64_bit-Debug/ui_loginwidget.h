/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QPushButton *btn_forget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_password;
    QCheckBox *checkBox_autoLogin;
    QPushButton *btn_return;
    QPushButton *btn_login;
    QPushButton *btn_register;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_userName;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_userName;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(1280, 720);
        btn_forget = new QPushButton(LoginWidget);
        btn_forget->setObjectName(QString::fromUtf8("btn_forget"));
        btn_forget->setGeometry(QRect(520, 380, 211, 61));
        btn_forget->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial\";"));
        layoutWidget = new QWidget(LoginWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 230, 771, 91));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_password = new QLabel(layoutWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        horizontalLayout_2->addWidget(label_password);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setStyleSheet(QString::fromUtf8("font: 87 10pt \"Arial\";"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_password);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 8);
        checkBox_autoLogin = new QCheckBox(LoginWidget);
        checkBox_autoLogin->setObjectName(QString::fromUtf8("checkBox_autoLogin"));
        checkBox_autoLogin->setGeometry(QRect(290, 370, 201, 71));
        checkBox_autoLogin->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_return = new QPushButton(LoginWidget);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));
        btn_return->setGeometry(QRect(170, 550, 171, 61));
        btn_return->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_login = new QPushButton(LoginWidget);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setGeometry(QRect(480, 550, 171, 61));
        btn_login->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_register = new QPushButton(LoginWidget);
        btn_register->setObjectName(QString::fromUtf8("btn_register"));
        btn_register->setGeometry(QRect(780, 550, 171, 61));
        btn_register->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        widget = new QWidget(LoginWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(120, 120, 771, 91));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_userName = new QLabel(widget);
        label_userName->setObjectName(QString::fromUtf8("label_userName"));
        label_userName->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        horizontalLayout->addWidget(label_userName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEdit_userName = new QLineEdit(widget);
        lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));
        lineEdit_userName->setStyleSheet(QString::fromUtf8("font: 87 10pt \"Arial\";"));

        horizontalLayout->addWidget(lineEdit_userName);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 8);

        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        btn_forget->setText(QCoreApplication::translate("LoginWidget", "Forget Password?", nullptr));
        label_password->setText(QCoreApplication::translate("LoginWidget", "Password:", nullptr));
        checkBox_autoLogin->setText(QCoreApplication::translate("LoginWidget", "Auto Login", nullptr));
        btn_return->setText(QCoreApplication::translate("LoginWidget", "RETURN", nullptr));
        btn_login->setText(QCoreApplication::translate("LoginWidget", "LOGIN", nullptr));
        btn_register->setText(QCoreApplication::translate("LoginWidget", "REGISTER", nullptr));
        label_userName->setText(QCoreApplication::translate("LoginWidget", "UserName/Email:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
